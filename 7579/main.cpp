//
//  main.cpp
//  7579
//
//  Created by 정지용 on 1/8/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> dp;
    vector<int> value;
    vector<int> weight;
    int n, m, s = 0;
    
    cin >> n >> m;
    value.resize(n + 1);
    weight.resize(n + 1);
    
    for (int i = 1; i <= n; ++i) cin >> value[i];
    for (int i = 1; i <= n; ++i) {
        cin >> weight[i];
        s += weight[i];
    }
    
    dp.resize(n + 1, vector<int>(s + 1));
    
    for (int i = 1; i <= n; ++i) {
        int v2 = value[i], w2 = weight[i];
        for (int w = 0; w <= s; ++w) {
            if (w >= w2) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - w2] + v2);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    for (int i = 0; i <= s; ++i) {
        if (dp[n][i] >= m) {
            cout << i;
            return 0;
        }
    }
    
    return 0;
}
