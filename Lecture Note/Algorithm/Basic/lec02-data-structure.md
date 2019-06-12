# [알고리즘 기초] 2강 강의 노트 - 자료구조

> ### Contents
>
> - [스택](#스택-)
>   - [예제 1 - 괄호](#예제-1-괄호-)
>   - [예제 2 - 쇠막대기](#예제-2-쇠박대기-)
>   - [예제 3 - 에디터](#예제-3-에디터-)
> - [큐](#큐-)
>   - [예제 - 조세퍼스 문제](#예제-조세퍼스-문제-)
> - [덱](#덱-)
> - [문자열](#문자열-)
>   - [아스키코드](#아스키코드-)
>   - [예제 1 - ROT13](#예제-1-ROT13-)
>   - [예제 2 - 접미사 배열](#예제-2-접미사-배열-)

### 스택 [↑](#contents)

- 한쪽 끝에서만 자료를 넣고 뺼 수 있는 자료구조
- 마지막으로 넣은 것이 가장 먼저 나오기 때문에 *Last in First Out (LIFO)* 라고도 한다.
- 스택의 연산
  - `push`: 스택에 자료를 넣는 연산
  - `pop`: 스택에서 자료를 빼는 연산
  - `top`: 스택의 가장 위에 있는 자료를 보는 연산
  - `empty`: 스택이 비어있는지 아닌지를 알아보는 연산
  - `size`: 스택에 저장되어있는 자료의 개수를 알아보는 연산
- 스택은 C++의 경우에는 STL의 `stack` / Java의 경우에는 `java.util.Stack`을 사용하는 것이 좋다.

#### 예제 1 - 괄호 [↑](#contents)

- 링크: https://www.acmicpc.net/problem/9012
- 괄호 문자열이 주어졌을 때, 올바른 괄호 문자열인지 아닌지를 알아보는 문제
- 여기에서 괄호 문자열은 `(` 와 `)` 로만 이루어진 문자열이고,
- 올바른 괄호 문자열은 괄호의 쌍이 올바른 문자열을 뜻한다.

> - 올바른 괄호 문자열의 예시
>   - `()`
>   - `(())()`
>   - `((()))`
> - 올바른 괄호 문자열이 아닌 예시
>   - `(()(`
>   - `(())()))`
>   - `(()`

- 스택을 사용해서 올바른 괄호 문자열인지 아닌지를 알 수 있다.
  - `(` 가 나오면 스택에 `(` 를 넣고
  - `)` 가 나오면 스택에서 하나를 빼서 `(` 인지 확인한다.
  - 또는 하나를 뺄 수 있는지를 확인한다.

```c++
stack<int> s;
bool check = true;
for (auto x : brackets) {
  if (x == '(') s.push(1);
  else{
    if(s.empty()) {
      check = false;
      break;
    } else s.pop();
  }
}
if(check && !s.empty()) check = false;
```



#### 예제 2 - 쇠막대기 [↑](#contents)

- 링크: https://www.acmicpc.net/problem/10799
- 레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 `( )` 으로 표현된다. 또한, 모든 `( )` 는 반드시 레이저를 표현한다.
- 쇠막대기의 왼쪽 끝은 여는 괄호 `(` 로, 오른쪽 끝은 닫힌 괄호 `)` 로 표현된다.

> ![image](https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10799/1.png)

* 올바른 괄호 문자열과 비슷하게 풀 수 있다.
* `( )` 가 나올 때 마다 스택에 들어있는 `(` 의 개수를 세어준다.
* 그런데 `)` 가 나왔을 때, 이것이 레이저인지 쇠막대기인지 구분을 해줘야 한다.
* 레이저는 항상 `()` 와 같이 붙어진 상태로 나온다.
* 스택의 `(` 의 인덱스를 넣어서 인덱스의 차이가 1이 되는지 확인해야 한다.

```c++
stack<int> s;
int iron = 0, index = 0;
for (auto x : brackets) {
  if (x == '(') s.push(index);
  else {
    if (s.top() == index - 1) iron += s.size() - 1;
    else iron++; // 레이저 없이 생기는 막대기 하나
    s.pop();
  }
  index++;
}
```



#### 예제 3 - 에디터 [↑](#contents)

- 링크: https://www.acmicpc.net/problem/1406

> * 커서: 문장의 맨 앞, 맨 뒤, 문장 중간 임의의 곳에 위치할 수 있다.
> * `L`: 커서를 왼쪽으로 한 칸 옮김
> * `D`: 커서를 오른쪽으로 한 칸 옮김
> * `B`: 커서 왼쪽에 있는 문자를 삭제함
> * `P $`: `$` 라는 문자를 커서 오른쪽에 추가함. 커서는 `$`에 위치함

- 커서를 기준으로 커서의 왼쪽 스택(left)와 오른쪽 스택(right)로 나눠서 문제를 풀 수 있다.

```c++
if (cmd == 'L') {
  if(!left.empty()) {
    right.push(left.top());
    left.pop();
  }
} else if (cmd == 'D') {
  if(!right.empty()) {
    left.push(right.top());
    right.pop();
  }
} else if (cmd == 'B'){
  if (!left.empty()) left.pop();
} else if (cmd == 'P') {
  char c;
  cin >> c;
  left.push(c);
}
```

<br />

### 큐 [↑](#contents)

- 한쪽 끝에서만 자료를 넣고 다른 한쪽 끝에서만 뺄 수 있는 자료구조
- 먼저 넣은 것이 가장 먼저 나오기 때문에 *First In First Out (FIFO)* 라고도 한다.
- 큐의 연산
  - `push`: 큐에 자료를 넣는 연산
  - `pop`: 큐에서 자료를 빼는 연산
  - `front`: 큐의 가장 앞에 있는 자료를 보는 연산
  - `back`: 큐의 가장 뒤에 있는 자료를 보는 연산
  - `empty`: 큐가 비어있는지 아닌지를 알아보는 연산
  - `size`: 큐에 저장되어있는 자료의 개수를 알아보는 연산
- 큐는 C++ 의 경우에는 STL의 `queue` / Java의 경우에는 `java.util.Queue` 를 사용하는 것이 좋다.

#### 예제 - 조세퍼스 문제 [↑](#contents)

- 링크: https://www.acmicpc.net/problem/1158
- 1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 M(≤N)이 주어진다.
- 이제 순서대로 M번째 사람을 제거한다.
- 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.
- 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다.
- 원에서 사람들이 제거되는 순서를 `(N, M)-조세퍼스 순열` 이라고 한다.

```c++
int N, K;
cin >> N >> K;
queue<int> q;
for (int i = 1; i <= N; i++) q.push(i);
cout << '<';
while(q.size() != 1) {
  for (int i = 1; i < K; i++) {
    q.push(q.front());
    q.pop();
  }
  cout << q.front() << ", ";
  q.pop();
}
cout << q.front() << '>';
```

<br />

### 덱 [↑](#contents)

- 양 끝에서만 자료를 넣고 양 끝에서 뺄 수 있는 자료구조
- *Double-ended queue* 의 약자이다.
- 덱의 연산
  - `push_front`: 큐에 자료를 넣는 연산
  - `pop`: 큐에서 자료를 빼는 연산
  - `front`: 큐의 가장 앞에 있는 자료를 보는 연산
  - `back`: 큐의 가장 뒤에 있는 자료를 보는 연산
  - `empty`: 큐가 비어있는지 아닌지를 알아보는 연산
  - `size`: 큐에 저장되어있는 자료의 개수를 알아보는 연산

```c++
// https://www.acmicpc.net/problem/10866 - 덱
int n;
cin >> n;

deque<int> dq;

while(n--) {
  string cmd;
  cin >> cmd;
  if(cmd == "push_front") {
    int num;
    cin >> num;
    dq.push_front(num);
  }
  else if(cmd == "push_back") {
    int num;
    cin >> num;
    dq.push_back(num);
  }
  else if(cmd == "pop_front") {
    if(dq.empty())
      cout << -1 << '\n';
    else {
      cout << dq.front() <<'\n';
      dq.pop_front();
    }
  }
  else if(cmd == "pop_back") {
    if(dq.empty())
      cout << -1 << '\n';
    else {
      cout << dq.back() <<'\n';
      dq.pop_back();
    }
  }
  else if(cmd == "size")
    cout << dq.size() << '\n';
  else if(cmd == "empty")
    cout << dq.empty() << '\n';
  else if(cmd =="front") {
    if(dq.empty())
      cout << -1 << '\n';
    else
      cout << dq.front() << '\n';
  }
  else if(cmd =="back") {
    if(dq.empty())
      cout << -1 << '\n';
    else
      cout << dq.back() << '\n';
  }
}
```

<br />

### 문자열 [↑](#contents)

#### 아스키코드 [↑](#contents)

- 문자 인코딩 방법이고, 외울 필요는 없다.

> 대표적인 아스키 코드
>
> - `0` → 48
> - `A` → 65
> - `a` → 97
> - `NULL` → 0

- 숫자가 저장되어 있는데, 출력을 글자로 해주는 것으로 이해하면 편하다.

```c++
printf("%c", 65);
printf("%c", 48);
// result: A0
```

- 다른 문자열 관련 내용은 STL 강의의 [문자열]([https://github.com/cyc1am3n/Problem_Solving/blob/master/Lecture%20Note/C%20_C%2B%2B_STL/lec05-string.md](https://github.com/cyc1am3n/Problem_Solving/blob/master/Lecture Note/C _C%2B%2B_STL/lec05-string.md)) 을 참고하자.

#### 예제 1 - ROT13 [↑](#contents)

- 링크: https://www.acmicpc.net/problem/11655
- ROT13으로 암호하는 프로그램을 만드는 문제

```c++
for (auto x : s) {
  if (isupper(x)) cout << char('A' + (x - 'A' + 13) % ('Z' - 'A' + 1));
  else if (islower(x)) cout << char('a' + (x - 'a' + 13) % ('z' - 'a' + 1));
  else cout << x;
}
```

#### 예제 2 - 접미사 배열 [↑](#contents)

- 링크: https://www.acmicpc.net/problem/11656
- 접미사 배열은 문자열 S의 모든 접미사를 사전순으로 정렬해 놓은 배열이다.
- **baekjoon**의 접미사는 backjoon, ackjoon, ckjoon, kjoon, joon, oon, on, n 으로 총 8가지가 있고,  
  이를 사전순으로 정렬하면, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon 이 된다.
- 문자열의 부분 문자열은 **substr**를 이용해서 구할 수 있다.

```c++
vector<string> v;
for (int i = 0; i < s.length(); i++) {
  v.push_back(s.substr(i));
}
sort(v.begin(), v.end());
```

