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
