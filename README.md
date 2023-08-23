# Concurrent 자료구조

## 프로젝트 소개
자료구조의 종류인 Linked List 와 Binary Tree, Red-Black Tree 를 Concurrency (멀티 프로세싱) 을 활용해 구현
<br>

## 개발 기간
* 23.07.27~23.08.23

### 팀원 소개
- 팀장   : 조준형 - Binary Tree 관련 기능 구현 및 데이터 생성
- 팀원 1 : 구교진 - Binary Tree 생성 및 탐색 시간 측정, Concurrency 활용 기능 추가
- 팀원 2 : 송우민 - Linked List 관련 기능 구현 및 데이터 생성
- 팀원 3 : 이병현 - Linked List 생성 및 탐색 시간 측정, Concurrency 활용 기능 추가
- 팀원 4 : 김규용 - Red-Black Tree 관련 기능 구현 및 데이터 생성, Concurrency 활용 기능 추가 

### 개발 환경
- `C++`
- Visual Studio Code
- Visual Studio 2022

## 프로젝트 목표
- 자료구조에 대한 이해 및 Concurrency에 대한 이해
- 각 자료구조의 차이점 분석 (생성 및 탐색 시간 중심으로)
- 각 자료구조의 관리를 concurrency 활용하는 방향으로 실행 (입력과 삭제 기능을 중심으로)
- Concurrent 자료구조를 활용했을 때의 이점 분석

## 프로그래밍 연습 깃허브
- 자료구조팀 : https://github.com/nimjk/RedBlackTree
- Concurrent팀 : https://github.com/nimjk/ConcurrentTree

## 참고 자료
- C++ 관련
    - 전문가를 위한 C++ 5TH EDITION (한빛미디어/Marc Gregoire 저서)
    - 쉽게 배우는 알고리즘 : http://www.tcpschool.com/cpp/intro
    - 코드 생성 연습용 사이트 : https://pythontutor.com/render.html#mode=edit
    - C++ STL 모음 사이트 : https://web.archive.org/web/20160811224408/http://www.stepanovpapers.com/butler.hpl.hp/stl/stl/
    - C++ 언어 관련 블로그 : https://inpa.tistory.com/

- git 관련
    - git 활용 관련 영상 주소(mac) : https://youtu.be/Z9dvM7qgN9s
    - git 활용 관련 영상 주소(window 포함 및 상세) : https://www.youtube.com/watch?v=1I3hMwQU6GU&t=1365s
    - git 협업 팁 (Feature Branch Workflow) : https://gmlwjd9405.github.io/2017/10/27/how-to-collaborate-on-GitHub-1.html
    - git 브랜치 종류와 사용법 : https://sudo-minz.tistory.com/114
    - git 브랜치의 이해 & git 태그의 이해 :https://velog.io/@sorzzzzy/Code.presso-2주차-1.-실무자가-알려주는-Git-활용한-프로젝트-관리1

- 자료구조 관련 
    - Linked List 관련
        - Lock-Free Linked Lists and Skip Lists (Mikhail Fomitchev, Eric Ruppert, York University, 2003) 
        - Double Linked list concurrency 적용 사례 : https://github.com/sysprog21/concurrent-ll        

    - Binary Tree 관련
        - Binary Tree 설명 및 구현 영상 : https://youtu.be/V97oYgN9cIE, https://youtu.be/zUt2KB2hTQg
        - Binary Tree 이론 및 코드 관련 기사 : https://simplesnippets.tech/what-is-binary-search-tree-bst-with-full-code-dsa/

    - Redblack Tree 관련 
        - 레드-블랙 트리 개념과 도식화 : https://www.youtube.com/watch?v=qvZGUFHWChY
        - 레드-블랙 트리 그래픽 구현 사이트 : https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
        - 레드-블랙 트리 CAS 적용 : Lock-Free Red-Black Trees Using CAS (Jong Ho Kim, Helen Cameron, Peter Graham, 2011)


