#include <iostream>
#include "Binary Tree.h"
#include <cstdlib>
#include <ctime>
#include <thread>
#include <time.h>
#include <mutex>
#include <vector>
#include <random>
#include <functional>

using namespace std;
/*
뮤텍스 추가 생성
*/
mutex mtx;
// arry->vec
// voidInsertValueTest.cpp

// voidserchValuesTest.cpp

//

int main()
{
    BST obj;
    int option, val;
    // arr->vec
    vector<int> arr;
    // int arr[2000];

    mt19937 engine((unsigned int)time(NULL));
    uniform_int_distribution<int> distribution(1, 1000000);
    //  cout << "from clock_gettime" << tp << endl;
    int count = 0;
    clock_t makestart, makeend;
    double maketime;
    while (count < 400000)
    {
        int tmp = distribution(engine);
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
    } // 벡터 어레이 생성
    // 이진트리 만들기
    int insertcount = 0; // 어레이 값 트리에 넣어주기
    makestart = clock();
    while (insertcount < 400000)
    {
        TreeNode *new_node = new TreeNode();
        new_node->value = arr[insertcount]; // 새 노드에 어레이 값 넣기
        // 재귀해서 루트노드 정하기
        obj.root = obj.insertRecursive(obj.root, new_node); //
        insertcount++;
    }
    makeend = clock();

    maketime = (double)(makeend - makestart) / CLOCKS_PER_SEC;

    cout << "Binary Tree:" << endl;
    obj.print2D(obj.root, 3);

    // 탐색
    int searchcnt = 0;

    clock_t searchstart, searchend;

    double mintime, maxtime;
    double searchduration;
    double totaltime = 0;
    double meantime = 0;

    cout << "---------------Search Start------------------" << endl;
    // 100번 탐색
    while (searchcnt < 100000)
    {
        uniform_int_distribution<int> searchdistribution(0, 399999);
        int searchidx = searchdistribution(engine);
        int searchnum = distribution(engine);

        TreeNode *new_node = new TreeNode();

        // 탐색시작

        searchstart = clock();
        new_node = obj.recursiveSearch(obj.root, searchnum); // 살짝 이해안됨
        if (new_node != NULL)
        {
            cout << "Value found" << endl;
        }
        else
        {
            cout << "Value NOT found" << endl;
        }
        searchend = clock();

        // 탐색 끝
        searchduration = (double)(searchend - searchstart) /
                         CLOCKS_PER_SEC; // 걸린 시간

        if (searchcnt == 0)
        {
            mintime = searchduration;
            maxtime = searchduration;
        }

        else
        {
            if (mintime > searchduration)
            {
                mintime = searchduration;
            }
            else if (maxtime < searchduration)
            {
                maxtime = searchduration;
            }
        }

        totaltime += searchduration;

        searchcnt++;
    }
    // 100번 탐색 종료

    meantime = totaltime / (searchcnt + 1);

    cout << "---------------Search End------------------" << endl;

    // 싱글스레드 실행
    // 삽입 . 삭제 50000번

    clock_t delstart, delend, insertstart, insertend;
    int delcnt = 0;
    int insertcnt = 0;
    double deltime;
    double inserttime;

    cout << "---------------Single Thread Start------------------" << endl;

    delstart = clock();
    while (delcnt < 200000)
    {
        uniform_int_distribution<int> deldistribution(1, 1000000);
        int i = deldistribution(engine);
        // cout << "           | delete randomnum : " << i << "           \n"<< endl;
        TreeNode *new_node = new_node;
        new_node = obj.iterativeSearch(i);
        if (new_node != NULL)
        {
            obj.deleteNode(obj.root, i);
            cout << "Delete Success!" << endl;
        }
        delcnt++;
    }
    delend = clock();
    deltime = (double)(delend - delstart) / CLOCKS_PER_SEC;

    insertstart = clock();
    while (insertcnt < 200000)
    {
        uniform_int_distribution<int> insdistribution(1000001, 2000000);
        int k = insdistribution(engine);
        // cout << "           | insert ramdomnum : " << i << "           \n"
        //      << endl;
        TreeNode *new_node1 = new TreeNode();
        new_node1->value = k;
        obj.insertRecursive(obj.root, new_node1);

        insertcnt++;
    }
    insertend = clock();
    inserttime = (double)(insertend - insertstart) / CLOCKS_PER_SEC;

    // insertduration = (double)(insertend - insertstart) / CLOCKS_PER_SEC;   // 걸린 시간
    // deleteduration = (double)(insertend - insertstart) / CLOCKS_PER_SEC;   // 걸린 시간

    cout << "Making Time : " << fixed << maketime << "\n";
    cout << "search Total Time = " << searchduration << endl;
    cout << "minimum time of SingleThread : " << mintime << "초\n";
    cout << "maximum time of SingleThread : " << maxtime << "초\n";
    cout << "total time of SingleThread : " << totaltime << "초\n";
    cout << "average time of SingleThread : " << meantime << "초\n";

    cout << "delete Time : " << deltime << "초\n";
    cout << "insert time : " << inserttime << "초\n";
    cout << "---------------Single Thread End------------------" << endl;
    return 0;
}

/*
thread2.join();
thread3.join();
thread4.join();

thread thread5([&obj]() // 숫자 변경
               {
                       for (int j = 0; j < 2000; j++)
                       {
                           int i = rand() % 1250 + 8751;
                           TreeNode *new_node1 = new TreeNode();
                           new_node1->value = i;
                           unique_lock<mutex> lock(mtx);
                           obj.insertRecursive(obj.root, new_node1);
                           cout << "thread 5 working " << '\n'; // 숫자 변경
                       } });

thread thread6([&obj]() // 숫자 변경
               {
                        for(int j=0;j<500;j++){
                        int i = rand() % 1250 + 6251;
                            TreeNode *new_node2 = new TreeNode();
                            new_node2->value = i;
                            unique_lock<mutex> lock(mtx);
                            obj.insertRecursive(obj.root, new_node2);
                            cout << "thread 6 working " << '\n'; // 숫자 변경

                        } });

thread thread7([&obj]() // 숫자 변경
               {
                        for(int j=0;j<500;j++){
                        int i = rand() % 1250 + 7501;
                            TreeNode *new_node3 = new TreeNode();
                            new_node3->value = i;

                            unique_lock<mutex> lock(mtx);
                            obj.insertRecursive(obj.root, new_node3);
                            cout << "thread 7 working " << '\n'; // 숫자 변경

                        } });

thread thread8([&obj]() // 숫자 변경
               {
                        for(int j=0;j<500;j++){
                        int i = rand() % 5000 + 8751;
                            TreeNode *new_node4 = new TreeNode();
                            new_node4->value = i;

                            unique_lock<mutex> lock(mtx);
                            obj.insertRecursive(obj.root, new_node4);
                            cout << "thread 8 working " << '\n'; // 숫자 변경

                        } });

thread5.join();
thread6.join();
thread7.join();
thread8.join();


*/
