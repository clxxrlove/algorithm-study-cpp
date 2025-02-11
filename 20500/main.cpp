//
//  main.cpp
//  20500
//
//  Created by 정지용 on 2/11/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MOD = 1e9 + 7;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    int n; cin >> n;
    
    vvi dp(n + 1, vi(3, 0));
    dp[1][2] = 1;
    
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }
    
    cout << dp[n][0];
    
    return 0;
}
