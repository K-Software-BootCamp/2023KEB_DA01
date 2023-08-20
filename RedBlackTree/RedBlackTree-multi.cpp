#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <atomic>
#include <mutex>
#include <thread>
#include <vector>
#include "RBTree.hpp"
#include "SpinLock.hpp"

using namespace std;

mutex mt;
Spinlock locker;

bool isUseMutex;

RedBlackTree<int> rbTree;

int main() {
    
    vector<int> treeData;

    srand(GetTickCount());

    int count = 0;
    clock_t start, end;
    double duration;

    start = clock();
    while(count < 2000){
        int tmp = rand() % 5000 + 1;
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


    while(searchcnt < 100){
        int searchidx = rand() % 2000;
        int searchnum = rand() % 5000+1;

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
        for(int i = 0; i < 500; i++){
            int key = rand() % 5000 +1;
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.erase(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread2([&](){
        for(int i = 0; i < 500; i++){
            int key = rand() % 5000 +1;
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.erase(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread3([&](){
        for(int i = 0; i < 500; i++){
            int key = rand() % 5000 +1;
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.erase(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread4([&](){
        for(int i = 0; i < 500; i++){
            int key = rand() % 5000 +1;
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
        for (int i = 0; i < 500; i++) {
            int key = rand()%1250 + 5001;
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.insert(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread6([&](){
        for (int i = 0; i < 500; i++) {
            int key = rand()%1250 + 6251;
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.insert(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread7([&](){
        for (int i = 0; i < 500; i++) {
            int key = rand()%1250 + 7501;
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.insert(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread8([&](){
        for (int i = 0; i < 500; i++) {
            int key = rand()%1250 + 8751;
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
