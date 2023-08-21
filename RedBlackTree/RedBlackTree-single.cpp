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
    clock_t start, end;
    double duration;

    start = clock();
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
            rbTree.insert(treeData[count]);
            count++;
        }
    }
    end = clock();

    duration = (double)(end - start) / CLOCKS_PER_SEC;

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
    double delruntime = 0;
    double insertruntime = 0;

    while (delrun<200000){

        int deltmp = distribution(engine);
        delstart = clock();

        rbTree.erase(deltmp);

        delend = clock();

        delruntime += (double)(delend-delstart)/CLOCKS_PER_SEC;

        delrun++;
    }
    delend = clock();

    
    while (insertrun<200000){
        uniform_int_distribution<int> insertdistribution(1000001, 2000000);
        int instmp = insertdistribution(engine);
        insstart = clock();
        rbTree.insert(instmp);
        insend = clock();

        insertruntime += (double)(insend-insstart)/CLOCKS_PER_SEC;

        insertrun++;
    }



    cout << "Red-Black Tree:" << endl;
    rbTree.printTree(rbTree.getRoot());
    cout << "Time of generation tree : " << duration << "초\n";

    cout << "minimum time of search : " <<fixed<< mintime << "초\n";
    cout << "maximum time of search : " << maxtime << "초\n";
    cout << "total time of search : " << totaltime << "초\n";
    cout << "average time of search : " << meantime << "초\n";

    cout << delruntime << "초\n";    
    cout << insertruntime<< "초";

    return 0;
}
