# [STL] 3강 강의노트 - STL(2)

### set

* `set` 과 `map`은 *Binary Search Tree* 중 *Red Black Tree* 로 구현된 컨테이너이다.

* `set`은 순서가 없고 중복을 허용하지 않는다. (default 오름차순)

* `size()` 로 `set` 의 크기를 구할 수 있다.

  ```c++
  set<int> s1;
  set<int> s2 = {1, 2, 3, 4, 5};
  set<int> s3 = {1, 1, 1, 1, 2, 2, 2, 3, 3};
  
  cout << "s1.size() = " << s1.size() << '\n';
  // s1.size() = 0
  cout << "s1.size() = " << s1.size() << '\n';
  // s2.size() = 5
  cout << "s1.size() = " << s1.size() << '\n';
  // s3.size() = 3
  
  // 내림차순으로 바꾸기
  set<int, greater<int>> s4;
  ```

* `insert()` 를 사용해 `set` 에 값을 넣어 줄 수 있다.

* `insert()` 의 반환 타입은 `pair<set<int>::iterator, bool>` 인데  
  첫 번째 값은 넣어줄 값의 이터레이터이고,  
  두 번째 값은 `insert` 에 성공했는지 여부이다(이미 값이 들어있으면 0(false) 반환).

  ```c++
  set<int> s;
  s.insert(1); s.insert(3); s.insert(2);
  
  cout << "s.size() = " << s.size() << '\n';
  // s.size() = 3
  
  pair<set<int>::iterator, bool> result = s.insert(4);
  cout << "result iterator = " << *result.first << '\n';
  // result iterator = 4
  cout << "result bool = " << result.second << '\n';
  // result bool = 1
  
  auto result2 = s.insert(3);
  cout << "result2 iterator = " << *result2.first << '\n';
  // result2 iterator = 3
  cout << "result2 bool = " << result2.second << '\n';
  // result2 bool = 0
  ```

* 한편, `set` 은 *Binary Search Tree* 로 이루어져 있어서 메모리를 연속적으로 사용하지 않기 때문에 **삽입**과 **삭제** 시 **O(logN)**의 시간이 걸린다.

* `iterator` 연산 시 `++` 나 `--` 를 이용하면 된다. (`it += 1` 은 compile error 발생)

  ```c++
  set<int> s = {1, 2, 3, 4, 5};
  s.erase(s.begin());
  cout << "s.size() = " << s.size() << '\n';
  // s.size() = 4
  
  auto it = s.begin();
  ++it;
  cout << "*it = " << *it << '\n';
  // *it = 3
  it = s.erase(it);
  cout << "*it = " << *it << '\n';
  // *it = 4
  cout << "s.size() = " << s.size() << '\n';
  // s.size() = 3
  ```

* `set`에 있는 값들을 순차적으로 출력할 때는 **O(N logN)** 의 시간이 걸린다. (N번 탐색)

* `.end()` 는 `vector` 와 마찬가지로 마지막 값의 **다음 메모리**를 가리킨다.

  ```c++
  set<int> s = {5, 2, 4, 1, 3, 7, 6};
  
  for (auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << ' ';
  }
  cout << '\n';
  // 1 2 3 4 5 6 7
  
  // 위와 같은 코드(Range-based for)
  for (auto x : s) {
    cout << x << ' ';
  }
  cout << '\n';
  // 1 2 3 4 5 6 7
  ```

* `.find()` 는 해당 값의 이터레이터를 반환한다. (`set<int>::iterator` 타입)

  ```c++
  void print(set<int> &s, set<int>::iterator it) {
    if (it == s.end()) { // 값이 없을 때
      cout << "end\n";
    } else {
      cout << *it << '\n';
    }
  }
  
  set<int> s = {7, 5, 3, 1};
  
  auto it = s.find(1);
  print(s, it);
  // 1
  it = s.find(2);
  print(s, it);
  // end
  it = s.find(3);
  print(s, it);
  // 3
  it = s.find(4);
  print(s, it);
  // end
  ```

