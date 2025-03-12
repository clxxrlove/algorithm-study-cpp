//
//  main.cpp
//  11404
//
//  Created by 정지용 on 3/12/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n, m;
const int INF = 1e9;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    cin >> n >> m;
    
    vvi dp(n + 1, vi(n + 1, INF));
    for (int i = 0; i < m; ++i) {
        int start, end, dist;
        cin >> start >> end >> dist;
        
        dp[start][end] = min(dp[start][end], dist);
    }
    
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dp[i][k] == INF || dp[k][j] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int curr = dp[i][j];
            curr = curr == INF ? 0 : curr;
            cout << curr << ' ';
        } cout << '\n';
    }
    
    return 0;
}
