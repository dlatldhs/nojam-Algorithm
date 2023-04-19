# beakjoon 
백준 문제

## 실버
-------
### 1620번: 나는야 포켓몬 마스터 이다솜
```cpp
#include <bits/stdc++.h>
using namespace std;
int n ,m;
string s;
map<string,int> mp;
string a[100004];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for ( int i = 1 ; i <= n ; i++ ) {
    cin >> s;
    mp[s] = i; // mp.insert({s,i}); 이거 둘이 같은 의미인거 기억
    a[i] = s;
  }
  for (int i = 0 ; i< m; i++ ) {
    cin >> s;
    if ( atoi(s.c_str()) ) {
      cout << a[atoi(s.c_str())] << "\n";
    } else {
      cout << mp[s] << "\n";
    }
  }
  return 0;
}
```
### 2559
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n , k , temp , psum[100001] , maxed = -10000004;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> k;
	for ( int i = 0 ; i < n ; i++ ) {
		cin >> temp;
		psum[i] = psum[i-1] + temp;
	}

	for ( int i = k; i <= n; i++ ) {
		maxed = max( maxed , psum[i]-psum[i-k] );
		cout << maxed << psum[i] << psum[i-k] << "\n"; 
	}
	cout << maxed << "\n";
	
	return 0;
}
```
> 부가 설명 : `max(maxed , psum[i] - psum[i-k] )` 이렇게 코드가 작성되는 이유는 5번 만큼의 누적합을 구하기 위해서이다. i가 k 즉 얼마만큼의 누적합을 구할 것인가를 나타내는 변수인데 이거를 i 시작에 넣음으로써 맨 처음에는 k만큼의 누적합을 보여주게 되고 그 다음부터는 i++ 되면서 i-k 를 하게 되면 1의 누적합 개수를 뺴게 된다. 그러면 점차 하나하나씩 올라가는 구조임을 알 수 가 있다. 그래서 6의 누적합 - 1의 누적합 하면 23456까지 되니까 이런 방식으로 코드를 짠거임

### 9996
```cpp
#include <bits/stdc++.h>
using namespace std;
int n;
string s, ori_s, pre, suf; // 접두사 접미사
int main() {
  cin >> n;
  cin >> ori_s;
  int pos = ori_s.find("*");   // 10
  pre = ori_s.substr(0, pos);  // pos는 포함 X index 0 ~ 9 10개
  suf = ori_s.substr(pos + 1); // 11 부터 싹다
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (pre.size() + suf.size() > s.size()) { // 입력으로 받은 파일 사이즈가 패턴 사이즈 합친 것 보다 작은 경우
      cout << "NE\n";
    } else {
      if (pre == s.substr(0, pre.size()) && // s.substr(0,pre.size()) 는 문자열이 결과값으로 나옴 0부터 pre.size()개 만큼
          suf == s.substr(s.size() - suf.size())) { // 받은 파일 문자열 크기에서 뒤에 패턴 크기만 빼서 뒤에 패턴이 시작되는 index를 구해서 거기서 부터 다 가져오게 해서 체크함
        cout << "DA\n";
      } else {
        cout << "NE\n";
      }
    }
  }
}
```
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
### 11655 ROT13
```cpp
#include <bits/stdc++.h>
using namespace std;
string s,ret;
char rot;
int main() {
  // 1. 문자열인 s를 입력받습니다. 공백 포함 하려면 getline 사용
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  getline(cin,s);
  
  // 2. s의 요소 하나하나를 검사하며 65 ~ 90 안에 들어가거나 97 ~ 122 안에 들어간다면 알파벳 대/소문자 임을 인지하고 +13 해서 ret에 넣는다.
  for ( char it : s ) {
    // a ~ z or A ~ Z
    if ( (65 <= it && 90 >= it) || (97 <= it && 122 >= it)) {
      
      // it 이 대문자안에 있고 , ROT13 했을 때 대문자의 범위보다 크다면 즉 91 이상이라면
      if ( 90 >= it && it+13 > 90 ) {
        // cout << it << " " << it+13 << "\n";
        rot = it-13;
      }
        
      // it 이 소문자안에 있고 , ROT13 했을 때 소문자의 범위보다 크다면 즉 123 이상이라면
      else if (122 >= it && it+13 > 122) {
        rot = it-13;
      }
      
      else { // 더해도 알파벳 범위 안에 있는 단어인 경우
        rot = it+13;
      }
      
      ret.push_back(rot);
      
    } else {// 3. 만약 알파벳 문자열이 아니라면(문자 or 숫자) 걍 넣는다.
      ret.push_back(it);
    }
  }

  // 5. for을 사용하여 ret을 출력한다.
  for ( auto it : ret ) {
    cout << it;
  }

  return 0;
}
```
