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
uniform_int_distribution<int> distribution(1, 1000000);

RedBlackTree<int> rbTree;

int main() {
    
    vector<int> treeData;

    srand(GetTickCount());

    int count = 0;
    clock_t start, end;
    double duration;

    start = clock();
    while(count < 400000){
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

    clock_t erasestart, eraseend, insertstart, insertend;
    double erasemultiruntime, insertmultiruntime;

    erasestart = clock();
    thread thread1([&](){
        mt19937 engine(GetTickCount());  
        uniform_int_distribution<int> deldistribution(1, 1000000);
        for(int i = 0; i < 50000; i++){
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
        uniform_int_distribution<int> deldistribution(1, 1000000);
        for(int i = 0; i < 50000; i++){
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
        uniform_int_distribution<int> deldistribution(1, 1000000);
        for(int i = 0; i < 50000; i++){
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
        uniform_int_distribution<int> deldistribution(1, 1000000);
        for(int i = 0; i < 50000; i++){
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
        mt19937 engine(GetTickCount());  
        uniform_int_distribution<int> insdistribution(1000001, 1250000);
        for (int i = 0; i < 50000; i++) {
            int key = insdistribution(engine);
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.insert(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread6([&](){
        mt19937 engine(GetTickCount());  
        uniform_int_distribution<int> insdistribution(1250001, 1500000);
        for (int i = 0; i < 50000; i++) {
            int key = insdistribution(engine);
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.insert(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread7([&](){
        mt19937 engine(GetTickCount());  
        uniform_int_distribution<int> insdistribution(1500001, 1750000);
        for (int i = 0; i < 50000; i++) {
            int key = insdistribution(engine);
            if (isUseMutex) mt.lock();
            else locker.Lock();

            rbTree.insert(key);

            if (isUseMutex) mt.unlock();
            else locker.Unlock();
        }
    });

    thread thread8([&](){
        mt19937 engine(GetTickCount());  
        uniform_int_distribution<int> insdistribution(1750001, 2000000);
        for (int i = 0; i < 50000; i++) {
            int key = insdistribution(engine);
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
