//
//  main.cpp
//  11051
//
//  Created by 정지용 on 4/15/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

const ll MOD = 10'007;
ll n, k;
vvl dp;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n >> k;
    dp.resize(n + 1, vl(k + 1, 0));
}

ll solution(ll n, ll k) {
    if (dp[n][k] > 0) return dp[n][k];
    if (n == k || k == 0) return dp[n][k] = 1;
    return dp[n][k] = (solution(n - 1, k) + solution(n - 1, k - 1)) % MOD;
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    cout << solution(n, k) << '\n';
    
    return 0;
}