* `.count()` 로 `set` 에 해당 값이 있는지 없는지를 알아낼 수 있다. (0 또는 1 반환)

  ```c++
  set<int> s = {4, 1, 3};
  
  for (int i=1; i<=5; i++) {
    cout << "s.count(" << i << ") = " << s.count(i) << '\n';
  }
  // s.count(1) = 1
  // s.count(2) = 0
  // s.count(3) = 1
  // s.count(4) = 1
  // s.count(5) = 0
  ```

* `set` 은 중복을 허용하지 않지만, `multiset` 은 중복을 허용하기 때문에 `.count()` 가 0, 1 이외의 값을 반환할 수 있다.

<br />

### map

* `map` 은 **key** 와 **value** 로 이루어진 컨테이너이고, 배열과 유사하게 접근할 수 있다.

* *Binary Search Tree* 로 구성되어 있어서 역시 접근 시 **O(logN)** 의 시간이 걸린다.

  ```c++
  map<int, int> d1;
  map<int, int> d2 = {{1, 2}, {3, 4}, {5, 6}};
  
  cout << "d1.size() = " << d1.size() << '\n'; // d1.size() = 0
  cout << "d2.size() = " << d2.size() << '\n'; // d2.size() = 3
  
  d1[10] = 20;
  cout << "d1[10] = " << d1[10] << '\n';       // d1[10] = 20
  cout << "d1[1] = " << d1[1] << '\n';         // d1[1] = 2
  cout << "d1[2] = " << d1[2] << '\n';         // d1[2] = 0
  cout << "d1[3] = " << d1[3] << '\n';         // d1[3] = 4
  cout << "d1[4] = " << d1[4] << '\n';         // d1[4] = 0
  cout << "d1[5] = " << d1[5] << '\n';         // d1[5] = 6
  ```

* `map` 에 `d[1]` 과 같이 접근할 때, 자동으로 초기값인 0이 할당되는 점을 주의해야한다. (`.count()` 사용하기)

  ```c++
  map<int, int> d1 = {{1, 1}, {3, 9}, {5, 25}, {7, 49}, {9, 81}};
  map<int, int> d2 = {{1, 1}, {3, 9}, {5, 25}, {7, 49}, {9, 81}};
  
  for (int i=1; i<=10; i++) {
    if (d1[i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';
  // 1 3 5 7 9
  
  for (int i=1; i<=10; i++) {
    if (d2.count(i)) {
      cout << i << ' ';
    }
  }
  cout << '\n';
  // 1 3 5 7 9
  
  cout << "d1.size() = " << d1.size() << '\n'; // d1.size() = 10
  cout << "d2.size() = " << d2.size() << '\n'; // d2.size() = 5
  ```

* `map` 의 이터레이터는 `pair` 형태로 존재하는데, `first` 는 key, `second` 는 value를 가리킨다.

  ```c++
  map<int, int> d = {{1, 2}, {3, 4}, {5, 6}};
  
  for (auto it = d.begin(); it != d.end(); ++it) {
    cout << (it->first) << ' ' << (it->second) << '\n';
  }
  // 1 2
  // 3 4
  // 5 6
  
  for (auto p : d) {
    cout << p.first << ' ' << p.second << '\n';
  }
  // 1 2
  // 3 4
  // 5 6
  ```

<br />

### stack

* `stack`은 자료구조의 스택과 같고, 따로 명시해주지 않으면 `deque`로 구현되어있다.

  ```c++
  stack<int> s1;            // deque으로 구현
  
  stack<int, list<int>> s2; // linked-list로 구현
  
  deque<int> d = {1, 2, 3, 4, 5};
  stack<int> s3(d);
  ```

