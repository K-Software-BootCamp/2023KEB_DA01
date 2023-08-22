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

mt19937 engine((unsigned int)time(NULL));
// MT19937 난수 엔진
uniform_int_distribution<int> distribution(1, 1000000);

using namespace std;
/*
뮤텍스 추가 생성
*/
mutex mtx;
// arry->vec
// voidInsertValueTest.cpp

// voidserchValuesTest.cpp

//

int main(){
    BST obj;
    int option, val;
    // arr->vec
    vector<int> arr;
    // int arr[2000];

    srand((unsigned int)time(NULL));
    //  cout << "from clock_gettime" << tp << endl;
    int count = 0;
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
    while (insertcount < 400000)
    {
        TreeNode *new_node = new TreeNode();
        new_node->value = arr[insertcount]; // 새 노드에 어레이 값 넣기
        // 재귀해서 루트노드 정하기
        obj.root = obj.insertRecursive(obj.root, new_node); //
        insertcount++;
    }

    // delete 멀티스레드 실행부분

    clock_t deletestart, deleteend;
    double deleteduration;
    long double deletemintime, deletemaxtime;
    long double deletetotaltime = 0;
    long double deletemeantime = 0;

    //cout << "----------- Binary Tree delete Start -----------" << endl;

    deletestart = clock();
    thread thread1([&obj]()
                    {
                        mt19937 engine((unsigned int)time(NULL));
                        uniform_int_distribution<int> deldistribution(1, 1000000);
                        
                        for (int j = 0; j < 50000; j++){
                            int i = deldistribution(engine);
                            unique_lock<mutex> lock(mtx);
                            TreeNode *new_node = new_node;
                            new_node = obj.iterativeSearch(i);
                            if(new_node != NULL){  
                                
                                obj.deleteNode(obj.root, i);
                                //cout << "delete" << endl;
                            }
                        } 
                    });

    thread thread2([&obj]()
                    {
                        mt19937 engine((unsigned int)time(NULL));
                        uniform_int_distribution<int> deldistribution(1, 1000000);
                        
                        for (int j = 0; j < 50000; j++){
                            int i = deldistribution(engine);
                            unique_lock<mutex> lock(mtx);
                            TreeNode *new_node = new_node;
                            new_node = obj.iterativeSearch(i);
                            if(new_node != NULL){
                                
                                obj.deleteNode(obj.root, i);
                                //cout << "delete" << endl;
                                
                            }
                        } 
                    });

    thread thread3([&obj]()
                    {
                        mt19937 engine((unsigned int)time(NULL));
                        uniform_int_distribution<int> deldistribution(1, 1000000);
                        
                        for (int j = 0; j < 50000; j++){
                            int i = deldistribution(engine);
                            
                            unique_lock<mutex> lock(mtx);
                            TreeNode *new_node = new_node;
                            new_node = obj.iterativeSearch(i);
                            if(new_node != NULL){
                                obj.deleteNode(obj.root, i);
                                //cout << "delete" << endl;
                            }
                        } 
                    });

    thread thread4([&obj]()
                    {
                        mt19937 engine((unsigned int)time(NULL));
                        uniform_int_distribution<int> deldistribution(1, 1000000);
                        
                        for (int j = 0; j < 50000; j++){
                            int i = deldistribution(engine);
                            unique_lock<mutex> lock(mtx);
                            TreeNode *new_node = new_node;
                            new_node = obj.iterativeSearch(i);
                            if(new_node != NULL){
                                
                                obj.deleteNode(obj.root, i);
                                //cout << "delete" << endl;
                            }
                        } 
                    });

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    deleteend = clock();
    //cout << "----------- Binary Tree delete End -----------\n" << endl;

    // delete 시간 계산
    deleteduration = (long double)(deleteend - deletestart) / CLOCKS_PER_SEC; // 걸린 시간

    /*
        int threadcnt = 0;
        long double threadmintime, threadmaxtime;
        long double threadtotaltime = 0;
        long double threadmeantime = 0;
        while (threadcnt < 2000)
        {
            start = clock();

            if (threadcnt == 0)
            {
                threadmintime = duration;
                threadmaxtime = duration;
            }

            else
            {
                if (threadmintime > duration)
                {
                    threadmintime = duration;
                }
                else if (threadmaxtime < duration)
                {
                    threadmaxtime = duration;
                }
            }

            totaltime += duration;
        }

        // 100번 탐색 종료
        meantime = totaltime / (searchcnt + 1);

        cout << "minimum time of search : " << fixed << mintime << "초\n";
        cout << "maximum time of search : " << maxtime << "초\n";
        cout << "total time of search : " << totaltime << "초\n";
        cout << "average time of search : " << meantime << "초\n";
        */

    // insert 멀티스레드 실행 부분
    clock_t insertstart, insertend;
    double insertduration;

    insertstart = clock();
    thread thread5([&obj]()
                    {
                        mt19937 engine((unsigned int)time(NULL));
                        uniform_int_distribution<int> insdistribution(1000001, 1250000);
                        for (int j = 0; j < 50000; j++)
                        {
                            int i = insdistribution(engine);
                            unique_lock<mutex> lock(mtx);

                            TreeNode *new_node1 = new TreeNode();
                            new_node1->value = i;
                            obj.insertRecursive(obj.root, new_node1);
                            // cout << "thread 5 working " << '\n'; // 숫자 변경
                        } });

    thread thread6([&obj]()
                    {
                        mt19937 engine((unsigned int)time(NULL));
                        uniform_int_distribution<int> insdistribution(1250001, 1500000);
                        for (int j = 0; j < 50000; j++)
                        {
                            int i = insdistribution(engine);
                            unique_lock<mutex> lock(mtx);
                    
                            TreeNode *new_node2 = new TreeNode();
                            new_node2->value = i;
                            obj.insertRecursive(obj.root, new_node2);
                            // cout << "thread 6 working " << '\n'; // 숫자 변경

                        } });

    thread thread7([&obj]()
                    {
                        mt19937 engine((unsigned int)time(NULL));
                        uniform_int_distribution<int> insdistribution(1500001, 1750000);
                        for (int j = 0; j < 50000; j++)
                        {
                            int i = insdistribution(engine);
                            unique_lock<mutex> lock(mtx);
                            TreeNode *new_node3 = new TreeNode();
                            new_node3->value = i;
                            obj.insertRecursive(obj.root, new_node3);
                            // cout << "thread 7 working " << '\n'; // 숫자 변경
                        
                        } });

    thread thread8([&obj]()
                    {
                        mt19937 engine((unsigned int)time(NULL));
                        uniform_int_distribution<int> insdistribution(1750001, 2000000);
                        for (int j = 0; j < 50000; j++)
                        {
                            int i = insdistribution(engine);
                            unique_lock<mutex> lock(mtx);
                            TreeNode *new_node4 = new TreeNode();
                            new_node4->value = i;
                            obj.insertRecursive(obj.root, new_node4);
                            // cout << "thread 8 working " << '\n'; // 숫자 변경
                        
                        } });

    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();

    insertend = clock();
    // insert 멀티스레드 시간 계산
    insertduration = (long double)(insertend - insertstart) / CLOCKS_PER_SEC; // 걸린 시간

    cout << "Binary Tree (Multi-Thread) Delete Total Time : " << deleteduration << "초" << endl;

    cout << "Binary Tree (Multi-Thread) Insert Total Time : " << insertduration << "초" << endl;

    // cout << "------------------------------------------------------------------" << endl;
    return 0;
}