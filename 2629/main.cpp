//
//  main.cpp
//  2629
//
//  Created by 정지용 on 3/14/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vb = vector<bool>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    int n; cin >> n;
    
    int sum = 0;
    vi weight(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
        sum += weight[i];
    }
    
    vb dp(sum * 2 + 1, false);
    dp[sum] = true;
    for (int i = 0; i < n; ++i) {
        vb next_dp(dp);
        for (int j = 0; j <= sum * 2; ++j) {
            if (dp[j]) {
                if (j + weight[i] <= 2 * sum) {
                    next_dp[j + weight[i]] = true;
                }
                if (j - weight[i] >= 0) {
                    next_dp[j - weight[i]] = true;
                }
            }
        }
        dp = next_dp;
    }
    
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int bead; cin >> bead;
        if (bead > sum) cout << "N ";
        else cout << (dp[sum + bead] ? "Y ": "N ");
    }
    
    return 0;
}
