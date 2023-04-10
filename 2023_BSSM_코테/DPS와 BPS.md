# DPS와 BPS

## 활동 1
```cpp
#include<bits/stdc++.h>
using namespace std;

void dfs(int start, vector<int> graph[], bool check[]){
	check[start]= true;
	printf("%d ", start);
	
	for(int i=0; i < graph[start].size(); i++){
		int next = graph[start][i];
		// 방문하지 않았다면
		if(check[next]==false){
			// 재귀함수를 호출한다.
			dfs(next, graph, check);
		}
	}
}

void bfs( int start , vector<int> graph[] , bool check[] ) {
	queue<int> q;
	
	q.push(start);
	check[start] = true;
	
	while(!q.empty()) {
		int tmp = q.front();
		q.pop();
		printf("%d ",tmp);
		for ( int i=0;i<graph[tmp].size();i++ ) {
			if ( check[graph[tmp][i]] == false ) {
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}
}
int main (){
	
	// 정점 개수 , 간선 개수 , 탐색 정점 번호
	int n, m, start;
	cin >> n >> m >> start;
	
	// 초기 값 설정 및 변수 선언
	vector<int> graph[n+1];
	vector<int> graph2[n+1];
	bool check [n+1];
	bool check2 [n+1];
	fill(check2, check2+n+1,false);
	fill(check, check+n+1, false);

	// 입력 받기
	for(int i=0; i<m; i++){
		int u,v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	// 나중에 값이 작은 거 부터 해야되서 정렬
	for(int i=1; i<=n; i++){
		sort(graph[i].begin(), graph[i].end());
	}

	//dfs
	dfs(start, graph, check);
	printf("\n");
	bfs(start, graph, check2);
	printf("\n");

	return 0;
	
}
```
