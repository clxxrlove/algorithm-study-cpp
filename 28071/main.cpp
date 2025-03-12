//
//  main.cpp
//  28071
//
//  Created by 정지용 on 3/12/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vi value(n);
    vvi dp(m + 1, vi(k, 0));
    for (int i = 0; i < n; ++i) {
        cin >> value[i];
        dp[1][value[i] % k] = max(dp[1][value[i] % k], value[i]);
    }
    
    for (auto v: value) {
        for (int w = 2; w <= m; ++w) {
            for (int mod = 0; mod < k; ++mod) {
                int next_mod = (mod - v) % k;
                if (next_mod < 0) next_mod += k;
                if (dp[w - 1][next_mod] == 0) continue;
                dp[w][mod] = max(dp[w][mod], dp[w - 1][next_mod] + v);
            }
        }
    }
    
//    for (auto v: value) {
//        for (int w = 1; w <= m; ++w) {
//            dp[w] = max(dp[w], dp[w - 1] + v);
//            if (dp[w] % k == 0) answer = max(answer, dp[w]);
//        }
//        
//        for (auto element: dp) cout << element << ' ';
//        cout << '\n';
//    }
    
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << dp[i][j] << ' ';
        } cout << '\n';
    }
    
    int answer = 0;
    for (int i = 0; i <= m; ++i) {
        answer = max(dp[i][0], answer);
    }
    
    cout << answer;
    
    return 0;
}
