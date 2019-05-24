# [STL] 6강 강의노트 - algorithm

### count

* `count(begin, end, value)`: `[begin, end)` 에 포함되어 있는 원소 중에서 `value`의 개수를 찾는다.

  ```c++
  vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
  for (int i=1; i<=5; i++) {
    cout << i << "의 개수: " <<count(a.begin(), a.end(), i);
    cout << '\n';
  }
  // 1의 개수: 2
  // 2의 개수: 3
  // 3의 개수: 1
  // 4의 개수: 5
  // 5의 개수: 9
  ```

* `count_if(begin, end, p)`: `[begin, end)` 에 포함되어 있는 원소 중에서 조건 `p` 에 해당하는 것의 개수를 찾는다.

  ```c++
  vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
  int even = count_if(a.begin(), a.end(), [](int x) {
    return x % 2 == 0;
  });
  int odd = count_if(a.begin(), a.end(), [](int x) {
    return x % 2 == 1;
  });
  
  cout << "짝수의 개수: " << even << '\n';
  cout << "홀수의 개수: " << odd << '\n';
  
  // 짝수의 개수: 8
  // 홀수의 개수: 3
  ```

* 시간복잡도는 **O(N)** 이다.

<br />

### find

* `find(begin, end, value)`: `[begin, end)` 에 포함되어 있는 원소 중에서 `value` 의 첫 이터레이터를 반환, 못 찾으면 `end` 를 반환한다.

  ```c++
  vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
  for (int i=1; i<=5; i++) {
    auto it = find(a.begin(), a.end(), i);
    cout << i <<"의 위치: ";
    if (it == a.end()) {
      cout << "찾을 수 없음";
    } else {
      cout << (it-a.begin());
    }
    cout << '\n';
  }
  
  // 1의 위치: 0
  // 2의 위치: 3
  // 3의 위치: 8
  // 4의 위치: 1
  // 5의 위치: 찾을 수 없음
  ```

* `find_if(begin, end, p)`: `[begin, end)` 에 포함되어 있는 원소 중에서 조건 `p` 에 해당하는 것의 첫 이터레이터를 반환, 못 찾으면 `end` 를 반환한다.

  ```c++
  vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
  auto even = find_if(a.begin(), a.end(), [](int x) {
    return x % 2 == 0;
  });
  auto odd = find_if(a.begin(), a.end(), [](int x) {
    return x % 2 == 1;
  });
  
  cout << "첫 번째 짝수: " << (even - a.begin()) << '\n';
  cout << "첫 번째 홀수: " << (odd - a.begin()) << '\n';
  
  // 첫 번째 짝수: 1
  // 첫 번째 홀수: 0
  ```

<br />

### fill

* `fill(begin, end, value)`: `[begin, end)` 을 `value` 로 채운다.

* 시간복잡도는 **O(N)** 이다.

* C String의 `memset` 과도 매우 유사한데, `memset` 을 사용하면 1 Byte 단위로 초기화 되기 때문에 그것 보다 큰 자료형은 0 외의 값으로 초기화할 수 없다.

  ```c++
  vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  fill(a.begin(), a.end(), 0);
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  
  // 1 4 1 2 4 2 4 2 3 4 4 
  // 0 0 0 0 0 0 0 0 0 0 0 
  ```

<br />

### reverse

* `reverse(begin, end)`: `[begin, end)`의 순서를 역순으로 만든다.

* 시간복잡도는 **O(N)**이다.

  ```c++
  vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  reverse(a.begin(), a.end());
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  
  // 1 4 1 2 4 2 4 2 3 4 4 
  // 4 4 3 2 4 2 4 2 1 4 1  
  ```

<br />

### rotate

* `rotate(begin, mid, end)`: `[begin, end)` 를 `mid` 기준 왼쪽으로 회전시킨다.

* `[begin, ..., mid-1, mid, ..., end]` -> `[mid, ..., end, begin, ..., mid-1]`

  ```c++
  void print(vector<int> a) {
    for (int x : a) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  
  vector<int> a = {0, 1, 2, 3, 4, 5};
  for (int i=0; i<a.size(); i++) {
    rotate(a.begin(), a.begin()+1, a.end());
    print(a);
  }
  
  // 0 1 2 3 4 5
  // 2 3 4 5 0 1
  // 3 4 5 0 1 2
  // 4 5 0 1 2 3
  // 5 0 1 2 3 4
  ```

<br />

### swap

* `swap(a, b)`: `a`와 `b`에 들어있던 값을 바꾼다.

  ```c++
  int a = 0, b = 20;
  cout << a << ' ' << b << '\n';
  // 10 20
  swap(a, b);
  cout << a << ' ' << b << '\n';
  // 20 10
  swap(a, b);
  cout << a << ' ' << b << '\n';
  // 10 20
  ```

<br />

### unique

* `unique(begin, end)`: `unique`는 `[begin, end)` 구간에서 **연속되는** 같은 값을 하나를 제외하고 제거한다.

* 실제로 컨테이너의 크기를 줄이거나 제거하지는 않고, 중복을 덮어씌우거나 시프트시키는 방식으로 작동한다. (따라서 제대로 구현하려면 `erase` 를 추가해야 한다.)

