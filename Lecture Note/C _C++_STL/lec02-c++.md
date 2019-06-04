# [STL] 2강 강의 노트 - C++

>### Contents
>- [getline](#getline-)
>- [setprecision](#setprecision-)
>- [endl vs '\n'](#endl-vs-n-)
>- [auto](#auto-)
>- [Range-based for](#range-based-for-)
>- [초기화 리스트](#초기화-리스트-)
>- [람다 함수](#람다-함수-)
<br/>

### getline [↑](#contents)

* c 에서는 입출력시 `scanf` / `printf` 를 이용했었는데,

* c++ 에는 `cin` / `cout` 을 사용할 수 있다.

  ```c++
  cin >> x;
  cout << x;
  ```

* 한 줄 전체를 입력받을 때는 `getline` 을 사용하는 것이 편하다.

  ```c++
  getline(cin, s);
  ```

<br />

### setprecision [↑](#contents)

* `setprecision` 을 사용하면 정밀도를 조정할 수 있는데,

* 사용하려면 `#include <iomanip>` 를 선언해줘야한다.

  ```c++
  #include <iomanip>
  #include <iostream>
  using namesapce std;
  int main() {
    double f = 3.14159265358979;
    cout << setprecision(5) << f << '\n';
    cout << setprecision(8) << f << '\n';
    cout << setprecision(10) << f << '\n';
    return 0;
  }
  //Output:
  //3.1416
  //3.1415927
  //3.141692654
  ```

* 해당 자리에서 **반올림**한 결과를 출력시킬 수 있다.

* 반올림 없이 출력하려면 `fixed` 를 사용하면 된다. (소수점 자리가 위와 다르다.)

  ```c++
  #include <iomanip>
  #include <iostream>
  using namesapce std;
  int main() {
    double f = 3.14159265358979;
    cout << fixed << setprecision(5) << f << '\n';
    cout << fixed << setprecision(8) << f << '\n';
    cout << fixed << setprecision(10) << f << '\n';
    return 0;
  }
  //Output:
  //3.14159
  //3.14159265
  //3.1416926536
  ```

<br />

### endl vs '\n' [↑](#contents)

* `endl` 은 줄 바꿈을 출력하고, 스트림을 flush시키는 기능도 포함되어 있기 때문에
* `'\n'` 보다 느리다.

> * `cout << i << endl;` (4272MS)
> * `cout << i << '\n';` (36MS)
> * `print("%d\n", i);` (20MS)
>
> from [N찍기 문제](https://www/acmicpc.net/problem/2741)

<br />

### auto [↑](#contents)

* 컴파일러가 타입을 추론해서 결정한다.

* `auto` 를 사용하려면 변수의 타입을 명확하게 알 수 있어야 한다.

* 아래 코드는 컴파일 에러가 나온다. (변수의 타입을 명확하게 알 수 없음)

  ```c++
  auto a, b;
  cin >> a >> b;
  cout << a + b << '\n';
  ```

* 올바른 코드는 아래와 같다.

  ```c++
  auto a = 0, b = 0;
  cin >> a >> b;
  cout << a + b << '\n';
  ```

* 만약 이 코드 뒤에 `a = "abc"` 나 `b = 3.14` 로 타입을 바꿔줘도 컴파일 에러가 발생한다.

* 한편 `auto` 는 이터레이터를 사용할 때 매우 편리한데,

  ```c++
  map<pair<int,int>, vector<pair<int,string>>> d;
  for (map<pair<int,int>, vector<pair<int,string>>>::iterator it = d.begin(); it != d.end(); ++it) {
  }
  ```

  이런 코드를

  ```c++
  map<pair<int,int>, vector<pair<int,string>>> d;
  for (auto it = d.begin(); it != d.end(); ++it) {
  }
  ```

  이렇게 줄일 수 있다.

<br />

### Range-based for [↑](#contents)

* **range-based for** 를 사용하면 빠르고 간단한 코드를 작성할 수 있다.

  ```c++ 
  vector<int> a = {1, 2, 3, 4, 5} // C++11 에서 부터 나온 초기화 리스트
  for (int i=0; i<a.size(); i++) {
    cout << a[1] << ' ';
  }
  cout << '\n';
  ```

  대신에

  ```c++
  vector<int> a = {1, 2, 3, 4, 5}
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
  ```

  를 사용할 수 있다.

* `auto` 와 **range-based for** 를 같이 사용한 예

  ```c++
  int sum = 0;
  for (auto x : {1, 2 ,3 ,4}) {
    sum += x;
  }
  cout << "sum = " << sum << '\n';
  // OUTPUT: 10
  
  int a [] = {1, 2, 3, 4, 5}
  int sum = 0;
  for (auto x : a) {
    sum += x;
  }
  cout << "sum = " << sum << '\n';
  // OUTPUT: 15
  ```

* **문자열**을 `const char`(C Style)에 저장할 때는 `NULL` 문자까지 들어간다는 점을 주의해야 한다.

  ```c++
  const char cstr[] = "string";
  sum = 0;
  for (auto x : cstr) {
    sum += 1;
  }
  cout << "sum = " << sum << '\n';
  //OUTPUT: 7 (string+NULL)
  
  string = "string";
  sum = 0;
  for (auto x : cstr) {
    sum += 1;
  }
  cout << "sum = " << sum << '\n';
  //OUTPUT: 6
  ```

<br />

### 초기화 리스트 [↑](#contents)

* 선언시 초기화 리스트를 사용하면 편리하다. 

  ```c++
  vector<int> a;
  a.push_back(1);
  a.push_back(3);
  a.push_back(7);
  a.push_back(13);
  a.push_back(50);
  // 대신에
  vector<int> a = {1, 3, 7, 13, 50};
  ```

* 구조체를 포함해 **복잡한 타입**에도 초기화 리스트를 사용할 수 있다.

  ```c++
  struct Person {
    string name;
    int age;
  };
  set<int> s = {1, 2, 3, 4, 5};  // set
  map<int, string> m = {{20, "a"}, {10, "hi"}}; // map
  Person p = {"you", 20} // struct, 안에 들어가는 변수 타입만 잘 맞춰주면 된다.
  map<int, vector<pair<int,int>>> m2 = {
    {10, {{1, 2}, {3, 4}}},
    {20, {{5, 6}, {7, 8}, {9, 10}}}
  } // 여러가지 섞인 복잡한 타입
  ```

<br />

### 람다 함수 [↑](#contents)

* 람다 함수도 C++11 에서 나왔고, 이름 없이 사용가능해 "익명 함수"라고 부르기도 한다.

* **`[캡쳐](함수인자){함수 내용}`** 의 구조를 가지고 있다.

  ```c++
  int sum(int x, int y) {
    return x + y;
  }
  cout << sum(1, 2) << '\n';
  
  cout << [](int x, int y) {
    return x + y;
  }(1, 2) << '\n';
  ```

* `auto` 와 같이 사용하면 편리하다.

  ```c++
  auto sum2 = [](int x, int y) {
    return x + y;
  };
  cout << sum2(1, 2) << '\n';
  ```

* `[캡쳐](함수인자){함수 내용}` 에서 캡쳐에 `&`와 `빈 값` 을 넣을 수 있다.

  * `&`는 **참조**이고, 선언하는 시점에서 바깥에 있는 변수를 모두 사용할 수 있다.
    (`&x` 처럼 어떤 변수를 사용할 것인지 적을 수도 있다.)
  * `빈 값`은 **값 복사** 이고 바깥에 있는 변수는 사용할 수 없다.

  ```c++
  int x = 10;
      int y = 20;
  
      auto f = [&x, y]() {
          x += 10;
          //y += 10; // 주석 해제하면 컴파일 에러 발생
      };
  
      cout << "x = " << x << ", y = " << y << '\n'; // x = 10, y = 20
      f();
      cout << "x = " << x << ", y = " << y << '\n'; // x = 20, y = 20
      f();
      cout << "x = " << x << ", y = " << y << '\n'; // x = 30, y = 20
  ```

  * 위 코드에서 주석을 해제하고 싶으면 `auto f = [&x, y]() mutable {` 로 바꾸면 되지만, 실행 결과는 바뀌지 않는다.
  * 캡쳐에 여러 값을 넣으려면 `,` 를 이용하면 된다.

* 람다 함수의 변수 타입은 `#include <functional>` 에 선언되어 있다.

  -> `function<리턴타입(콤마로 구분한 인자의 타입들)>`

  ```c++
  function<void()> print = [] {
  };
  function<void(int)> print2 = [] (int x) {
  };
  function<int(int, int)> sum = [] (int x, int y) {
    return x + y;
  };
  ```

* 람다 함수를 **재귀**적으로 사용하려면 캡쳐에 `&`를 넣어줘야 한다.

  ```c++
  /* 피보나치 수 */
  #include <functional>
  #include <iostream>
  using namespace std;
  int main() {
    int n;
    cin >> n;
    function<int(int)> f = [&](int n) {
      if (n <= 1) return n;
      else return f(n - 1) + f(n - 2);
    };
    cout << f(n) << '\n';
    return 0
  }
  ```

* 람다 함수 여러 개를 `vector`에 넣어서 사용할 수 있다.

  ```c++
  // https://www.acmicpc.net/problem/10869 (사칙연산)
  vector<function<int(int, int)>> d;
  d.push_back([](int x, int y) {
    return x + y;
  });
  d.push_back([](int x, int y) {
    return x + y;
  });
  d.push_back([](int x, int y) {
    return x - y;
  });
  d.push_back([](int x, int y) {
    return x * y;
  });
  d.push_back([](int x, int y) {
    return x / y;
  });
  d.push_back([](int x, int y) {
    return x % y;
  });
  
  for (auto &f : d) {
    cout << f(a, b) << '\n';
  }
  ```

  
