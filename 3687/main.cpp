//
//  main.cpp
//  3687
//
//  Created by 정지용 on 3/2/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vll = vector<long long>;
using ii = pair<int, int>;
using ll = long long;

const ll MAX = 9e18;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int t; cin >> t;
    ii numerics[6] = {
        {7, 8}, {6, 0}, {5, 2}, {4, 4}, {3, 7}, {2, 1}
    };
    
    while (t--) {
        int n; cin >> n;
        vi upper;
        int lower = 0;
        vll dp(n + 1, MAX);
        
        // upper
        if (n % 2 == 0) {
            upper.push_back(1);
            for (int i = 0; i < (n - 2) / 2; ++i) {
                upper.push_back(1);
            }
        } else {
            upper.push_back(7);
            for (int i = 0; i < (n - 3) / 2; ++i) {
                upper.push_back(1);
            }
        }
        
        dp[0] = 0;
        // lower
        for (int i = 2; i <= n; ++i) {
            for (auto& num: numerics) {
                if (i - num.first < 0) continue;
                if (dp[i - num.first] == MAX) continue;
                ll value = dp[i - num.first] * 10 + num.second;
                if (dp[i - num.first] == 0 && num.second == 0) value = 6;
                dp[i] = min(value, dp[i]);
            }
        }
        
        cout << dp[n] << ' ';
        for (int u: upper) cout << u;
        cout << '\n';
    }
    
    return 0;
}
