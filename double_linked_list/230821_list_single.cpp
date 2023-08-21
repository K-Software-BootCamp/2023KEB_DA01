#include <iostream>
#include <random>
#include <cstdlib>
#include <vector>
#include "230821_list_final.hpp"


using namespace std;



int main(void) {
    DoublyLinkedList<int> dll; // list 만들고 이름 지정

    clock_t start, end;
    double duration;
    start = clock();


    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100000);


    vector<int> reference;

    int i = 0;

    while (i != 40000)
    {

        int randomValue = dis(gen);
        if (i == 0)
        {
            reference.push_back(randomValue);
            dll.insertNode(randomValue);
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
                dll.insertNode(randomValue);
                i += 1;
            }
        }

    }

   

    

    end = clock();

    for (int i = 0; i < reference.size(); i++) {
        cout << reference[i] << "->";
    }

    cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
    //시작과 끝 시간을 이용한 list의 insert 시간 계산
    duration = (double)(end - start) / CLOCKS_PER_SEC;
  





    int searchcnt = 0;

    clock_t start1, end1;
    double duration1;

    double mintime, maxtime;
    double totaltime = 0;
    double meantime = 0;


    while (searchcnt < 10000) {
        int searchnum = dis(gen);

        start1 = clock();
        dll.search(searchnum); // 
        end1 = clock();

        duration1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

        if (searchcnt == 0) {
            mintime = duration1;
            maxtime = duration1;
        }

        else {
            if (mintime > duration1) {
                mintime = duration1;
            }
            else if (maxtime < duration1) {
                maxtime = duration1;
            }
        }

        totaltime += duration1;

        searchcnt++;
    }

    meantime = totaltime / (searchcnt + 1);







    clock_t start2, end2;
    double duration2;
    start2 = clock();


   
   
    int count1 = 0;

    while (count1 < 20000) {
        int tmp = dis(gen);

        dll.deleteNode(tmp);

        count1++;
    }

    end2 = clock();
    duration2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

    cout << "delete 진행 완료\n";




    clock_t start3, end3;
    double duration3;
    start3 = clock();



 
    uniform_int_distribution<> dis2(100001, 200000);
 
    
    int count2 = 0;

    while (count2 < 20000) {
        int tmp = dis2(gen);

        dll.deleteNode(tmp);

        count2++;
    }


  


    end3 = clock();
    //시작과 끝 시간을 이용한 list의 insert 시간 계산
    duration3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    cout << "추가 insert 진행 완료 \n\n\n";

    dll.displayList();

    cout << "minimum time of search : " << fixed << mintime << "초\n";
    cout << "maximum time of search : " << maxtime << "초\n";
    cout << "total time of search : " << totaltime << "초\n";
    cout << "average time of search : " << meantime << "초\n";


    cout << "Time of single generation list : " << fixed << duration << "초\n";
    cout << "Time of single delete list : " << duration2 << "초\n";
    cout << "Time of additional insert list : " << duration3 << "초\n";
    cout << '\n\n\n\n';

    return 0;
}


