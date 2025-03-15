//
//  main.cpp
//  4781
//
//  Created by 정지용 on 3/15/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using vi = vector<int>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    while (true) {
        int n; double d_m;
        cin >> n >> d_m;
        int m = static_cast<int>(lround(d_m * 100));
        
        if (n == 0 && m == 0) break;
        
        vi dp(m + 1, 0);
        vi weight(n);
        vi value(n);
        for (int i = 0; i < n; ++i) {
            double w;
            cin >> value[i] >> w;
            weight[i] = static_cast<int>(lround(w * 100));
        }
        
        for (int i = 0; i < n; ++i) {
            for (int w = weight[i]; w <= m; ++w) {
                dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
            }
        }
        
        cout << dp[m] << '\n';
    }
    
    return 0;
}
