#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <functional>
#include "RBTree.hpp"

using namespace std;

int threadcount;

mt19937 engine(GetTickCount());                    // MT19937 난수 엔진
uniform_int_distribution<int> distribution(1, 90000);

RedBlackTree<int> rbTree;

int main() {
    
    vector<int> treeData;

    int count = 0;
    clock_t start, end;
    double duration;

    start = clock();
    while(count < 50000){
        int tmp = distribution(engine);
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


    while(searchcnt < 20000){
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
    clock_t start1, end1;
    int singlethreadrun = 0;
    double singleruntime;
    start1 = clock();
    while (singlethreadrun<30000){
        int deltmp = distribution(engine);
        int instmp = distribution(engine)+100000;

        rbTree.erase(deltmp);
        rbTree.insert(instmp);

        singlethreadrun++;
    }
    end1 = clock();

    singleruntime = (double)(end1-start1)/CLOCKS_PER_SEC;

    cout << fixed << singleruntime;    

    return 0;
}
