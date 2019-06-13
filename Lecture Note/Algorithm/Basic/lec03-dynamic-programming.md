# [알고리즘 기초] 3강 강의 노트 - 다이나믹 프로그래밍

> ### Contents
>
> - [다이나믹 프로그래밍](#다이나믹-프로그래밍-)
>   - [구현 예시](#구현-예시-)
>   - [Top-down](#top-down-)
>   - [Bottom-up](#bottom-up-)
> - [다이나믹 프로그래밍 문제풀이 전략](#다이나믹-프로그래밍-문제풀이-전략-)
>   - [예제 1 - 1로 만들기](#예제-1---1로-만들기-)
>   - [예제 2 - 2 x n 타일링](#예제-2---2-x-n-타일링-)
>   - [예제 3 - 카드 구매하기](#예제-3---카드-구매하기-)

<br/>

### 다이나믹 프로그래밍 [↑](#contents)

- 큰 문제를 작은 문제로 나눠서 푸는 알고리즘

- *Dynamic Programming* 에서 다이나믹은 아무 의미가 없다.

- 두 가지 속성을 만족해야 다이나믹 프로그래밈으로 문제를 풀 수 있다.

  1. Overlapping Subproblem
  2. Optimal Substructure

- Overlapping Subproblem

  - 큰 문제와 작은 문제를 같은 방법으로 풀 수 있다.
  - 문제를 작은 문제로 쪼갤 수 있다.

  > ex) 피보나치 수
  >
  > - 문제: **N** 번째 피보나치 수를 구하는 문제
  > - 작은 문제: **N-1** 번째 피보나치 수를 구하는 문제, **N-2** 번째 피보나치 수를 구하는 문제
  >
  >   ↓
  >
  > - 문제: **N-1** 번째 피보나치 수를 구하는 문제
  > - 작은 문제: **N-2** 번째 피보나치 수를 구하는 문제, **N-3** 번째 피보나치 수를 구하는 문제
  >
  > ↓
  >
  > - 문제: **N-2** 번째 피보나치 수를 구하는 문제
  > - 작은 문제: **N-3** 번째 피보나치 수를 구하는 문제, **N-4** 번째 피보나치 수를 구하는 문제
  >
  > ↓
  >
  > ...

  

- Optimal Substructure

  - 문제의 정답을 작은 문제의 정답에서 구할 수 있다.

  > ex) 피보나치 수
  >
  > - 문제의 정답을 작은 문제의 정답을 합하는 것으로 구할 수 있다.

  - Optimal Substructure를 만족한다면, 문제의 크기에 상관없이 어떤 한 문제의 정답은 일정하다.
    - 10번째 피보나치 수를 구하면서 구한 **4번째 피보나치 수**
    - 9번째 피보나치 수를 구하면서 구한 **4번째 피보나치 수**
    - ...
    - 5번째 피보나치 수를 구하면서 구한 **4번째 피보나치 수**
    - 4번째 피보나치 수를 구하면서 구한 **4번째 피보나치 수**
    - 에서 4번째 피보나치 수는 항상 같다.

- 다이나믹 프로그래밍에서 각 문제는 한 번만 풀어야 한다.

- Optimal Substructure를 만족하기 때문에, 같은 문제는 구할 때마다 정답이 같다.

- 따라서, 정답을 한 번 구했으면 정답을 어딘가에 메모해놓는다. (Memoization)

- 이렇게 메모하는 것을 코드로는 배열에 저장해 구현한다.

#### 구현 예시 [↑](#contents)

```c++
// 피보나치 수 (original)
int fibonacci(int n) {
  if(n <= 1) return n;
  else return fibonacci(n-1) + fibonacci(n-2);
}
```

- 위와 같은 코드는 이전에 구했던 값도 반복해서 구할 수 밖에 없다.
- 따라서 한 번 답을 구할 떄, 어딘가에 메모를 해놓고 중복 호출이면 메모해놓은 값을 리턴한다.

```c++
// 피보나치 수 (ver. DP)
int memo[100];
int fibonacci(int n) {
  if (n <= 1) return n;
  else {
    if (memo[n] > 0) {
      return memo[n];
    }
    memo[n] = fibonacci(n-1) + fibonacci(n-2);
    return memo[n];
  }
}
```

- 다이나믹 프로그래밍에는 두 가지 방법이 있다.
  1. **Top-down**
  2. **Bottom-up**

#### Top-down [↑](#contents)

1. 문제를 풀어야 한다
   - `fibonacci(n)`
2. 문제를 작은 문제로 나눈다.
   - `fibonacci(n-1)` 과 `fibonacci(n-2)` 로 문제를 나눈다.
3. 작은 문제를 푼다.
   - `fibonacci(n-1)` 과 `fibonacci(n-2)` 를 호출해 문제를 푼다.
4. 작은 문제를 풀었으니, 이제 문제를 푼다.
   - `fibonacci(n-1)` 의 값과 `fibonacci(n-2)` 의 값을 더해 문제를 푼다.

- Top-down은 재귀 호출을 이용해서 문제를 쉽게 풀 수 있다.

#### Bottom-up [↑](#contents)

1. 문제를 크기가 작은 문제부터 차례대로 푼다.
   - for (int i = 2; i <= n; i++)
2. 문제의 크기를 조금씩 크게 만들면서 문제를 점점 푼다.
   - for(int i = 2; i <= n; **i++**)
3. 작은 문제를 풀면서 왔기 때문에, 큰 문제는 항상 풀 수 있다.
   - `d[i] = d[i-1] + d[i-2]`
4. 그러다보면, 언제간 풀어야 하는 문제를 풀 수 있다.
   - `d[n]` 을 구하게 된다.

<br />

### 다이나믹 프로그래밍 문제 풀이 전략 [↑](#contents)

- 문제에서 구하려고 하는 답을 문장으로 나타낸다.
  - 피보나치 수 문제 → N번째 피보나치 수
- 이제 그 문장에 나와있는 변수의 개수만큼 메모하는 배열을 만든다.
- Top-down 인 경우에는 재귀 호출의 인자의 개수
- 문제를 작은 문제로 나누고, 수식을 이용해서 문제를 표현해야 한다.

#### 예제 1 - 1로 만들기 [↑](#contents)

- 링크: https://www.acmicpc.net/problem/1463

> - 어떤 정수 N에 다음과 같은 연산 중 하나를 할 수 있다.
>
> 1. N이 3으로 나누어 떨어지면, 3으로 나눈다.
> 2. N이 2로 나누어 떨어지면. 2로 나눈다.
> 3. 1을 뺀다.
>
> - 어떤 정수 N에 위와 같은 연산을 선택해서 1을 만드려고 하는데, 연산 사용 횟수의 최솟값을 구하는 문제.

- `D[N]` 을 N을 1로 만드는데 필요한 최소 연산 횟수라고 하면, 가능한 경우는
  1. N이 3으로 나누어 떨어졌을 때, 3으로 나누는 경우 : `D[N/3] + 1`
  2. N이 2로 나누어 떨어졌을 때, 2로 나누는 경우 : `D[N/2] + 1`
  3. N에서 1을 빼는 경우 : `D[i-1] + 1`
- 위 세 값 중 최소값이 들어가게 된다.

```c++
// Top-down
int makeOne(vector<int> &v, int n) {
    int temp;
    if (v[n] != -1) return v[n];

    if (n > 1) {
        temp = makeOne(v, n-1);
        v[n] = temp + 1;
    }
    if (n % 3 == 0) {
        temp = makeOne(v, n/3);
        if (v[n] > temp + 1 ) v[n] = temp + 1;
    }
    if (n % 2 == 0) {
        temp = makeOne(v, n/2);
        if (v[n] > temp + 1) v[n] = temp + 1;
    }
    return v[n];
}

int main() {
    int num;
    cin >> num;
    vector<int> v(num + 1, -1);
    v[1] = 0;
    cout << makeOne(v, num);
}
```

```c++
// Bottom-up
int main() {
    int num;
    cin >> num;
    vector<int> v(num + 1, -1);
    v[1] = 0;
    for (int i = 2; i <= num; i++) {
        int temp = v[i - 1] + 1;
        if (i % 2 == 0)
            if (temp > v[i/2] + 1) temp = v[i/2] + 1;
        if (i % 3 == 0)
            if (temp > v[i/3] + 1) temp = v[i/3] + 1;
        v[i] = temp;
    }
    cout << v[num];
}
```



#### 예제 2 - 2 x n 타일링 [↑](#contents)

- 링크: https://www.acmicpc.net/problem/11726

> - 2 x n 직사각형을 1 x 2, 2 x 1 타일로 채우는 방법의 수를 구하는 문제
>
> - 아래 그림은 2 x 5 크기의 직사각형을 채운 한 가지 방법의 예이다.
>
>   ![image](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11726/1.png)

- `D[N]` : 2 x N 직사각형을 채우는 방법의 수
- 2 x n 직사각형을 1 x 2, 2 x 1 타일로 채우는 경우는
  1. 2 x (n - 1) 직사각형 채우기 + 제일 끝 열을 2 x 1 타일 하나로 채우기
  2. 2 x (n - 2) 직사각형 채우기 + 제일 끝 두 열을 1 x 2 타일 두 개로 채우기
- 로 나누어지므로 `D[N] = D[N-1] + D[N-2]` 로 식을 간단히 할 수 있다.

```c++
// Top-down
int make2Xn(vector<int> &v, int n) {
    if (v[n] != -1) return v[n];
    if (n > 2) v[n] = (make2Xn(v, n-1) + make2Xn(v, n-2)) % 10007;
    return v[n];
}

int main() {
    int num;
    cin >> num;
    vector<int> v(num + 1, -1);
    v[1] = 1, v[2] = 2;
    cout << make2Xn(v, num);
}
```

```c++
// Bottom-up
int main() {
    int num;
    cin >> num;
    vector<int> v(num + 1, -1);
    v[1] = 1, v[2] = 2;
    for (int i = 3; i <= num; i++) {
        v[i] = (v[i - 1] + v[i - 2]) % 10007;
    }
    cout << v[num];
}
```



#### 예제 3 - 카드 구매하기 [↑](#contents)

- 링크: https://www.acmicpc.net/problem/11052

> - 카드는 카드팩의 형태로만 구매할 수 있고, 카드팩의 종류는 카드 1개가 포함된 카드팩, 카드 2개가 포함된 카드팩, ... 카드 N개가 포함된 카드팩과 같이 총 N가지가 존재한다.
> - i 개의 카드가 들어있는 카드팩의 금액이 `P[i]`일 때, N개의 카드를 구매했을 때의 최대 지출을 구하는 문제
> - 예를 들어, 카드팩이 총 4가지 종류가 있고, `P[1]` = 1, `P[2]` = 5, `P[3]` = 6, `P[4]` = 7인 경우에 카드 4개를 갖기 위해 지불해야 하는 금액의 최댓값은 10원이다. (2개  카드팩을 2번 구매)

- `D[i]` : 카드 i 개를 구매할 때의 최대 지출
- 가능한 경우 생각해보기
  - 카드 1개를 `P[1]`에 구매 → 남은 카드의 개수: i - 1 → `P[1] + D[i-1]`
  - 카드 2개를 `P[2]`에 구매 → 남은 카드의 개수: i - 2 → `P[2] + D[i-2]`
  - ...
  - 카드 i - 1개를 `P[i-1]`에 구매 → 남은 카드의 개수: 1 → `P[i-1] + D[1]`
  - 카드 i개를 `P[i]`에 구매 → 남은 카드의 개수: 0 → `P[i] + D[0]`
- `D[i] = max(P[j] + D[i-j]) (1 ≤ j ≤ i)`

```c++
int main() {
    int n;
    cin >> n;
    vector<int> P = {-1}, D = {-1};
    for(int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        P.push_back(cost);
        D.push_back(cost);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            D[i] = max(D[i], P[j] + D[i-j]);
        }
    }
    cout << D[n];
}
```