//
//  main.cpp
//  9084
//
//  Created by 정지용 on 3/9/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n; cin >> n;
    int w;
    
    vi coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];
    cin >> w;
    vi dp(w + 1, 0);
    dp[0] = 1;
    
    for (auto coin: coins) {
        for (int i = coin; i <= w; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    
    cout << dp[w] << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    int t; cin >> t;
    while (t--) solve();
    
    return 0;
}
