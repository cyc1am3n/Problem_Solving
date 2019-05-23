# [STL] 5강 강의 노트 - string

* `string`은 C++ 에서 사용하는 문자열 자료형이다.

* C style을 `string`에 대입해도 사용가능하다.

  ```c++
  string s1;
  
  char c[] = "c string"; // C style
  string s2(c);  // c string
  string s3 = c; // c string
  
  c[1] = '\0'; // 1번째에 NULL 문자 삽입. 그 뒤로는 인식 못 함
  
  string s4(c);  // c
  string s5 = c; // c
  
  string s6(10, !);      // !!!!!!!!!! (!가 10개)
  string s7 = "abcdefg"; // abcdefg (제일 많이 사용하는 방법)
  ```

* `string`끼리 덧셈을 하면 문자열이 합쳐진다.

  ```c++
  string s1, s2;
  cin >> s1 >> s2;
  cout << s1 << ' ' << s2;
  ```

* `scanf`처럼 `while` 안에 `cin`을 넣어 사용할 수 있다. (문자열에만 해당되는 건 아님)

  ```c++
  int count = 0;
  string s;
  
  while (cin >> s) {
          count += 1;
  }
  ```

* `getline`을 사용하면 한 줄 전체를 입력받을 수 있고, 이 또한 `while`에 넣을 수 있다.

  ```c++
  // from 문자열 분석: https://www.acmicpc.net/problem/10820
  string s;
  while (getline(cin, s)) {
    int lower = 0;
    int upper = 0;
    int number = 0;
    int space = 0;
    for (char x: s) { // Range-based for (한 글자씩 읽는다)
      if (x >= 'a' && x <= 'z') {
        lower += 1;
      } else if (x >= 'A' && x <= 'Z') {
        upper += 1;
      } else if (x >= '0' && x <= '9') {
        number += 1;
      } else if (x == ' ') {
        space += 1;
      }
    }
  }
  ```

* `getline`의 세 번째 인자는 구분자이다.

  ```c++
  // from 정수의 개수: https://www.acmicpc.net/problem/10821
  string s;
  int cnt = 0;
  while (getline(cin, s, ',')) {
    cnt += 1;
  }
  ```

* `string`을 `printf`로 출력하려면 `.c_str()`를 사용하면 된다.

  ```c++
  string s = "abc";
  printf("%s\n", s.c_str());
  
  s += "def";
  printf("%s\n", s.c_str());
  
  s = "";
  printf("%s\n", s.c_str());
  
  s = "abcdefghijklmnopqrstuvwxyz";
  printf("%s\n", s.c_str());
  ```

* 문자열의 길이를 구할 때는 다른 컨테이너처럼 `size`를 사용해도 되고, `length`를 사용해도 된다.(`length`가 의미적으로 더 맞긴 하다.)

* `size`의 타입은 *Unsigned Int* 인 점을 주의해야한다.

  ```c++
  string s = "book";
  cout << s << ": " << s.size() << '\n';
  cout << s << ": " << s.length() << '\n';
  // book: 4
  // book: 4
  
  s = "";
  cout << s << ": " << s.size() << '\n';
  cout << s << ": " << s.size()-1 << '\n';
  // : 0
  // : 18446744073709551615 (16-bit 환경)
  ```

* `empty`를 사용하면 `size`가 0일 때는 1(true), 그 외에는 0(false)를 반환한다.

  ```c++
  string s = "book";
  cout << s << ": " << s.empty() << '\n';
  // book: 0
  
  s = "";
  cout << s << ": " << s.empty() << '\n';
  // : 1
  ```

* `string`에는 비교 연산자도 사용가능하다. (`==`, `!=`, `<`, `>`, `<=`, `>=`)

  ```c++
  string s1 = "string";
  string s2 = "string";
  
  if (s1 == s2) {
    cout << "s1 == s2" << '\n';
  } else if (s1 != s2) {
    cout << "s1 != s2" << '\n';
  }
  // s1 == s2
  
  if (s1 < s2) {
    cout << "s1 < s2" << '\n';
  } else if (s1 > s2) {
    cout << "s1 > s2" << '\n';
  }
  // (Nothing happened.)
  ```

* `string`을 합치는 방법 - (1) (`+`, `+=`, `push_back`)

  ```c++
  string a = "Hello";
  string b = "World";
  
  string hello_world = a + " " + b; // 1. +
  hello_world += "!";               // 2. +=
  
  cout << hello_world << '\n';
  // Hello World!
  
  string hello_world2 = a + " " + b;
  hello_world2.push_back('!');      // 3. push_back
  
  cout << hello_world2 << '\n';
  // Hello World!
  
  ```

* `string`을 합치는 방법 - (2) (`append`, `insert`)

  ```c++
  // 4. append
  string c = "He";
  c.append(2, 'l');                // l을 2개 ("Hell")
  c.append("o").append(1, ' ');    // 한 글자 삽입 ("Hello ")
  
  string d = "";
  const char *e = "World";
  d.append(e);                     // C style char* 넣기 ("World")
  
  // 5. insert
  string s = "e";                  // "e"
  s.insert(0, "H");                // 0번 자리에 "H" 삽입, "He"
  s.insert(2, "o");                // 2번 자리에 "o" 삽입, "Heo"
  s.insert(2, 2, 'l');             // 2번 자리에 'ㅣ' 을 2번 삽입, "Hello"
  
  string world = "Half the World Away";
  s.insert(6, world, 8, 6);        // 6번 자리에 world 문자열의 8번 자리부터 6개 문자 삽입, "Hello World"
  ```

* `stoi`를 사용하면 `string`을 `int`로 바꿀 수 있다. (`int`형의 숫자가 안 나올때 까지 가져온다.)

  ```c++
  string str = "21 Guns";
  int number = stoi(str);
  cout << number; // 21
  
  str = "3.141592";
  number = stoi(str);
  cout << number; // 3
  
  // Segmentation Fault Error
  /*
  str = "2147483648"; // int의 max 값을 넘는다.
  number = stoi(str);
  cout << number;
  
  str = "hello";     // int형 숫자가 없다.
  number = stoi(str);
  cout << number;
  */
  ```

* `string`을 **표준 입출력**처럼 사용하려면 `istringstream`을 사용한다. (`#include <sstream>` 필요)

  ```c++
  // from 더하기 2: https://www.acmicpc.net/problem/10823
  string s;
  string line;
  while (cin >> line) {
    s += line;
  }
  
  istringstream sin(s);
  
  string number;
  int sum = 0;
  
  while (getline(sin, number, ',')) {
    sum += stoi(number);
  }
  cout << sum << '\n';
  
  /*
  Input:
  10,20,
  3
  0,50
  ,1
  00
  
  Output: 210
  */
  ```

* `stoi`같은 함수들

  * to unsigned long: `stoul`
  * to unsigned long long: `stoull`
  * to float: `stof`
  * to double: `stod`
  * to long double: `stold`

* `to_string`을 사용해 `string`이 아닌 것을 변환할 수 있다.

  ```c++
  int n = 1;
  string s1 = to_string(n);
  
  long long l = 2147483647;
  s1 = to_string(l);
  
  double d = 3.141592;
  s1 = to_string(d);
  
  float f = 65358979.0;
  s1 = to_string(f);
  ```

  