* 중복을 제거한 후 `end` 이터레이터를 반환한다.

  ```c++
  vector<int> a = {1, 1, 2, 2, 2, 3, 1, 1, 1, 2, 2, 2, 2};
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  // 1 1 2 2 2 3 1 1 1 2 2 2
  
  auto last = unique(a.begin(), a.end());
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  // 1 2 3 1 2 3 1 1 1 2 2 2 2
  
  for (auto it = a.begin(); it != last; ++it) {
    cout << *it << ' ';
  }
  cout << '\n'
   // 1 2 3 1 2
  ```

* `erase` 를 사용해서 `last`이후로 제거

  ```c++
  vector<int> a = {1, 1, 2, 2, 2, 3, 1, 1, 1, 2, 2, 2, 2};
  
  auto last = unique(a.begin(), a.end());
  a.erase(last, a.end());
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  
  // 1 2 3 1 2
  ```

<br />

### sort

* `sort(begin, end)`: `[begin, end)`를 `<` 기준으로 정렬한다. (default)

  ```c++
  vector<int> a = {5, 3, 2, 1, 4};
  
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  // 5 3 2 1 4
  
  sort(a.begin(), a.end());
  
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  // 1 2 3 4 5
  ```

* `sort(begin, end, cmp)`: `[begin, end)`를 `cmp` 기준으로 정렬한다.

* 비교 함수 `cmp`는 `u`가 `v` 앞에 오는 것이면 `true`이고, 아니면 `false`이다.

* 비교 함수를 만드는 경우에는 3번째 인자로 함수 이름을 넘겨줘야 한다.

  ```c++
  bool cmp(const int &u const int &v) {
    return u > v;
  }
  
  vector<int> a = {5, 3, 2, 1, 4};
  
  // 1. greater<int>()
  sort(a.begin(), a.end(), greater<int>());
  // 2. bool type 함수 지정
  sort(a.begin(), a.end(), cmp);
  // 3. 람다 함수
  sort(a.begin(), a.end(), [](int u, int v) {
    return u > v;
  });
  ```

* 여러 조건을 가지고 `sort` 하는 방법 - (1)

  ```c++
  // from 단어 정렬: https://www.acmicpc.net/problem/1181
  sort(a.begin(), a.end(), [](string u, string v) {
    if (u.size() == v.size()) {
      return u < v;
    } else {
      return u.size() < v.size();
    }
  });
  
  // 더 짧게 줄이기
  sort(a.begin(), a.end(), [](string u, string v) {
    return (u.size() < v.size()) || (u.size() == v.size() && u < v);
  });
  ```

* 여러 조건을 가지고 `sort` 하는 방법 - (2) 

  ```c++
  // from 좌표 정렬하기: https://www.acmicpc.net/problem/11650
  // (x, y)가 여러 개 있을 때, x가 증가하는 순으로, 같으면 y가 증가하는 순서로 정렬하는 문제
  
  // 1. pair 사용하기
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  for (int i=0; i<a.size(); i++) {
    cout << a[i].first << ' ' << a[i].second << '\n';
  }
  
  // 2. struct 구현 - 비교 함수 만들기
  // 이 때, const 와 &를 넣어줘야 한다.
  struct Point {
    int x, y;
  }
  bool cmp(const Point &u, const Point &v) {
    if (u.x < v.x) {
      return true;
    } else if (u.x == v.x) {
      return u.y < v.y;
    }else {
      return false;
    }
  }
  ...
  sort(a.begin(), a.end(), cmp);
  
  // 3. struct 구현 - 연산자 over loading
  // 이 경우에는 sort에 3번째 인자가 필요 없다.
  struct Point {
    int x, y;
    bool operator < (const Point &v) const {
      if (x < v.x) {
        return true;
      } else if (x == v.x) {
        return y < v.y;
      } else {
        return false;
      }
    }
  }
  ...
  sort(a.begin(), a.end());
  ```

<br />

### stable_sort

* 정렬하려는 조건이 같은 경우에 `sort` 를 사용하면 기존 순서가 변경되는 경우가 있다.
* 이 때 순서가 유지되는 정렬 알고리즘을 **Stable Sorting** 이라고 한다.
* `stable_sort(begin, end)`: `[begin, end)` 를 `<` 기준으로 정렬한다.
* `stable_sort(begin, end, cmp)`: `[begin, end)` 를 `cmp` 기준으로 정렬한다.

<br />

### binary_search

* `binary_search(begin, end, value)`: `[begin, end)`에서 `value`를 찾으면 `true`, 못 찾으면 `false`

* 위치 대신 있는지 없는지 유무만 파악할 수 있고, **정렬된 상태**에서 사용해야 한다.

  ```c++
  vector<int> a = {1, 5, 6, 7, 10, 20};
  
  for (int i=1; i<=10; i++) {
    cout << i << ": ";
    cout << binary_search(a.begin(), a.end(), i) << '\n';
  }
  // 1: 1
  // 2: 0
  // 3: 0
  // 4: 0
  // 5: 1
  // 6: 1
  // 7: 1
  // 8: 0
  // 9: 0
  // 10: 1
  ```

