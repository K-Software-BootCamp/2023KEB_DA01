#include <iostream>
#include <random>
#include <cstdlib>
#include <vector>
#include "230821_list_final.hpp"


using namespace std;


int main(void) {
    DoublyLinkedList<int> dll; 


    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100000);


    clock_t start, end;
    double duration;
    start = clock();

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
    duration = (double)(end - start) / CLOCKS_PER_SEC;


    for (int i = 0; i < reference.size(); i++) {
        cout << reference[i] << "->";
    }

    cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';

   
    //시작과 끝 시간을 이용한 list의 insert 시간 계산
   





   

    //멀티스레드를 이용한 삭제 과정

    clock_t start1, end1;
    double duration1;
    start1 = clock();



    thread thread1([&]() {

        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100000);
        int count1 = 0;

        while (count1 < 5000) {
            int tmp = dis(gen);
            
             dll.deleteNode(tmp);

             count1++;
        }

        });
    thread thread2([&]() {


        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100000);
        int count2 = 0;

        while (count2 < 5000) {
            int tmp = dis(gen);
        

            dll.deleteNode(tmp);

            count2++;
        }

        });
    thread thread3([&]() {


        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100000);
        int count3 = 0;

        while (count3 < 5000) {
            int tmp = dis(gen);


            dll.deleteNode(tmp);

            count3++;
        }

        });
    thread thread4([&]() {

        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100000);
        int count4 = 0;

        while (count4 < 5000) {
            int tmp = dis(gen);


            dll.deleteNode(tmp);

            count4++;
        }
        });


    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    end1 = clock();
    duration1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

    cout << "delete 진행 완료\n\n\n";





    clock_t start2, end2;
    double duration2;
    start2 = clock();

    thread thread5([&]() {

        mt19937 gen(rd());
        uniform_int_distribution<> dis(100001, 125000);
       
        int count5 = 0;

        while (count5 < 5000) {
            int tmp = dis(gen);


            dll.insertNode(tmp);

            count5++;
        }
      
  });

       
    thread thread6([&]() {

        mt19937 gen(rd());
        uniform_int_distribution<> dis(125001, 150000);
        int count6 = 0;

        while (count6 < 5000) {
            int tmp = dis(gen);
            dll.insertNode(tmp);

            count6++;
        }
    });


        

    thread thread7([&]() {

        mt19937 gen(rd());
        uniform_int_distribution<> dis(150001, 175000);
       
        int count7 = 0;

        while (count7 < 5000) {
            int tmp = dis(gen);


            dll.insertNode(tmp);

            count7++;
        }
        });
    thread thread8([&]() {

        mt19937 gen(rd());
        uniform_int_distribution<> dis(175001, 200000);
        int count8 = 0;

        while (count8 < 5000) {
            int tmp = dis(gen);


            dll.insertNode(tmp);

            count8++;
        }
        });

    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();

    end2 = clock();
    //시작과 끝 시간을 이용한 list의 insert 시간 계산
    duration2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    cout << "추가 insert 진행 완료 \n\n\n";



    dll.displayList();


    cout << "\n\n\n\n";



   
    cout << "Time of single generation lsist: " << duration << "초\n";
    cout << "Time of multithread delete list : " << duration1 << "초\n";
    cout << "Time of add multithread generation list : " << duration2 << "초\n";

    cout << '\n';

    return 0;
}
