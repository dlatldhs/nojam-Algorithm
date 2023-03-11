# 피보나치
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> memo(41, make_pair(0, 0));
pair<int, int> fibo(int n) {
    
    // 조건
    if (n == 0) return make_pair(1, 0);
    if (n == 1) return make_pair(0, 1);
    
    // 0이 아닐 때
    if (memo[n].first != 0 && memo[n].second != 0) {
        return memo[n];
    }

    pair<int, int> p1 = fibo(n - 1);
    pair<int, int> p2 = fibo(n - 2);

    int zero = p1.first + p2.first;
    int one = p1.second + p2.second;

    memo[n] = make_pair(zero, one);

    return memo[n];
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        pair<int, int> ans = fibo(n);
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}
