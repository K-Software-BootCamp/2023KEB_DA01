#include <iostream>
#include <random>
#include <cstdlib>
#include <vector>
#include "Linked_List.hpp"

using namespace std;

int main(void) {
    DoublyLinkedList<int> dll; // list 만들고 이름 지정

    clock_t makestart, makeend;
    double makeduration;

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

    // dll.displayList();

    //시작과 끝 시간을 이용한 list의 insert 시간 계산
    makeduration = (double)(makeend - makestart) / CLOCKS_PER_SEC;

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

    dll.displayList();

    cout << "Linked List Making Time : " << fixed << makeduration << "초\n";
    cout << "Linked List Minimum Time of Search : " << mintime << "초\n";
    cout << "Linked List Maximum Time of Search : " << maxtime << "초\n";
    cout << "Linked List Total Time of Search : " << totaltime << "초\n";
    cout << "Linked List Average Time of Search : " << meantime << "초\n";

    cout << "Linked List (Single-Thread) Delete TotalTime : " << delduration << "초\n";
    cout << "Linked List (Single-Thread) Insert Total Time : " << insduration << "초\n";

    return 0;
}


