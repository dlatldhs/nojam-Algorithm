# beakjoon 
백준 문제

## 실버
-------
### 2828: 사과 담기 게임
```cpp
#include <bits/stdc++.h>
using namespace std;

// vriables
int N, M, J, K, a;
int apples[25];
int max_l, max_r, ret;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // screen => N, box => M
    cin >> N >> M;

    // how many apple 
    cin >> J;

    for ( int i = 0 ; i < J ; i++ ) {
        cin >> a;
        apples[i] = a-1;
    }

    
    // 바구니 제일 왼쪽 좌표;
    max_l = 0;

    // 바구니 제일 오른쪽 좌표;
    max_r = M-1;
    
    while ( K != J ) {
        
        // 만약 바구니 제일 왼쪽 좌표 <= 사과 좌표 && 사과 좌표 <= 바구니 제일 오른쪽 좌표 라면 ?
        if ( max_l <= apples[K] && apples[K] <= max_r ) {
            // 통과하고 다음사과로 넘어감
            K++;
        }

        // else if 바구니 보다 왼쪽에 있을 때
        else if ( (max_l > apples[K] && apples[K] <= max_r) || ( max_l == max_r && max_l > apples[K] ) ) {

            // 바구니 가동범위 왼쪽으로 이동
            max_l--; max_r--;

            // 이동거리++
            ret++;
        }

        // else if 바구니 보다 오른쪽에 있을 때
        else if ( (max_l <= apples[K] && max_r <= apples[K]) || ( max_l == max_r && max_l < apples[K] ) ) {
            
            // 바구니 가동범위 오른쪽으로 이동
            max_l++; max_r++;
            
            // 이동거리++
            ret++;
        }
    }

    // print 이동거리
    cout << ret << "\n";

    return 0;

}
```

