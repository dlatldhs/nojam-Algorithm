# 그래프 연습

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
