#include <iostream>
#include <random>
#include <cstdlib>
#include <vector>
#include "Linked_List.hpp"


using namespace std;


int main(void) {
    DoublyLinkedList<int> dll; 


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

    clock_t delstart, delend;
    double delduration;
    
    delstart = clock();

    thread thread1([&]() {

        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000000);
        int count1 = 0;

        while (count1 < 50000) {
            int tmp = dis(gen);
            
             dll.deleteNode(tmp);

             count1++;
        }

        });
    thread thread2([&]() {


        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000000);
        int count2 = 0;

        while (count2 < 50000) {
            int tmp = dis(gen);
        

            dll.deleteNode(tmp);

            count2++;
        }

        });
    thread thread3([&]() {


        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000000);
        int count3 = 0;

        while (count3 < 50000) {
            int tmp = dis(gen);


            dll.deleteNode(tmp);

            count3++;
        }

        });
    thread thread4([&]() {

        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000000);
        int count4 = 0;

        while (count4 < 50000) {
            int tmp = dis(gen);


            dll.deleteNode(tmp);

            count4++;
        }
        });


    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    delend = clock();
    delduration = (double)(delend - delstart) / CLOCKS_PER_SEC;

    // cout << "delete 완료\n\n\n";

    clock_t insstart, insend;
    double insduration;
    insstart = clock();

    thread thread5([&]() {

        mt19937 gen(rd());
        uniform_int_distribution<> dis(1000001, 1250000);
       
        int count5 = 0;

        while (count5 < 50000) {
            int tmp = dis(gen);


            dll.insertNode(tmp);

            count5++;
        }
      
  });

       
    thread thread6([&]() {

        mt19937 gen(rd());
        uniform_int_distribution<> dis(1250001, 1500000);
        int count6 = 0;

        while (count6 < 50000) {
            int tmp = dis(gen);
            dll.insertNode(tmp);

            count6++;
        }
    });


        

    thread thread7([&]() {

        mt19937 gen(rd());
        uniform_int_distribution<> dis(1500001, 1750000);
       
        int count7 = 0;

        while (count7 < 50000) {
            int tmp = dis(gen);


            dll.insertNode(tmp);

            count7++;
        }
        });
    thread thread8([&]() {

        mt19937 gen(rd());
        uniform_int_distribution<> dis(1750001, 2000000);
        int count8 = 0;

        while (count8 < 50000) {
            int tmp = dis(gen);


            dll.insertNode(tmp);

            count8++;
        }
        });

    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();

    insend = clock();
    insduration = (double)(insend - insstart) / CLOCKS_PER_SEC;
    // cout << "추가 concurrent 방식의 insert 진행 완료 \n\n\n";

    // dll.displayList();

    cout << "Linked List (Multi-Thread) Delete TotalTime : " << delduration << "초\n";
    cout << "Linked List (Multi-Thread) Insert Total Time : " << insduration << "초\n";
    return 0;
}