* `.push`는 삽입, `.pop`은 삭제를 나타내고, `.top`은 가장 위에 있는 값을, `.empty`는 비어있는지 여부를 반환한다.

  ```c++
  stack<int> s;
  
  for (int i=1; i<=5; i++) { // s = {1, 2, 3, 4, 5}
    s.push(i);
  }
  
  for (int i=0; i<2; i++) {
    cout << s.top() << ' ';
    s.pop();
  }
  // 5 4
  
  cout << "size = " << s.size() << '\n';   // size = 3
  cout << "empty = " << s.empty() << '\n'; // empty = 0
  
  while (!s.empty()) {
    cout << s.top() << ' '; // 3 2 1
  }
  
  cout << "size = " << s.size() << '\n';   // size = 0
  cout << "empty = " << s.empty() << '\n'; // empty = 1
  ```

* `stack`에는 `pair`도 넣을 수 있는데, 방향이 하나밖에 없기 때문에 `vector`처럼 `emplace_back`를 사용하는게 아니라 `emplace`를 사용해야 한다.

  ```c++
  stack<pair<int, int>> s;
  s.push(make_pair(1, 2));
  s.push({3, 4});
  s.emplace(5, 6);
  
  while(!s.empty()) {
    auto p = s.top();
    cout << p.first << ' ' << p.second << '\n';
    s.pop();
  }
  // 5 6
  // 3 4
  // 1 2
  ```

<br />

### queue

* `queue`는 `stack`과 선언 방법이 동일하다.

* `.top` 밖에 없는 `stack` 과는 다르게 `.front` 와 `.back` 을 가지고 있다.

  ```c++
  queue<int> q;
  
  for (int i=1; i<=5; i++) { // q = {1, 2, 3, 4, 5}
    q.push(i);
  }
  
  for (int i=0; i<2; i++) {
    cout << q.front() << ' ' << q.back() << '\n';
    q.pop();
  }
  // 1 5
  // 2 5
  
  cout << "size = " << q.size() <, '\n';   // size = 3
  cout << "empty = " << q.empty() << '\n'; // empty = 0
  
  for (int i=6; i<=8; i++) {
    q.push(i);
    cout << "back = " << q.back() << '\n';
  }
  // back = 6
  // back = 7
  // back = 8
  
  while (!q.empty()) {
    cout << q.front() << ' ' << q.back() << '\n';
    q.pop();
  }
  // 3 8
  // 4 8
  // 5 8
  // 6 8
  // 7 8
  // 8 8
  
  cout << "size = " << q.size() <, '\n';   // size = 0
  cout << "empty = " << q.empty() << '\n'; // empty = 1
  ```

* `stack`과 `pair`를 넣는 방법은 동일하다.

  ```c++
  queue<pair<int, int>> q;
  q.push(make_pair(1, 2));
  q.push({3, 4});
  q.emplace(5, 6);
  
  while(!q.empty()) {
    auto p = q.front();
    cout << p.first << ' ' << p.second << '\n';
    q.pop();
  }
  // 1 2
  // 3 4
  // 5 6
  ```

<br />

### priority_queue

* 가중치가 높은 수가 `top` 이 되는 큐이다.

* 따로 지정해주지 않으면 큰 수가 제일 먼저 나온다. (최대 힙)

  ```c++
  vector<int> a ={5, 2, 4, 1, 3};
  
  priority_queue<int> q1;
  
  for (int x : a) {
    q1.push(x);
  }
  
  while (!q1.empty()) {
    cout << q1.top() << ' ';
    q1.pop();
  }
  cout << '\n';
  // 5 4 3 2 1
  ```

* 최소 값을 먼저 나오게 하는 방법 (최소 힙)

  ```c++
  // 1. - 값으로 집어넣고 꺼낼 때 원상복구하기
  priority_queue<int> q2;
  for (int x : a) {
    q2.push(-x);
  }
  
  while (!q2.empty()) {
    cout << -q2.top() << ' ';
    q2.pop();
  }
  cout << '\n';
  // 1 2 3 4 5
  
  // 2. greater<int> 넣어주기
  priority_queue<int, vector<int>, greater<int>> q3;
  for (int x : a) {
    q3.push(x);
  }
  
  while (!q3.empty()) {
    cout << q3.top() << ' ';
    q3.pop();
  }
  cout << '\n';
  // 1 2 3 4 5
  ```

  * 1번 방법을 사용했을 때는 **2^31**(=2147483648)일 때는 `x==-x` 로 인식하기 때문에 주의해야한다.

