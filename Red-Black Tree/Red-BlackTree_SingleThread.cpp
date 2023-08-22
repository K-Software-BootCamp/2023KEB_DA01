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
uniform_int_distribution<int> distribution(1, 1000000);

RedBlackTree<int> rbTree;

int main() {
    
    vector<int> treeData;

    int count = 0;
    clock_t makestart, makeend;
    double makeduration;

    while(count < 400000){
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
            count++;
        }
    }
    makestart = clock();
    for(int i = 0; i < treeData.size();i++){
        rbTree.insert(treeData[i]);
    }
    makeend = clock();

    makeduration = (double)(makeend - makestart) / CLOCKS_PER_SEC;

    int searchcnt = 0;

    clock_t searchstart, searchend;
    double searchduration;
    double mintime, maxtime;
    double totaltime = 0;
    double meantime = 0;

    while(searchcnt < 100000){
        uniform_int_distribution<int> searchdistribution(0, 399999);
        int searchidx = searchdistribution(engine);
        int searchnum = distribution(engine);

        searchstart = clock();
        rbTree.search(searchnum); // 배열 index로 할꺼면 searchnum 대신에 treeData[searchidx]
        searchend = clock();

        searchduration = (double)(searchend - searchstart) / CLOCKS_PER_SEC;

        if(searchcnt == 0){
            mintime = searchduration;
            maxtime = searchduration;
        }

        else{
            if(mintime > searchduration){
                mintime = searchduration;
            }
            else if(maxtime < searchduration){
                maxtime = searchduration;
            }
        }

        totaltime += searchduration;

        searchcnt++;
    }

    meantime = totaltime / (searchcnt+1);

    // Single Thread Process
    clock_t delstart, delend, insstart, insend;
    int delrun = 0;
    int insertrun = 0;
    double delduration;
    double insduration;

    delstart = clock();
    while (delrun<200000){

        int deltmp = distribution(engine);

        rbTree.erase(deltmp);

        delrun++;
    }
    delend = clock();

    delduration = (double)(delend-delstart)/CLOCKS_PER_SEC;

    insstart = clock();    
    while (insertrun<200000){
        uniform_int_distribution<int> insertdistribution(1000001, 2000000);
        int instmp = insertdistribution(engine);

        rbTree.insert(instmp);

        insertrun++;
    }
    insend = clock();
    insduration = (double)(insend - insstart)/CLOCKS_PER_SEC;

    cout << "Red-Black Tree:" << endl;
    // rbTree.printTree(rbTree.getRoot());

    cout << "Red-Black Tree Making Time : " << fixed << makeduration << "초\n";
    cout << "Red-Black Tree Minimum Time of Search : " << mintime << "초\n";
    cout << "Red-Black Tree Maximum Time of Search : " << maxtime << "초\n";
    cout << "Red-Black Tree Total Time of Search : " << totaltime << "초\n";
    cout << "Red-Black Tree Average Time of Search : " << meantime << "초\n";

    cout << "Red-Black Tree (Single-Thread) Delete TotalTime : " << delduration << "초\n";
    cout << "Red-Black Tree (Single-Thread) Insert Total Time : " << insduration << "초\n";

    return 0;
}