### 18353: 병사 배치하기
```cpp
#include <bits/stdc++.h>
using namespace std;
int N, a;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
    
	reverse(v.begin(), v.end());

	int dp[2000];
	for (int i = 0; i < N; i++)
		dp[i] = 1;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int maxValue = 0;

	for (int i = 0; i < N; i++) {
		maxValue = max(maxValue, dp[i]);
	}
	cout << N - maxValue << "\n";
}
```
### 1992: 쿼드 트리
```cpp
#include <bits/stdc++.h>
using namespace std;
char a[101][101];
string s;
int n;
string quard( int y, int x, int size ) {
    if ( size == 1 ) return string(1,a[y][x]);
    string ret="";
    char b = a[y][x];
    for ( int i = y; i < y+size; i++ ) {
        for ( int j = x; j < x+size; j++ ) {
            if ( b !=a[i][j] ) {
                ret += "(";
                ret += quard(y, x,size/2);
                ret += quard(y,x+size/2,size/2);
                ret += quard(y+size/2,x,size/2);
                ret += quard(y+size/2,x+size/2,size/2);
                ret += ")";
                return ret;
            }
        }
    }
    return string(1,a[y][x]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> s;
        for ( int j = 0 ; j < n ; j++ ) {
            a[i][j] = s[j];
        }
    }
    cout << quard(0,0,n) << "\n";
    return 0;
}
```
### 2583: 영역 구하기
```cpp
#include <bits/stdc++.h>
using namespace std;
const int V = 104;
int N,M,K,ly,lx,ry,rx,cnt,ret,ny,nx;
int a[V][V], visited[V][V];
int dy[] = {-1,0,1,0},dx[] = {0,1,0,-1};
vector<int> v;
void dfs( int y, int x ) {
    cnt++;
    visited[y][x] = 1;
    for ( int i = 0 ; i < 4 ; i++ ) {
        ny = y + dy[i]; nx = x + dx[i];
        if ( ny < 0 || nx < 0 || ny >= M || nx >=N ) continue;
        if ( visited[ny][nx] ) continue;
        if ( a[ny][nx] ) continue;
        dfs(ny,nx);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> K;
    while (K--) {
        cin >> ly >> lx >> ry >> rx;
        for ( int i = lx, p1=(rx-lx);p1;i++,p1-- ) {
            for ( int j = ly, p2=(ry-ly);p2;j++,p2--) {
                a[i][j] = 1;
            }
        }
    }

    for ( int i = 0; i<M; i++ ) {
        for ( int j = 0; j<N; j++ ) {
            if ( a[i][j] == 0 && !visited[i][j] ) {
                dfs(i,j);
                v.push_back(cnt);
                ret++;
                cnt=0;
            }
        }
    }
    cout << ret << "\n";
    sort(v.begin(),v.end());
    for ( int i = 0 ; i < ret; i++ ) {
        if ( i == 0 ) cout << v[i];
        else cout << " " << v[i];
    }
}
```
### 2468: 안전 영역
```cpp
#include <bits/stdc++.h>
using namespace std;
const int V = 104;
int visited[V][V], a[V][V],N,i,cnt,ny,nx,dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1},sm=-1,p=1;
void dfs(int y , int x, int rain) {
    visited[y][x] = 1;
    for ( int i = 0 ; i < 4 ; i++ ) {
        ny = y + dy[i]; nx = x + dx[i];
        if ( ny < 0 || nx < 0 || ny >= N || nx >= N ) continue;
        if ( visited[ny][nx] ) continue;
        if ( a[ny][nx] <= rain ) continue;
        dfs(ny,nx,rain);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for ( int i = 0 ; i < N ; i++ ) {
        for (int k = 0; k < N; k++ ) {
            cin >> a[i][k];
        }
    }
    
    for ( int rain=0; rain <=100; rain++ ) {
        cnt = 0;
        for ( int i = 0 ; i < N; i++ ) {
            for ( int k = 0 ; k< N; k++ ) {
                if ( !visited[i][k] && a[i][k] > rain ) {
                    dfs(i,k,rain);
                    cnt++;
                }
            }
        }
        if (cnt > sm) {
            sm = cnt;
        }
        memset(visited,0,sizeof(visited));
    }
    cout << sm;
}
```
### 1012: 유기농 배추
```cpp
#include <bits/stdc++.h>
using namespace std;
int T,M,N,K,b1,b2;
const int P = 54;
int visited[P][P], a[P][P], dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1}, cnt;
void dfs( int by , int bx ) {

    visited[by][bx]=1;
    
    for ( int i = 0 ; i < 4 ; i++ ) {
        int py = by + dy[i];
        int px = bx + dx[i];
        if ( py < 0 || px < 0 || py >= M || px >= N ) continue;
        if ( a[py][px] == 0 ) continue;
        if ( visited[py][px] ) continue;
        dfs(py,px);
    }
    return;
}
int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T; // 테스트 케이스 갯수
    while (T--) {
        cin >> M >> N >> K; // 가로 세로 배추 심을 갯수
        cnt = 0;
        for ( int i = 0 ; i < K ; i++ ) {
            cin >> b1 >> b2;
            a[b1][b2] = 1;
        }
        
        // connect compoents 갯수 출력
        for ( int i = 0 ; i < M; i++ ) {
            for ( int k = 0 ; k < N; k++ ) {
                if ( a[i][k] && !visited[i][k] ) {
                    cnt++;
                    dfs(i,k);
                }
            }
        }
        cout << cnt << "\n";
        
        // map 초기화 visited 초기화 하기!!!
        memset(a,0,sizeof(a));
        memset(visited,0,sizeof(visited));
    }
    return 0;
}
```
### 1213: 팰린드롬 만들기
```cpp
#include <bits/stdc++.h> 
using namespace std;
string s;
int ary[30],fa,last;
vector<char> v2;
int main() {
// 1. 문자열 s 를 입력받음
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> s;
  for (int i=0; s[i] != NULL; i++ ) {
  // 2. ary에 문자열 알파벳 개수를 
    // cout << i;
    int alpa = s[i]-'A';
    ary[alpa]++;
  }
  // 3. for 문을 돌면서 2개 인지 확인 -> 짝수인지 , 만약 홀수 인 것이 있다면 cnt++;
  for ( int i = 0 ; i < 26 ; i++ ) {
    if ( ary[i] == 0 ) { continue; }
    else {
      if ( ary[i]%2 == 0 ) { // 짝수
        for ( int k = 0 ; k < ary[i]/2 ; k++ ) v2.push_back(char(i+'A'));
        // 5. 아니라면 A부터 알파벳 카운트 값을 /2 한 결과 만큼 출력을 한다.그리고 마지막에 홀수 출력 
      } 
    
      else { // 홀수
        fa++;
        last=i;
        for (int k = 0 ; k < ary[i]/2 ; k++ ) v2.push_back( char(i+'A') );
      }
    }
  }
  // 4. cnt가 2가 된다면 "I'm Sorry Hansoo" 출력 
  if ( fa >= 2 ) {
    cout << "I'm Sorry Hansoo";
    return 0;
  }
  // 6. 이걸reverse() 함수를 써서 출력 함
  
  if (s.size() %2 == 1 ) { // 홀수라면
    v2.push_back( char(last+'A') );
    for ( auto it : v2 ) cout << it;
    v2.pop_back();
  } else {
    for ( auto it : v2 ) cout << it;
  }
  reverse( v2.begin() , v2.end() );
  for ( auto it : v2 ) cout << it;
  return 0;
}
```
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
### 1629: 곱셈
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A , B , C,na,ret;
ll go( ll A , ll B ) {
  if ( B == 1 ) return A%C;
  ret = go(A,B/2);
  ret = (ret*ret)%C;
  if ( B%2 ) ret = (ret*A)%C;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> A >> B >> C;
  na = go(A,B);
  cout << na;
}
```
### 2178 미로 탐색
```cpp
#include <bits/stdc++.h>
using namespace std;
int visited[104][104];
int N,M,dy[]={-1,0,1,0},dx[]={0,1,0,-1},a[104][104];
string s;
void bfs(int y,int x) {
    // cout << "bfs!!!";
    queue<pair<int,int>> q;
    visited[y][x]=1;
    q.push({y,x});
    while ( q.size() ) {
        tie(y,x) = q.front(); q.pop();
        for ( int i = 0 ; i < 4 ; i++ ) {
            int ty = y+dy[i], tx = x+dx[i];
            if ( ty < 0 || tx < 0 || ty >= N || tx >= M ) continue;
            if ( visited[ty][tx] ) continue;
            if ( !a[ty][tx] ) continue;
            q.push({ty,tx});
            visited[ty][tx] = visited[y][x] + 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin.ignore();
    for ( int i=0; i<N; i++ ) {
        getline(cin,s);
        int k = 0;
        for ( char ch : s ) {
            a[i][k] = ch-'0';
            k++;
        }
    }

    bfs(0,0);
    cout << visited[N-1][M-1];
    return 0;

}
```
### 1940: 주몽
```cpp
#include <bits/stdc++.h>
using namespace std;
int n, m, tmp, cnt, sum, k = 2;
int ary[15004];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cin >> m;
  for (int i = 0; i < n; i++) {
    cin >> ary[i];
  }

  for ( int i = 0 ; i < n ; i++ ) {
    for ( int k = i+1 ; k < n ; k++ ) {
      if ( ary[i]+ary[k] == m ) {
        cnt++;
      }
    }
  }
  
  cout << cnt;
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
### 3986: 좋은 단어
```cpp
#include <bits/stdc++.h>
using namespace std;
int n, cnt;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    stack<char> stk;
    for (char it : s) {
      if (stk.size() > 0 && // 여기 이거 안하면 참조 에러 뜸 값이 없는 것을 불러와서 
          it == stk.top()) // 사이즈가 없는 것을 체크해서 예외 처리 
        stk.pop();
      else
        stk.push(it);
    }
    if (stk.size() == 0) {
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}
```
### 4375: 1
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int cnt;
ll sum, simp;
int i, n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin>>n) {
    simp = 1;
    cnt = 1;
    while (1) {
      if (simp % n == 0) { // 111111111 == n;
        cout << cnt << "\n";
        break;
      } else { // 11111111111 != n;
        simp = (simp * 10) + 1;
        simp %= n;
        cnt++;
      }
    }
  }
  return 0;
}
```

### 9375: 패션왕 신해빈
```cpp
#include <bits/stdc++.h>
using namespace std;
int n , m;
string s1,s2;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // 입력 받기(testcase)
  cin >> n;

  while(n--) { // testcase 수 만큼 반복
    map<string,int> _mp;

    // 옷의 개수 입력받기
    cin >> m;
    for (int i = 0 ; i<m; i++) {
      // s1: 옷 이름 , s2: 옷 종류
      cin >> s1 >> s2;
      // 옷 이름 필요 X , 옷 종류만 cnt;
      _mp[s2]++;
    }

    // 경우의 수 계산
    long long sum =1; // * 할 때 0이면 값이 안들감

    // 모든 경우의 수 계산 종류 * 종류
    for (auto it : _mp ) {
      sum *= ((long long)it.second +1 ); // 종류마다 하나씩 가능 -> 각 종류수 + 그 종류를 입지 않을 경우 1
    }

    // 아무것도 입지 않을 경우의 수 제거
    sum--;

    cout << sum << "\n";
  }
  return 0;
}
```
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
### 27961: 고양이는 많을수록 좋다
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n;
int cnt, p = 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  // if (n == 0) {
  //   cout << 0;
  //   return 0;
  // }
  // while (1) {
  //   if (n == 1) {
  //     cout << cnt + 1;
  //     break;
  //   }
  //   n /= 2;
  //   if (n % 2 == 1 && n != 1) {
  //     n += 1;
  //   }
  //   cnt++;
  // }
  while ( n > 3 ) {
    cnt++;
    if (n%2==1) {
      n=n/2+1;
    }
    else {
      n/=2;
    }
  }
  cout << cnt+n;
  return 0;
}
```
