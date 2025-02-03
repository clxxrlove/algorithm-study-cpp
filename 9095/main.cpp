//
//  main.cpp
//  9095
//
//  Created by 정지용 on 2/3/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
const int MOD = 1e9 + 9;

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int t;
    cin >> t;
    int dp[1'000'001] = {0, };
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for (int i = 4; i <= 1'000'000; ++i) {
        dp[i] = (1LL * dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
    }
    
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    
    return 0;
}
