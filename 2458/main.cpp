//
//  main.cpp
//  2458
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
vvi dp;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    cin >> n >> m;
    dp.resize(n + 1, vi(n + 1, 10));
    
    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        
        dp[start][end] = 1;
    }
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dp[i][k] == 1 && dp[k][j] == 1)
                    dp[i][j] = 1;
            }
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] == 1 || dp[j][i] == 1)
                cnt++;
        }
        if (cnt == n - 1) answer++;
    }
    
    cout << answer << '\n';
    
    return 0;
}
