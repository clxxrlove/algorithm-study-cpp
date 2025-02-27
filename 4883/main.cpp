//
//  main.cpp
//  4883
//
//  Created by 정지용 on 2/27/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

const int INF = 1e9 + 1;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int test_case = 1;
    
    while (true) {
        int n; cin >> n;
        
        if (n == 0) break;
        
        vi dp(3);
        vi ndp(3);
        for (int i = 0; i < 3; ++i) cin >> dp[i];
        dp[0] = INF;
        dp[2] += dp[1];
        
        for (int _ = 0; _ < n - 1; ++_) {
            for (int i = 0; i < 3; ++i) cin >> ndp[i];
            
            ndp[0] += min(dp[0], dp[1]);
            ndp[1] += min(min(dp[2], ndp[0]), min(dp[0], dp[1]));
            ndp[2] += min(ndp[1], min(dp[1], dp[2]));
            
            dp = ndp;
        }
        
        cout << test_case++ << ". " << dp[1] << "\n";
    }
    
    return 0;
}
