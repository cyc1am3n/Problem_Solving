# [알고리즘 기초] 1강 강의 노트 - 알고리즘과 입출력

> ### Contents
>
> - [알고리즘](#알고리즘-)
>   - [공부하는 방법](#공부하는-방법-)
>   - [더 중요한 점](#더-중요한-점-)
>   - [프로그래밍 언어](#프로그래밍-언어-)
> - [시간 복잡도](#시간-복잡도-)
> - [입/출력](#입출력-)

### 알고리즘 [↑](#contents)

- 알고리즘이란 어떠한 문제를 해결하기 위한 여러 동작들의 모임이다.
- 알고리즘 공부에 가장 효과적인 것은 **문제 풀이** 이다.

#### 공부하는 방법 [↑](#contents)

1. 먼저 알고리즘이나 문제를 푸는 방법을 이해
   - 완벽하지 않거나 일부만 이해했어도 성공!
2. 관련 문제를 풀어본다.
   - 한 문제는 길어야 2시간 정도만 고민해본다.
   - 모르겠으면 포기하고 정답 소스를 보거나 풀이를 본다.
3. 1번과 2번에서 이해가 잘 가지 않는 부분이 있으면 질문한다.
   - 설마 이런 것을 질문해도 될까 고민 되는 것도 질문해야 한다.
4. 다시 알고리즘을 이해해보고 문제를 다시 풀어본다.
   - 모르겠으면 포기하고 다시 풀이를 본다.
   - 그래도 모르겠으면 다른 일을 하거나, 놀러 나가거나, 다른 알고리즘이나 문제를 풀어본다.

#### 더 중요한 점 [↑](#contents)

- 더 중요한 것은 모르겠으면 포기하고 풀이를 보는 것
- 스스로 생각해서 해결하지 않고 답을 보고 해결했어도 해결한 것이다.
- 1개를 3일에 걸쳐서 푸는 것 보다 3개를 1일동안 푸는 것이 더 좋다.
- 여기서 포기라는 것은 최대한 노력을 해보고를 의미함(그래도 1~2시간 고민해도 모르겠으면 포기!)
- 알고리즘에서 제일 중요한 것은 알고리즘을 만드는 것이 아니고, 생각의 과정을 배워서 나중에 스스로 그러한 생각을 해내는 것

#### 프로그래밍 언어 [↑](#contents)

- 프로그래밍 언어는 크게 상관이 없다.
- 많은 사람들이 알고리즘 문제를 풀 때 사용하는 언어: C++ > C > Java
- C언어를 사용하는 경우에는 C++을 사용하는 것이 좋다.
- Java를 사용하는 경운에는 `Scanner`를 이용해 입력을 편리하게 받는 것이 좋다.

<br/>

### 시간 복잡도 [↑](#contents)

- 시간 복잡도를 이용하면 작성한 코드가 시간이 얼마나 걸릴지 예상할 수 있다.
- 알고리즘 문제에서는 대부분 *Big O Notation* 을 사용하는데, 표기법으로는 대문자 `O` 를 사용한다.
- 입력의 크기에 대해서 시간이 얼마나 걸릴지 나타내는 방법이다.
- 최악의 경우에 시간이 얼마나 걸릴지 나타내야 한다.

```c++
// 1부터 N까지 합을 계산하는 소스 - (1)
int sum = 0;
for (int i=0; i<=N; i++) {
  sum += i;
}
// 시간 복잡도: O(N)
```

```c++
// 1부터 N까지 합을 계산하는 소스 - (2)
int sum = 0;
sum = N*(N+1)/2;
// 시간 복잡도: O(1)
```

```c++
// 1부터 N까지 합을 계산하는 소스 - (3)
int sum = 0;
for (int i=0; i<n; i++) {
  for (int j=0; j <=n; j++) {
    if (i == j) {
      sum += j;
    }
  }
}
// 시간 복잡도: O(N^2)
```

- 대표적인 시간 복잡도와 그 의미는 다음과 같다(대부분의 경우이고, 항상 그런 것은 아니다).
  - O(1): 단순 계산(a+b와 같은 계산, 배열에 접근하는 연산)
  - O(logN): N개를 절반으로 계속해서 나눔
  - O(N): 1중 for 문
  - O(NlogN)
  - O(N^2): 2중 for 문
  - O(N^3): 3중 for 문
  - O(2^N): 크기가 N인 집합의 부분 집합
  - O(N!): 크기가 N인 순열
- *Big O Notation* 에서 상수는 버린다.
  - O(3N^2) = O(N^2)
  - O(1/2 N^2)  = O(N^2)
  - O(5) = O(1)
- 두 가지 항이 있을 때, 변수가 같으면 큰 것만 빼고 다 버린다.
  - O(N^2 + N) = O(N^2)
  - O(N^2 +NlogN) = O(N^2)
- 두 가지 항이 있는데 변수가 다르면 놔둔다.
  - O(N^2 + M)

<br />

### 입/출력 [↑](#contents)

- 입/출력의 경우에는 STL [1강](https://github.com/cyc1am3n/Problem_Solving/blob/master/Lecture%20Note/C%20_C%2B%2B_STL/lec01-c.md)과 [2강](https://github.com/cyc1am3n/Problem_Solving/blob/master/Lecture%20Note/C%20_C%2B%2B_STL/lec02-c%2B%2B.md)을 참고하자.