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

#define ITER_TIME 10000000
#define THREAD_COUNT 1
#define TRY_TIME 100

using namespace std;

mutex mt;
Spinlock locker;

bool isUseMutex;
int threadcount;

RedBlackTree<int> rbTree;

void insertInSafely(int key) {
    for (int i = 0; i < ITER_TIME; ++i) {
        if (isUseMutex) mt.lock();
        else locker.Lock();

        rbTree.insert(key);

        if (isUseMutex) mt.unlock();
        else locker.Unlock();
    }
}

void eraseInSafely(int key) {
    for (int i = 0; i < ITER_TIME; ++i) {
        if (isUseMutex) mt.lock();
        else locker.Lock();

        rbTree.erase(key);

        if (isUseMutex) mt.unlock();
        else locker.Unlock();
    }

}

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
    clock_t start1, end1;
    int singlethreadrun = 0;
    double singleruntime;
    start1 = clock();
    while (singlethreadrun<1000){
        int deltmp = rand()%5000 + 1;
        int instmp = rand()%5000 + 5001;

        rbTree.erase(deltmp);
        rbTree.insert(instmp);
        treeData.erase(remove_if(treeData.begin(), treeData.end(), [&](auto x) -> bool { return x  == deltmp; }), treeData.end());
        treeData.push_back(instmp); 

        singlethreadrun++;
    }
    end1 = clock();

    singleruntime = (double)(end1-start1)/CLOCKS_PER_SEC;

    cout << fixed << singleruntime;    

    return 0;
}