<br />

### bitset

* `bitset`은 `vector<int>`와 유사하지만 하나에 **1 bit**의 크기를 가진다는 차이가 있다. (`vector<int>`는  1 Byte)

  ```c++
  bitset<8> b1; // 8자리 지정, 기본값 0 - 0,0,0,0,0,0,0,0
  
  bitset<10> b2(88); // 10자리 지정, 88의 2진수 표현 - 0,0,0,1,0,1,1,0,0,0
  
  bitset<8> b3("10110"); // 8자리로 표현한 10110(2진수) - 0,0,0,1,0,1,1,0
  
  for (int i=0; i<b3.size(); i++) {
    cout << i << ": " << b3[i] << '\n';
  }
  // 0: 0
  // 1: 0
  // 2: 0
  // 3: 1
  // 4: 0
  // 5: 1
  // 6: 1
  // 7: 0
  ```

* `bitset`에 접근할 때, 위의 코드처럼 접근할 수도 있고 `test`를 사용할 수도 있다.

* `set`은 해당 자리를 1로 만들고, `reset`은 해당 자리를 0으로 만들며, `flip`은 해당 자리를 반전시킨다.(0->1 / 1->0)

  ```c++
  bitset<10> b(88); // 0,0,0,1,0,1,1,0,0,0
  cout << b << '\n'; // 0001011000
  
  cout << b.test(4) << '\n'; // 1 (b[4]와 같음)
  cout << b.test(5) << '\n'; // 0 (b[5]와 같음)
  
  b.set(0);
  cout << b << '\n'; // 0001011001
  
  b.reset(3);
  cout << b << '\n'; // 0001010001
  
  b.flip(2);
  cout << b << '\n'; // 0001010101
  ```

* `set`, `reset`, `flip`에 인자가 없으면 해당 `bitset`전체에 적용된다.

  ```c++
  bitset<10> b(88); // 0,0,0,1,0,1,1,0,0,0
  
  b.flip();
  cout << b << '\n'; // 1110100111
  
  b.set();
  cout << b << '\n'; // 1111111111
  
  b.reset();
  cout << b << '\n'; // 0000000000
  ```

* `all`은 모든 bit가 1일 때, `none`은 모든 bit가 0일때, `any`는 적어도 1개의 bit가 1일 때 1을 반환한다. (나머지는 0) 

* `count`는 1인 bit의 갯수를 반환한다.

  ```c++
  bitset<10> b(88); // 0,0,0,1,0,1,1,0,0,0
  
  cout << b.all() << '\n'; // 0 (false)
  cout << b.any() << '\n'; // 1 (true)
  cout << b.none() << '\n'; // 0 (false)
  
  cout << b.count() << '\n'; // 3
  ```

* `bitset`은 **2진수 연산**이 가능하다. 

* `&`는 **AND** 연산, `|` 는 **OR** 연산, `^`는 **XOR** 연산, `~`는 **NOT** 연산을 의미한다.

* **shift** 연산도 동일하게 사용가능하다. (`>>`, `<<`)

  ```c++
  bitset<10> b1(88); //0,0,0,1,0,1,1,0,0,0
  bitset<10> b2(47): //0,0,0,0,1,0,1,1,1,1
  
  cout << (b1 & b2) << '\n'; // 0000001000
  cout << (b1 | b2) << '\n'; // 0001111111
  cout << (b1 ^ b2) << '\n'; // 0001110111
  cout << ~(b1) << '\n';     // 1110100111
  
  cout << (b1 << 2) << '\n'; // 0101100000
  cout << (b1 >> 2) << '\n'; // 0000001011
  ```

  