#include <iostream>
#include <random>
#include <cstdlib>
#include <vector>
#include "230821_list_final.hpp"

using namespace std;

int main(void) {
    DoublyLinkedList<int> dll; // list 만들고 이름 지정

    clock_t makestart, makeend;
    double duration;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000);


    vector<int> reference;

    int i = 0;

    while (i != 400000)
    {
        int randomValue = dis(gen);
        if (i == 0)
        {
            reference.push_back(randomValue);
            i += 1;
        }
        else
        {
            bool good = true;
            for (int j = 0; j < reference.size(); j++)
            {
                if (randomValue == reference[j])
                {
                    good = false;
                    break;
                }
            }

            if (good)
            {
                reference.push_back(randomValue);
                i += 1;
            }
        }

    }

    makestart = clock();
    for(int k = 0; k < reference.size(); k++){
        dll.insertNode(reference[k]);
    }
    makeend = clock();

    for (int i = 0; i < reference.size(); i++) {
        if(i == reference.size()-1){
            cout << reference[i];
        }
        else{
            cout << reference[i] << "->";
        }        
    }

    //시작과 끝 시간을 이용한 list의 insert 시간 계산
    duration = (double)(makeend - makestart) / CLOCKS_PER_SEC;

    int searchcnt = 0;

    clock_t searchstart, searchend;
    double searchduration;

    double mintime, maxtime;
    double totaltime = 0;
    double meantime = 0;


    while (searchcnt < 100000) {
        int searchnum = dis(gen);

        searchstart = clock();
        dll.search(searchnum); // 
        searchend = clock();

        searchduration = (double)(searchend - searchstart) / CLOCKS_PER_SEC;

        if (searchcnt == 0) {
            mintime = searchduration;
            maxtime = searchduration;
        }

        else {
            if (mintime > searchduration) {
                mintime = searchduration;
            }
            else if (maxtime < searchduration) {
                maxtime = searchduration;
            }
        }

        totaltime += searchduration;

        searchcnt++;
    }

    meantime = totaltime / (searchcnt + 1);

    clock_t delstart, delend;
    double delduration;
    delstart = clock();
   
    int delcount = 0;

    while (delcount < 200000) {
        int tmp = dis(gen);

        dll.deleteNode(tmp);

        delcount++;
    }

    delend = clock();
    delduration = (double)(delend - delstart) / CLOCKS_PER_SEC;

    cout << "delete 진행 완료\n";

    clock_t insstart, insend;
    double insduration;
 
    uniform_int_distribution<> dis2(1000001, 2000000);
    
    int inscount = 0;

    insstart = clock();
    while (inscount < 200000) {
        int tmp = dis2(gen);

        dll.insertNode(tmp);

        inscount++;
    }

    insend = clock();
    //시작과 끝 시간을 이용한 list의 insert 시간 계산
    insduration = (double)(insend - insstart) / CLOCKS_PER_SEC;
    cout << "추가 insert 진행 완료 \n\n\n";

    dll.displayList();

    cout << "minimum time of search : " << fixed << mintime << "초\n";
    cout << "maximum time of search : " << maxtime << "초\n";
    cout << "total time of search : " << totaltime << "초\n";
    
    cout << "Time of single generation list : " << fixed << duration << "초\n";
    cout << "Time of single delete list : " << delduration << "초\n";
    cout << "Time of additional insert list : " << insduration << "초\n";

    return 0;
}


