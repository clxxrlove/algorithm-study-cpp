//
//  main.cpp
//  2098
//
//  Created by 정지용 on 3/11/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n;
vvi matrix;
vvi dp;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int tsp(int state, int curr) {
    if (state == (1 << n) - 1) {
        int result = matrix[curr][0];
        if (result == 0) return 1e9;
        return result;
    }
    
    if (dp[state][curr] != -1) {
        return dp[state][curr];
    }
    
    dp[state][curr] = 1e9;
    for (int next = 0; next < n; ++next) {
        if ((state & (1 << next)) == 0 && matrix[curr][next] != 0) {
            dp[state][curr] = min(dp[state][curr], matrix[curr][next] + tsp(state | (1 << next), next));
        }
    }
    
    return dp[state][curr];
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    cin >> n;
    
    dp.resize(1 << n, vi(n, -1));
    matrix.resize(n, vi(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> matrix[i][j];
    }
    
    cout << tsp(1 << 0, 0);
    
    return 0;
}
