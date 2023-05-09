# 그래프 연습
### dfs
연습 3
```cpp
/*
조건 : 연결되어있으면 전부 다 오염된다.
맵의 세로길이 N과 가로길이 M이 주어지고 이어서 N*M 의 맵이 주어진다.
다 오염시킬려면 몇 번 해야하는지 출력하라.
1 <= N <= 100
1 <= M <= 100
*/
#include <bits/stdc++.h>
using namespace std;
int n , m , a[104][104] , cnt;
bool visited[104][104];
int dy[] = { -1 , 0 , 1 , 0 };
int dx[] = {  0 , 1 , 0 , -1};
void dfs( int y , int x ) {
    
    if ( visited[y][x] == 1 ) return;
    if ( a[y][x] == 0 ) return;
    a[y][x] = 0 ;
    visited[y][x] = 1;

    cout << y << " : " << x << "\n";
    
    for ( int i = 0 ; i < 4; i++ ) {
        int my = y + dy[i], mx = x + dx[i];
        if ( my < 0 || mx < 0 || my >= n || mx >= n ) continue;
        if ( a[my][mx] == 1 ) {
            dfs(my,mx);
            return;
        }
    }
    cnt++;
    return;
    
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int k = 0 ; k < m ; k++ ) {
            cin >> a[i][k];
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int k = 0 ; k<m ;k++ ) {
            dfs(i,k);
        }
    }
    cout << cnt;
}
```
##### 연습 문제4
```cpp
/*
조건 : 연결되어있으면 전부 다 오염된다.
맵의 세로길이 N과 가로길이 M이 주어지고 이어서 N*M 의 맵이 주어진다.
다 오염시킬려면 몇 번 해야하는지 출력하라.
1 <= N <= 100
1 <= M <= 100
*/
#include <bits/stdc++.h>
using namespace std;
int n , m , a[104][104] , cnt;
bool visited[104][104];
int dy[] = { -1 , 0 , 1 , 0 };
int dx[] = {  0 , 1 , 0 , -1};
void dfs( int y , int x ) {
    visited[y][x] = 1;
    cout << y << " : " << x << "\n";
    for ( int i = 0 ; i < 4; i++ ) {
        int my = y + dy[i], mx = x + dx[i];
        if ( my < 0 || mx < 0 || my >= n || mx >= m ) continue;
        if ( a[my][mx] == 1 && !visited[my][mx]) {
            dfs(my,mx);
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int k = 0 ; k < m ; k++ ) {
            cin >> a[i][k];
        }
    }
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int k = 0 ; k<m ;k++ ) {
            if ( a[i][k] == 1 && !visited[i][k] ) {
                cnt++;
                dfs(i,k);

            }
        }
    }
    cout << cnt;
}
```

### bfs 연습문제
```cpp
#include<bits/stdc++.h>
using namespace std;     
vector<int> adj[100];
int visited[100]; 
int nodeList[] = {10, 12, 14, 16, 18, 20, 22, 24};
void bfs(int here){
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while ( q.size() ) {
        int here = q.front(); q.pop();
        for ( int there : adj[here] ) {
            if (visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }
}
int main(){
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);
    
    adj[12].push_back(18);
    adj[12].push_back(20);


    adj[20].push_back(22);
    adj[20].push_back(24);
    bfs(10);
    for(int i : nodeList){
        cout << i << " : " << visited[i] << '\n';
    }
    cout << "10번으로부터 24번까지 최단거리는 : " << visited[24] - 1 << '\n';
    return 0; 
} 
/*
10 : 1
12 : 2
14 : 2
16 : 2
18 : 3
20 : 3
22 : 4
24 : 4
10번으로부터 24번까지 최단거리는 : 3
*/
```
### bfs 연습 문제2
```cpp
/*
맵의 세로길이 N과 가로길이 M이 주어지고 이어서 N*M 의 맵이 주어진다. 그 다음줄의 승원이의 위치(y,x)와 당근마켓의 위치(y,x)가 주어진다.
맵의 1은 육지, 0은 바다를 가리킨다. 승원이는 상하좌우와 육지로만 갈 수 있다. "한칸" 움질일 때 "당근한개"가 소모된다면
승원이는 당근을 최소 몇개 소모해야 하는지 출력하라.

범위
1 <= N <= 100
1 <= M <= 100

예제 입력
5 5
0 0
4 4
1 0 1 0 1
1 1 1 0 1
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1

예제 출력
9
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100];
int visited[100][100],a[104][104];
int N,M,py,px,cy,cx,ret,ey,ex;
int dy[] = {-1,0,1,0} , dx[] = {0,1,0,-1};
void dfs( int py , int px ) {
    queue<pair<int,int>> q;
    visited[py][px] = 1;
    q.push({py,px});
    while( q.size() ) {
        tie(py,px) = q.front(); q.pop();
        for ( int i = 0 ; i < 4 ; i++ ) {
            int my = py + dy[i] , mx = px + dx[i];
            if ( my < 0 || mx < 0 || my >= N || mx >= M ) continue;
            if ( visited[my][mx] ) continue;
            if ( !a[my][mx] ) continue;
            cout << my << " : " << mx << "\n";
            q.push({my,mx});
            visited[my][mx] = visited[py][px] + 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin >> py >> px;
    cin >> cy >> cx;
    for ( int i=0 ; i<N ; i++ ) {
        for ( int k=0; k<M; k++ ) {
            cin >> a[i][k];
        }
    }
    dfs(py,px);
    cout << visited[cy][cx];
    return 0;
}
```
