#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <atomic>
#include <mutex>
#include <thread>
#include <vector>
#include <random>
#include <functional>
#include "RBTree.hpp"
#include "SpinLock.hpp"

using namespace std;

mutex mt;
Spinlock locker;

bool isUseMutex;

mt19937 engine(GetTickCount());                    // MT19937 난수 엔진
uniform_int_distribution<int> distribution(1, 90000);

RedBlackTree<int> rbTree;

int main() {
    
    vector<int> treeData;

    srand(GetTickCount());

    int count = 0;
    clock_t start, end;
    double duration;

    start = clock();
    while(count < 50000){
        int tmp = distribution(engine);
        // int tmp = (int)(((double)((rand()<<15) | rand())) / (((RAND_MAX<<15) | RAND_MAX) + 1) * (90000))+1;
        int isSame = 0;
        for (int i = 0; i < treeData.size(); i++){
            if(tmp == treeData[i]){
                isSame = 1;
                break;
            }
        }
        
        if(isSame == 0){
            treeData.push_back(tmp);
            rbTree.insert(treeData[count]);
            count++;
        }
    }
    end = clock();

    duration = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "Red-Black Tree:" << endl;
    rbTree.printTree(rbTree.getRoot());
    cout << "Time of generation tree : " << duration << "초\n";

    int searchcnt = 0;


    double mintime, maxtime;
    double totaltime = 0;
    double meantime = 0;


    while(searchcnt < 30000){
        uniform_int_distribution<int> searchdistribution(0, 49999);
        int searchidx = searchdistribution(engine);
        int searchnum = distribution(engine);

        start = clock();
        rbTree.search(searchnum); // 배열 index로 할꺼면 searchnum 대신에 treeData[searchidx]
        end = clock();

        duration = (double)(end - start) / CLOCKS_PER_SEC;

        if(searchcnt == 0){
            mintime = duration;
            maxtime = duration;
        }

        else{
            if(mintime > duration){
                mintime = duration;
            }
            else if(maxtime < duration){
                maxtime = duration;
            }
        }

        totaltime += duration;

        searchcnt++;
    }

    meantime = totaltime / (searchcnt+1);

    cout << "minimum time of search : " <<fixed<< mintime << "초\n";
    cout << "maximum time of search : " << maxtime << "초\n";
    cout << "total time of search : " << totaltime << "초\n";
    cout << "average time of search : " << meantime << "초\n";

    // Single Thread Process
    clock_t erasestart, eraseend, insertstart, insertend;
    double erasemultiruntime, insertmultiruntime;

    erasestart = clock();
    thread thread1([&](){
        mt19937 engine(GetTickCount());  
        uniform_int_distribution<int> deldistribution(1, 90000);
        for(int i = 0; i < 25000; i++){
            int key = deldistribution(engine);
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.erase(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread2([&](){
        mt19937 engine(GetTickCount());  
        uniform_int_distribution<int> deldistribution(1, 90000);
        for(int i = 0; i < 25000; i++){
            int key = deldistribution(engine);
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.erase(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread3([&](){
        mt19937 engine(GetTickCount());  
        uniform_int_distribution<int> deldistribution(1, 90000);
        for(int i = 0; i < 25000; i++){
            int key = deldistribution(engine);
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.erase(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread4([&](){
        mt19937 engine(GetTickCount());  
        uniform_int_distribution<int> deldistribution(1, 90000);
        for(int i = 0; i < 25000; i++){
            int key = deldistribution(engine);
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.erase(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    eraseend = clock();

    erasemultiruntime = (double)(eraseend - erasestart) / CLOCKS_PER_SEC;

    insertstart = clock();
    thread thread5([&](){
        for (int i = 0; i < 20000; i++) {
            int key = (int)(((double)((rand()<<15) | rand())) / (((RAND_MAX<<15) | RAND_MAX) + 1) * (25000)) + 100001;
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.insert(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread6([&](){
        for (int i = 0; i < 20000; i++) {
            int key = (int)(((double)((rand()<<15) | rand())) / (((RAND_MAX<<15) | RAND_MAX) + 1) * (25000)) + 125001;
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.insert(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread7([&](){
        for (int i = 0; i < 20000; i++) {
            int key = (int)(((double)((rand()<<15) | rand())) / (((RAND_MAX<<15) | RAND_MAX) + 1) * (25000)) + 150001;
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.insert(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread8([&](){
        for (int i = 0; i < 20000; i++) {
            int key = (int)(((double)((rand()<<15) | rand())) / (((RAND_MAX<<15) | RAND_MAX) + 1) * (25000)) + 175001;
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.insert(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();
    insertend = clock();

    insertmultiruntime = (double)(insertend - insertstart)/CLOCKS_PER_SEC;

    cout << fixed << erasemultiruntime << '\n';
    cout << insertmultiruntime << '\n';
    
    return 0;
}