- Concurreny(동시성) 관련 
    - 영상 참고 
        - Modern C++ 활용 선행학습
            - 메모리 모델 학습 메모리 학습 : https://www.youtube.com/watch?v=xyHUNTvS9uQ&list=PLDV-cCQnUlIYbHztmY7hFUCd2eGI7sQ_0
            - 빌드 프로세스 학습 빌드 프로세스 학습 : https://www.youtube.com/watch?v=nSikXlDmdec&list=PLDV-cCQnUlIY4TMoRsrW0oqjCLTSm1nAf
            - LR Value LR Value : https://www.youtube.com/watch?v=iQBXzttfU5c&list=PLDV-cCQnUlIa5K5UYxaXsH78Ao0pltrlq
            - OOP : https://www.youtube.com/watch?v=N3TKk2hf_X8&list=PLDV-cCQnUlIYTBn70Bd822n2nlJwafCQE
            - 스마트 포인터 : https://www.youtube.com/watch?v=K8L9Pwfq47o&list=PLDV-cCQnUlIbOBiPvBaRPezOLArubgZbQ
            - 람다함수 : https://www.youtube.com/watch?v=a02gNgBJyK8&list=PLDV-cCQnUlIa9cy9one-i9foU8DwErnSp
            - 상속 : https://www.youtube.com/watch?v=AImBeri4pJY&list=PLDV-cCQnUlIar6Wx3rkXHs7wbfmlz34Fz

        - Concurrency(동시성)/Parallel(병렬성) 관련 기능 
            - threads Treads : https://www.youtube.com/watch?v=TnpZLBSLZfg&list=PLDV-cCQnUlIZfOrxXyQ115zbvI3hnemLU
            - Sync - 뮤텍스 소개 : https://www.youtube.com/watch?v=0pvx4k0lsoA&list=PLDV-cCQnUlIYBAg9tm1pNUyiYkSvwj1YW
            - Async - 비동기 호출 : https://www.youtube.com/watch?v=Urv11u-hqfM&list=PLDV-cCQnUlIZS95_tFTg9mkXIYXKze6r9
            - Parrallel - 병렬 프로그래밍 : https://www.youtube.com/watch?v=6LWuhlID_-s&list=PLDV-cCQnUlIZ7KbIe9sOMbjwETX1uwCxW
            - Atomic 아토믹 소개 : https://www.youtube.com/@user-pw9fm4gc7e
            - Conroutines 코루틴 소개 : https://www.youtube.com/playlist?list=PLDV-cCQnUlIYc1FGC6FJRdHgPucxb7bzp
            - Multi process/thread 멀티 프로세스/스레드 소개 : https://youtu.be/QmtYKZC0lMU

        - Concurrent Linked List : https://www.youtube.com/watch?v=eB0AlnK8iRI

    -코드 참고
        - Concurrent Red_Black Tree : https://github.com/JuanBesa/Concurrent-RedBlack-Tree

    - 홈페이지 참고 
        - 동시성 프로그래밍 설명 : https://tech.devsisters.com/posts/programming-languages-5-concurrent-programming/
        - Multi-threading : https://cplusplus.com/reference/multithreading/
        - 운영체제 관련 사이트 : https://pages.cs.wisc.edu/~remzi/OSTEP/
        - Concurrent Red-Black Tree : https://www.sciencedirect.com/science/article/pii/S0743731512002912

    - 블로그 참고 
        - C++ 멀티스레딩 프로그래밍 : https://junstar92.tistory.com/336, https://junstar92.tistory.com/337
        - 아토믹 관련 : https://junstar92.tistory.com/298
        - [운영체제] Concurrency(동시성)과 Parallelism(병렬성) 이해 : https://spacebike.tistory.com/22

- PDF 문헌 참고 자료는 해당 깃 Documents 폴더에 저장하였습니다.

## Acknowledgement
```
 "본 연구는 과학기술정보통신부 및 정보통신기획평가원의 SW전문인재양성사업의 연구결과로 수행되었음"(2022-0-01127) 
```

<hr>