- `binary_search(begin, end, value, cmp)`: `[begin, end)`에서 `cmp`를 기준으로 `value`를 찾으면 `true`, 못 찾으면 `false`

<br />

### lower_bound / upper_bound

* `lower_bound(begin, end, value)`: `[begin, end)` 에서 `value`보다 **작지 않은** 첫 번째 이터레이터

* `upper_bound(begin, end, value)`: `[begin, end)` 에서 `value`보다 **큰** 첫 번째 이터레이터

* 모두 `cmp` 를 넣을 수 있다.

* 두 개를 활용해 해당 숫자의 갯수도 구할 수 있다.

  ```c++
  vector<int> a = {1, 3, 4, 5, 7, 7, 8};
  for (int i=1; i<=10; i++) {
    auto l = lower_bound(a.begin(), a.end(), i);
    auto r = upper_bound(a.begin(), a.end(), i);
    
    cout << i << ": ";
    cout << "lower_bound: " << (l-a.begin()) << ' ';
    cout << "upper_bound: " << (r-a.begin()) << '\n';
  }
  // 1: lower_bound: 0 upper_bound: 1
  // 2: lower_bound: 1 upper_bound: 1
  // 3: lower_bound: 1 upper_bound: 2
  // 4: lower_bound: 2 upper_bound: 3
  // 5: lower_bound: 3 upper_bound: 4
  // 6: lower_bound: 4 upper_bound: 4
  // 7: lower_bound: 4 upper_bound: 6
  // 8: lower_bound: 6 upper_bound: 7
  // 9: lower_bound: 7 upper_bound: 7
  // 10: lower_bound: 7 upper_bound: 7
  ```

<br />

### equal_range

* `equal_range(begin, end, value)` , `equal_range(begin, end, value, cmp)`
* `lower_bound`, `upper_bound`를 `pair` 형태로 리턴한다.

<br />

### min / max

* `min(a, b)` / `min(a, b, cmp)` / `min(initializer_list)` / `min(initializer_list, cmp)`

* `max(a, b)` / `max(a, b, cmp)` / `max(initializer_list)` / `max(initializer_list, cmp)`

  ```c++
  cout << min(2, 3) << '\n';
  cout << max(2, 3) <, '\n';
  // 2
  // 3
  
  // 두 가지 넘는 값의 min / max 
  int a = 10, b = 20, c = 30;
  cout << min(min(a, b), c) << '\n';
  cout << min({a, b, c}) << '\n';
  cout << max(max(a, b), c) << '\n';
  cout << max({a, b, c}) << '\n';
  // 10
  // 10
  // 30
  // 30
  ```

* `cmp` 사용하기

  ```c++
  string u = "long string";
  string v = "short";
  
  // 1. string 에서의 < 는 사전 순 배열
  cout << min(u, v) << '\n';
  // 2. 길이 순 배열(비교 함수 직접 만들기)
  cout << min(u, v, [](string u, string v) {
    return u.size() < v.size();
  }); << '\n';
  // long string
  // short
  ```

<br />

### minmax

* `min`과 `max`를 동시에 구할 수 있다.

* `minmax(a, b)` / `minmax(a, b, cmp)` / `minmax(initializer_list)` / `minmax(initializer_list, cmp)`

  ```c++
  // 두 번째로 큰 수 출력하기
  auto p = minmax({a, b, c});
  cout << (a+b+c) - p.first - p.second << '\n';
  ```

<br />

### min_element / max_element

* `[begin, end)`에서 최소/최대값의 이터레이터를 구한다.

* `min_element(begin, end)` / `min_element(begin, end, cmp)`

* `max_element(begin, end)` / `max_element(begin, end, cmp)`

  ```c++
  vector<int> a = {4, 2, 1, 5, 7, 3};
  
  auto it = min_element(a.begin(), a.end());
  cout << "최소: " << *it << ", 위치: " << (it-a.begin()) << '\n';
  // 최소: 1, 위치: 2
  
  it = max_element(a.begin(), a.end());
  cout << "최대: " << *it << ", 위치: " << (it-a.begin()) << '\n';
  // 최대: 7, 위치: 4
  ```

<br />

### minmax_element

* `[begin, end)`에서 최소, 최대값의 이터레이터를 구한다.
* `minmax_element(begin, end)` / `minmax_element(begin, end, cmp)`

<br />

### next_permutation / prev_permutation

* `[begin, end)`를 순열이라고 생각했을 때, 사전 순으로 다음/이전에 오는 순열을 만든다.

* 마지막/처음 순열이면 `false`를 반환한다.

* 주로 `do-while` 문을 사용해 구현한다.

* `next_permutation(begin, end)` / `next_permutation(begin, end, cmp)`

* `prev_permutation(begin, end)` / `prev_permutation(begin, end, cmp)`

  ```c++
  vector<int> a = {3, 1, 2};
  sort(a.begin(), a.end());
  
  do {
    for (int x : a) {
      cout << x << ' ';
    }
    cout << '\n';
  } while(next_permutation(a.begin(), a.end()));
  ```

  