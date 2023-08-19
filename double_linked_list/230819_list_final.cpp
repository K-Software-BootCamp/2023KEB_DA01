#include <iostream>
#include "list_final.hpp"


using namespace std;



int main() {
    DoublyLinkedList<int> dll; // list 만들고 이름 지정

    clock_t start, end;
    double duration;
    start = clock();


    srand(GetTickCount64());  // 랜덤한 2천개의 숫자 지정.
    int arr[2000];
    int count = 0;

    while (count < 2000) {
        int tmp = rand() % 5000 + 1;
        int isSame = 0;
        for (int i = 0; i < count; i++) {
            if (tmp == arr[i]) {
                isSame = 1;
                break;
            }
        }
        if (isSame == 0) {      // 중복인 경우 거르고 insert
            arr[count] = tmp;
            dll.insertNode(arr[count]);
            count++;
        }
    }
    end = clock();
    //시작과 끝 시간을 이용한 list의 insert 시간 계산
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time of generation list : " << duration << "초\n";





    int searchcnt = 0;

    clock_t start5, end5;
    double duration5;

    double mintime, maxtime;
    double totaltime = 0;
    double meantime = 0;


    while (searchcnt < 100) {
        int searchidx = rand() % 2000;
        int searchnum = rand() % 5000 + 1;

        start5 = clock();
        dll.search(searchnum); // 
        end5 = clock();

        duration5 = (double)(end5 - start5) / CLOCKS_PER_SEC;

        if (searchcnt == 0) {
            mintime = duration5;
            maxtime = duration5;
        }

        else {
            if (mintime > duration5) {
                mintime = duration5;
            }
            else if (maxtime < duration5) {
                maxtime = duration5;
            }
        }

        totaltime += duration5;

        searchcnt++;
    }

    meantime = totaltime / (searchcnt + 1);



    //멀티스레드를 이용한 삭제 과정

    clock_t start2, end2;
    double duration2;
    start2 = clock();
    thread thread1([&dll]() {
       
        int arr1[500];
        int count1 = 0;

      

        while (count1 < 500) {
            int tmp1 = rand() % 5000 + 1;
            int isSame1 = 0;
            for (int i = 0; i < count1; i++) {
                if (tmp1 == arr1[i]) {
                    isSame1 = 1;
                    break;
                }
            }
            if (isSame1 == 0) {      // 중복인 경우 거르고 delete
                arr1[count1] = tmp1;
                dll.deleteNode(arr1[count1]);
                count1++;
            }
        }

        });
    thread thread2([&dll]() {

        int arr2[500];
        int count2 = 0;

        

        while (count2 < 500) {
            int tmp2 = rand() % 5000 + 1;
            int isSame2 = 0;
            for (int i = 0; i < count2; i++) {
                if (tmp2 == arr2[i]) {
                    isSame2 = 1;
                    break;
                }
            }
            if (isSame2 == 0) {     
                arr2[count2] = tmp2;
                dll.deleteNode(arr2[count2]);
                count2++;
            }
        }

        });;
    thread thread3([&dll]() {

        int arr3[500];
        int count3 = 0;

        

        while (count3 < 500) {
            int tmp3 = rand() % 5000 + 1;
            int isSame3 = 0;
            for (int i = 0; i < count3; i++) {
                if (tmp3 == arr3[i]) {
                    isSame3 = 1;
                    break;
                }
            }
            if (isSame3 == 0) {    
                arr3[count3] = tmp3;
                dll.deleteNode(arr3[count3]);
                count3++;
            }
        }

        });;
    thread thread4([&dll]() {

        int arr4[500];
        int count4 = 0;

        
        while (count4 < 500) {
            int tmp4 = rand() % 5000 + 1;
            int isSame4 = 0;
            for (int i = 0; i < count4; i++) {
                if (tmp4 == arr4[i]) {
                    isSame4 = 1;
                    break;
                }
            }
            if (isSame4 == 0) {   
                arr4[count4] = tmp4;
                dll.deleteNode(arr4[count4]);
                count4++;
            }
        }

        });;


    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    end2 = clock();
    duration2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

    cout << "delete 진행 완료\n";

    clock_t start3, end3;
    double duration3;
    start3 = clock();


    thread thread5([&dll]() {
        int arr5[500];
        int count5 = 0;

        
        while (count5 < 500) {
            int tmp5 = rand() % 5000 + 5001;
            int isSame5 = 0;
            for (int i = 0; i < count5; i++) {
                if (tmp5 == arr5[i]) {
                    isSame5 = 1;
                    break;
                }
            }
            if (isSame5 == 0) {      // 중복인 경우 거르고 insert
                arr5[count5] = tmp5;
                dll.insertNode(arr5[count5]);
                count5++;
            }
        }

        });

    thread thread6([&dll]() {
        int arr6[500];
        int count6 = 0;

      

        while (count6 < 500) {
            int tmp6 = rand() % 5000 + 5001;
            int isSame6 = 0;
            for (int i = 0; i < count6; i++) {
                if (tmp6 == arr6[i]) {
                    isSame6 = 1;
                    break;
                }
            }
            if (isSame6 == 0) {     
                arr6[count6] = tmp6;
                dll.insertNode(arr6[count6]);
                count6++;
            }
        }

        });

    thread thread7([&dll]() {
        int arr7[500];
        int count7 = 0;


        while (count7 < 500) {
            int tmp7 = rand() % 5000 + 5001;
            int isSame7 = 0;
            for (int i = 0; i < count7; i++) {
                if (tmp7 == arr7[i]) {
                    isSame7 = 1;
                    break;
                }
            }
            if (isSame7 == 0) {   
                arr7[count7] = tmp7;
                dll.insertNode(arr7[count7]);
                count7++;
            }
        }
        });
    thread thread8([&dll]() {
        int arr8[500];
        int count8 = 0;

  

        while (count8 < 500) {
            int tmp8 = rand() % 5000 + 5001;
            int isSame8 = 0;
            for (int i = 0; i < count8; i++) {
                if (tmp8 == arr8[i]) {
                    isSame8 = 1;
                    break;
                }
            }
            if (isSame8 == 0) {    
                arr8[count8] = tmp8;
                dll.insertNode(arr8[count8]);
                count8++;
            }
        }
        });

    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();

    end3 = clock();
    //시작과 끝 시간을 이용한 list의 insert 시간 계산
    duration3 = (double)(end3 - start3) / CLOCKS_PER_SEC;






    cout << "추가 insert 진행 완료 \n";



    //멀티스레드를 이용한 삭제 과정

    clock_t start4, end4;
    double duration4;
    start4 = clock();
   
    int arr9[2000];
    int count9 = 0;

    while (count9 < 2000) {
        int tmp9 = rand() % 5000 + 5001;
        int isSame9 = 0;
        for (int i = 0; i < count9; i++) {
            if (tmp9 == arr[i]) {
                isSame9 = 1;
                break;
            }
        }
        if (isSame9 == 0) {      // 중복인 경우 거르고 insert
            arr9[count9] = tmp9;
            dll.deleteNode(arr9[count9]);
            count9++;
        }
    }



    end4 = clock();
    duration4 = (double)(end4 - start4) / CLOCKS_PER_SEC;

    cout << "추가 delete 진행 완료\n";


    dll.displayList();






    cout << "minimum time of search : " << fixed << mintime << "초\n";
    cout << "maximum time of search : " << maxtime << "초\n";
    cout << "total time of search : " << totaltime << "초\n";
    cout << "average time of search : " << meantime << "초\n";


    cout << "Time of single generation list : " << fixed << duration << "초\n";
    cout << "Time of multithread delete list : " << duration2 << "초\n";
    cout << "Time of multithread generation list : " << duration3 << "초\n";
    cout << "Time of single delete list : " << duration4 << "초\n";
    cout << '\n';

    return 0;
}



