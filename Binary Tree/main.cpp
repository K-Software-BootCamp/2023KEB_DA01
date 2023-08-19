#include <iostream>
#include "Binary Tree.h"
#include <cstdlib>
#include <ctime>
#include <thread>
#include <time.h>
#include <mutex>
using namespace std;

mutex mtx;
// arry->vec

int main()
{
    BST obj;
    int option, val;
    // arr->vec
    vector<int> arr;
    // int arr[2000];

    srand((unsigned int)time(NULL));
    //  cout << "from clock_gettime" << tp << endl;
    int count = 0;
    clock_t start, end;
    double duration;

    start = clock();
    while (count < 2000)
    {
        int tmp = rand() % 5000 + 1;
        int isSame = 0;

        for (int i = 0; i < arr.size(); i++) // vector 변경지점
        {
            if (tmp == arr[i]) // 삽입 값 중복확인
            {
                isSame = 1;
                break;
            }
        }
        if (isSame == 0)
        {
            arr.push_back(tmp); // vector 변경지점
            count++;
        }
    }
    int insertcount = 0; // 어레이 값 트리에 넣어주기
    while (insertcount < 2000)
    {
        TreeNode *new_node = new TreeNode();
        new_node->value = arr[insertcount];
        obj.root = obj.insertRecursive(obj.root, new_node);
        insertcount++;
    }

    cout << "Binary Tree:" << endl;
    obj.print2D(obj.root, 3);

    int searchcnt = 0;

    long double mintime, maxtime;
    long double totaltime = 0;
    long double meantime = 0;

    while (searchcnt < 100)
    {
        TreeNode *new_node = new TreeNode();
        int searchidx = rand() % 2000;
        int searchnum = rand() % 5000 + 1;

        start = clock();
        new_node = obj.recursiveSearch(obj.root, searchnum);
        if (new_node != NULL)
        {
            cout << "Value found" << endl;
        }
        else
        {
            cout << "Value NOT found" << endl;
        }
        end = clock();

        duration = (long double)(end - start) / CLOCKS_PER_SEC;

        if (searchcnt == 0)
        {
            mintime = duration;
            maxtime = duration;
        }

        else
        {
            if (mintime > duration)
            {
                mintime = duration;
            }
            else if (maxtime < duration)
            {
                maxtime = duration;
            }
        }

        totaltime += duration;

        searchcnt++;
    }

    meantime = totaltime / (searchcnt + 1);

    cout << "minimum time of search : " << fixed << mintime << "초\n";
    cout << "maximum time of search : " << maxtime << "초\n";
    cout << "total time of search : " << totaltime << "초\n";
    cout << "average time of search : " << meantime << "초\n";

    thread thread1([&obj]()
                   {
        for (int i = 500; i < 1000; i++) {
            TreeNode *new_node = obj.iterativeSearch(i);
            if (new_node != NULL) {
                unique_lock<mutex> lock(mtx);
                obj.deleteNode(obj.root, i);
            }
        } });
    cout << "thread 1: " << '\n';

    thread1.join();

    /*
    thread thread2([&obj]()
                   {
                           for (int i = 1000; i < 1500; i++)
                           {
                               insertValues(obj.root, i);
                               cout << "thread 2: " << '\n';
                           } });

    thread thread2([&obj]()
                   {
                           for (int i = 1500; i < 2000; i++)
                           {
                               deleteValues(obj.root, i);
                               cout << "thread 3: " << '\n';
                           } });
    thread thread2([&obj]()
                   {
                           for (int i = 2000; i < 2500; i++)
                           {
                               deleteValues(obj.root, i);
                               cout << "thread 3: " << '\n';
                           } });

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    cout << "Binary Tree: " << end;
    obj.print2D(obj.root, 3);

    return 0;
    */
}