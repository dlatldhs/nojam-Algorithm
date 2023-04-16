# beakjoon 
백준 문제

## 실버
-------
### 10773 제로
```cpp
#include <bits/stdc++.h>
using namespace std;
int n , m , k,sum;
vector<int> v;
   
int main () {
    cin.clear();
    cin >> n ;
    for ( int i=0;i<n;i++ ) {
        cin >> m;
        if ( m == 0 && v.size() != 0 ) {
            v.pop_back();
        } else if ( m != 0 ) {
            v.push_back(m);
        }
    }
    
    for ( auto it : v ) sum += it;
    cout << sum;
    
    return 0;
}
```
---

## 브론즈
---
### 1159
```cpp
#include <bits/stdc++.h>
using namespace std;
int N, ret;
string s;
map<char, int> mp;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
  // 1. N입력을 받는다.
  cin >> N;
  cin.ignore(); // 입력 버퍼에 남아있는 개행 문자 제거

  // 2. N 만큼 for문을 돌면서 선수 이름을 입력받는다.
  for (int i = 0; i < N; i++) { // 0 ~ 17
    getline(cin, s);
    char ch = s[0];
    mp[ch]++;
  }

  // 4. ret[] 배열을 돌면서 5 이상이 있으면 출력 만약 다 없다면 PREDAJA 를
  for (auto it : mp) {
    // cout << it.first << it.second;
    if (it.second >= 5) {
      cout << it.first; 
      ret++;
    }
  }

  // cout << "ret : " << ret;
  if (ret == 0) {
    cout << "PREDAJA";
  }

  // 출력한다.
  return 0;
}
```
### 2309 일곱 난쟁이
```cpp
// variable 선언
#include <bits/stdc++.h>
using namespace std;
int a[13];
int n = 9 , k = 7 , sum ;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// int tpye의 9개 배열 입력 받기
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> a[i];
    }
// sort 오름차순 정렬
    sort(a,a+9,less<int>());
    
// combination or permutation
    do {
        sum = 0 ;
        for ( int i = 0 ; i < k ; i++ ) {
            sum += a[i];
        }
        // 종료 조건
        if ( sum == 100 ) break;
    } while ( next_permutation(&a[0],&a[9]) );
// printAll
    
    for ( int i = 0 ; i < k ; i++ ) {
        cout << a[i] << "\n";
    }
    return 0;
}
```
### 2979
```cpp
#include <bits/stdc++.h>
using namespace std;
int a, b, c, x, y, sum, ret[104], n = 3,m=100;
/*
예제 입력
5 3 1
1 6
3 5
2 8
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> a >> b >> c;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    for (int k = x; k < y; k++) {
      ret[k]++;
      x++;
    }
  }
  for (int i = 1; i < m; i++) {
    if ( ret[i] == 1 ) {
      sum += a;
    }
    else if ( ret[i] == 2 ) {
      sum += b*2;
    }
    else if ( ret[i] == 3 ) {
      sum += c*3;
    }
  }
  cout << sum;
  return 0;
}
```
### 10808
```cpp
#include <bits/stdc++.h>
using namespace std;
string s;
int ret[30],n=26;
int main () {
    
    // 1. 문자열을 입력받는다.(한줄)
    ios_base::sync_with_stdio(false); cin.tie(NULL) ; cin.tie(NULL) ;
    cin.clear();
    getline(cin,s);
    
    // 2. 알파벳 배열 만들기
    for ( char ch : s ) {
        ret[ch-'a']++;
    }
    
    // 3. 출력 형태 맞춰 출력하기
    cout << ret[0];
    for ( int i = 1 ; i < n ; i++ ) {
        cout << " " << ret[i];
    }
    
    return 0;
}
```
### 10988
```cpp
#include <bits/stdc++.h>
using namespace std;
string s , temp;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin.clear();
  getline(cin,s);
  temp = s;
  reverse(temp.begin() , temp.end() );
  if ( temp == s ) cout << 1;
  else cout << 0;
  return 0;
}
```
