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
### 2309 일곱 난쟁이( 미완 )
```cpp
#include <bits/stdc++.h>
using namespace std;
int a[9];

void printV(vector<int> v) {
    for ( int i : v ) cout << i << "\n";
}

void combi(int start , vector<int> b) {
    if ( b.size() == 7 ) {
        int sum = accumulate(b.begin(), b.end() , 0);
        if ( sum == 100 ) {
            printV(b);
            exit(0);
        }
        for ( int i = start+1 ; i < 9 ; i++ ) {
            b.push_back(a[i]);
            combi(i,b);
            b.pop_back();
        }
        return;
    }
}

int main() {
    for ( int i = 0 ; i < 9 ; i++ ) cin >> a[i];
    sort(a,a+9);
    vector<int> v;
    combi(-1,v);
    return 0;
}
```
