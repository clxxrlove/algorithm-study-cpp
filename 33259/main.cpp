//
//  main.cpp
//  33259
//
//  Created by 정지용 on 3/5/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m; // i, w
    cin >> n >> m;
    
    vi value(n);
    vi weight(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> value[i];
        cin >> weight[i];
    }
    
    vvi dp(n + 1, vi(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = m; w >= 0; --w) {
            if (w >= weight[i - 1]) {
                dp[i][w] = max(dp[i - 1][w - weight[i - 1]] + value[i - 1], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    if (dp[n][m] == 0) {
        cout << -1 << '\n';
    } else {
        vi result;
        int w = m;
        for (int i = n; i > 0; --i) {
            if (dp[i][w] != dp[i - 1][w]) {
                result.push_back(i - 1);
                w -= weight[i - 1];
            }
        }
        
        sort(result.begin(), result.end());
        cout << result.size() << '\n';
        for (int v: result) cout << v + 1 << ' ';
    }
    
    return 0;
}
