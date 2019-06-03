# [STL] 3강 강의노트 - STL(1)


>### Contents
>- [pair](#pair)
>- [tuple](#tuple)
>- [tie](#tie)
>- [vector](#vector)
>- [deque](#deque)
>- [list](#list)
<br/>

### STL

* C++에서 사용되는 **STL**은 *Standard Template Library* 의 줄임말로 다음과 같이 이루어져 있다.
  * 알고리즘
  * 컨테이너
  * 함수
  * 이터레이터

<br />


### pair [↑](#contents)

* `pair`를 사용하면 두 자료형을 묶을 수 있는데, 오로지 두 개만 묶을 수 있다.

* 첫 번째 자료는 `first`, 두 번째 자료는 `second` 로 접근할 수 있다.

* `pair` 는 `#include <utility>` 에 있는데, `algorithm`, `vector` 와 같은 헤더파일에서 이미 include 하고 있기 때문에 따로 include하는 경우는 없다.

* `make_pair` 함수를 이용하거나, 생성자를 사용해 만들 수 있다.

  ```c++
  // pair를 선언하는 네 가지 방법
  pair<int, int> p1;														// 초기값은 0이다.
  cout << p1.first << ' ' << p1.second << '\n'; // 0 0
  
  p1 = make_pair(10, 20);
  cout << p1.first << ' ' << p1.second << '\n'; // 10 20
  
  p1 = pair<int, int> (30, 40);
  cout << p1.first << ' ' << p1.second << '\n'; // 30 40
  
  pair<int, int> p2 (50, 60);
  cout << p2.first << ' ' << p2.second << '\n'; //50 60
  ```

* 한편, 다음과 같이 `pair` 안에 `pair` 를 넣을 수도 있다.

  ```c++
  pair<pair<int, int>, pair<int, int>> p =
    make_pair(make_pair(10, 20), make_pair(30, 40));
  
  cout << p.first.first << ' ' << p.first.second << ' ';
  cout << p.second.first << ' ' << p.second.second << ' ';
  // OUTPUT: 10 20 30 40
  ```
  
<br />

### tuple [↑](#contents)

* `tuple` 은 `pair` 와 같지만 여러 개를 묶을 수 있다.

* `pair` 처럼 `.first`, `.second`, .. 를 사용해 접근하는게 아니고 `get`을 사용해서 인덱스로 접근해야 한다.

* `tuple` 은 `#include <tuple>` 에 정의되어 있다.

* `get` 을 사용해 인덱스로 접근할 때는 **변수를 사용할 수 없다**는 것을 주의해야한다.

  ```c++
  tuple<int, int, int> t1 = make_tuple(1, 2, 3);
  
  cout << get<0> (t1) << ' ';
  cout << get<1> (t1) << ' ';
  cout << get<2> (t1) << '\n';
  // OUTPUT: 1 2 3
  
  // <Compile Error>
  /*
  for (int i = 0; i < 3; i++) {
  	cout << get<i> (t1) << ' ';
  }
  */
  ```

<br />

### tie [↑](#contents)

* `tuple` 안에 있는 내용을 변수로 지정할 때 아래처럼 일일히 정의해줄 수 있는데,

  ```c++
  auto t = make_tuple(10 ,20, 30);
  
  int x = get<0>(t);
  int y = get<1>(t);
  int z = get<2>(t);
  
  cout << x << ' ' << y << ' ' << z << '\n';
  // OUTPUT: 10 20 30
  ```

* `tie` 를 사용하면 보다 쉽게 정의할 수 있다.

  ```c++
  x = y = z = 0;
  tie(x, y, z) = t;
  cout << x << ' ' << y << ' ' << z << '\n';
  // OUTPUT: 10 20 30
  ```

* `tie` 는 `pair` 에도 동일하게 사용할 수 있다.

* 변수값을 무시해야 하는 경우에는 `ignore` 를 사용한다.

  ```c++
  auto t = make_tuple(1, 2, 3);
  
  int x, y;
  tie(x, ignore, y) = t;
  
  cout << x << ' ' << y << '\n';
  // OUTPUT: 1 3
  ```

​	<br />

### vector [↑](#contents)

* `vector` 는 길이를 변경할 수 있는 **배열** 이다.

* `#include <vector>` 를 선언하면 사용할 수 있다.

  ```c++
  #include <iostream>
  #include <vector>
  using namespace std;
  int main() {
    vector<int> v1;                 // 길이가 0인 벡터 생성
    vector<int> v2(10);             // 길이가 10인 벡터, 초기값 0
    vector<int> v3(15, 1);          // 길이가 15인 벡터, 초기값 1
    vector<int> v4 ={1, 2, 3, 4, 5};// 초기화 리스트로 벡터 생성
    
    return 0;
  }
  ```

* `vector` 안에 `pair` 와 `vector` 를 비롯한 컨테이너들을 넣을 수도 있다.

  ```c++
  #include <iostream>
  #include <vector>
  using namespace std;
  int main() {
    vector<pair<int, int>> v5;
    vector<pair<int, int>> v6 = {{1, 2}, {3, 4}};
    vector<vector<int>> v7;
    
    int n = 10, m = 20;
    vector<vector<int>> v8(n, vector<int>(m)); // int v8[n][m] 같은 느낌
    
    return 0;
  }
  ```

* `vector` 에 값을 추가할 땐 `push_back`, 제거할 땐 `pop_ back`, 초기화 시킬 땐 `clear`, 크기를 변경할 땐 `resize` 를 사용한다.

  ```c++
  vector <int> a = {1, 2, 3, 4, 5};
  
  // push_back은 제일 뒷 부분에 값을 추가
  a.push_back(6); // [1, 2, 3, 4, 5, 6]
  a.push_back(7); // [1, 2, 3, 4, 5, 6, 7]
  
  // pop_back은 제일 뒷 부분의 값을 제거
  a.pop_back(); // [1, 2, 3, 4, 5, 6]
  a.pop_back(); // [1, 2, 3, 4, 5]
  a.pop_back(); // [1, 2, 3, 4]
  
  // clear는 초기화
  a.clear(); // []
  
  // resize는 크기 변경
  a.resize(5); // [0, 0, 0, 0, 0]
  ```

* `resize` 사용 시 크기가 작아지면 뒤의 값을 삭제하고, 크기가 커지면 0으로 채운다.

  ```c++
  vector <int> a = {1, 2};
  
  a.resize(5); // [1, 2, 0, 0, 0]
  a.resize(3); // [1, 2, 0]
  ```

* `vector` 에는 크기를 반환하는 `size` 와 비어있는지 여부를 반환하는 `empty` 가 있다.

  ```c++
  vector <int> a = {1, 2, 3, 4};
  cout << "size = " << a.size() << '\n';   // size = 4
  
  a.push_back(5);
  cout << "size = " << a.size() << '\n';   // size = 5
  cout << "empty = " << a.empty() << '\n'; // empty = 0 (false)
  
  a.clear();
  cout << "size = " << a.size() << '\n';   // size = 0
  cout << "empty = " << a.empty() << '\n'; // empty = 1 (true)
  ```

* `vector` 값에 접근 할 때는 `.front` 와 `.back` 을 사용할 수 있고, `[]` 에 인덱스 값을 넣어 사용할 수도 있다.

* `tuple` 과는 다르게 인덱스에 **변수를 넣을 수 있다**.

  ```c++
  vector<int> a = {1, 2, 3}; // index: 0 1 2
  cout << "front = " a.front() << '\n';   // front = 1
  cout << "a[1] = " a[1] << '\n';         // a[1] = 2
  cout << "back = " a.back() << '\n';     // back = 3
  
  a.push_back(4);
   
  for(int i=0; i<a.size(); i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  // 1 2 3 4
  ```

* **range-based for** 문을 사용해서도 `vector` 를 가져올 수 있다.

  ```c++
  vector<int> a = {1, 2, 3, 4, 5};
  
  for (int &x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  // 1 2 3 4 5
  ```

* `vector` 에 `iterator` 를 사용해 접근할 수도 있는데, `iterator`는 포인터랑 비슷한 개념이라고 생각하면 된다.

* `.begin()` 이나 `.end()` 를 사용하면 되는데 `.begin` 은 벡터의 제일 첫 번째(왼쪽) 값을 가리키고, `.end` 는 벡터의 제일 마지막(오른쪽) 값의 **다음 메모리**를 가리킨다.

* `iterator` 는 포인터처럼 메모리를 가져오므로 이를 통해 벡터를 가져올 땐 앞에 `*` 를 붙여줘야 한다.

* 포인터에서 쓰는 것처럼 `-`와 `+`등 인덱스에 연산을 사용할 수 있다.

  ```c++
  vector<int> a = {1, 2, 3, 4, 5};
  
  for (vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
    cout << *it << ' ';
  }
  cout << '\n';
  
  for (auto it = a.begin(); it != a.end(); ++it) {
    cout << "a[]" << (it - a.begin()) << "] = " << *it << '\n';
  }
  // OUTPUT:
  // 1 2 3 4 5
  // a[0] = 1
  // a[1] = 2
  // a[2] = 3
  // a[3] = 4
  // a[4] = 5
  ```

* `vector` 에 `pair` 를 삽입할 수도 있으며, `iterator` 를 통해 값을 가져올 땐 `.` 대신 `->` 를 사용해야 한다.(like pointer, `(*it).first` 로 써도 된다.)

  ```c++
  vector<pair<int, int>> a;
  a.emplace_back(1, 2);
  a.push_back({3, 4});
  a.push_back(make_pair(5, 6));
  
  for (auto &x : a) {
    cout << x.first << ' ' << x.second << '\n';
  }
  
  for (auto it = a.begin(); it != a.end(); ++it) {
    cout << it->first <<' ' << it->second << '\n';
  }
  // OUTPUT:
  // 1 2
  // 3 4
  // 5 6
  // 1 2
  // 3 4
  // 5 6
  ```

* `vector` 에 `insert` 를 사용하면 값을 삽입할 수 있다.

  ```c++
  void print(vector<int> &a) {
    for (int x : a) {
      cout << x << ' ';
    }
    cout << '\n';
  } 
  
  vector<int> a = {1, 2, 3};
  print(a);
  // 1 2 3
  
  auto it = a.begin();
  a.insert(it, 4); print(a); // (iterator, 삽입할 값)
  // 4 1 2 3
  
  it = a.begin() + 1;
  a.insert(it, 3, 0); print(a); // (iterator, 갯수, 삽입할 값)
  // 4 0 0 0 1 2 3
  
  it = a.begin() + 2;
  vector <int> b = {10, 20};
  a.insert(it, b.begin(), b.end()); print(a); // (iterator, 삽입할 벡터의 시작점, 끝 점)
  // [begin, end): end는 포함하지 않는 다는 것을 주의
  // 4 0 10 20 0 0 1 2 3
  ```

* `erase` 를 사용하면 값을 삭제할 수 있다.

  ```c++
  vector<int> a = {1, 2, 3, 4, 5};
  print(a);
  // 1 2 3 4 5
  
  a.erase(a.begin() + 2);
  print(a);
  // 1 2 4 5
  
  // [begin, end)
  a.erase(a.begin()+1, a.begin()+3);
  print(a);
  // 1 5
  ```

* 한편, `insert` 와 `erase` 의 시간복잡도는 **O(N)** 이다. (N은 벡터의 크기)

<br />

### deque [↑](#contents)

* `deque` 는 양방향으로 pop과 push가 가능한 큐이다.

* 따라서, `push_back`, `push_front`로 입력이 가능하고,

* `pop_back`, `pop_front`로 삭제가 가능하다.

  ```c++
  deque<int> d;
  
  d.push_back(1); print(d);
  // 1
  d.push_front(2); print(d);
  // 2 1
  d.push_back(3); print(d);
  // 2 1 3
  d.pop_back(); print(d);
  // 2 1
  d.pop_front(); print(d);
  // 1
  ```

<br />

### list [↑](#contents)

* `list` 는 이중 연결 리스트를 의미한다.

* `sort` 와 `reverse` 를 제외한 다른 함수들은 `vector`, `deque` 와 동일하다. (`sort`, `reverse` 는 자체 함수를가짐)

* 이중 연결 리스트이기 때문에 `insert` 와 `erase` 의 시간복잡도는 **O(1)** 이다.

  ```c++
  list<int> l = {2, 1, -5, 4, -3, 6, -7}; print(l);
  // 2 1 -5 4 -3 6 -7
  
  l.sort(); print(l); // default: 작은 순서대로
  // -7 -5 -3 1 2 4 6
  
  l.sort(greater<int>()); print(l);
  // 6 4 2 1 -3 -5 -7
  
  l.sort([](int &u, int &v) {
    return abs(u) < abs(v);
  });
  print(l);
  // 1 2 -3 4 -5 6 -7
  
  l.reverse(); print(l);
  // -7 6 -5 4 -3 2 1
  ```

  
