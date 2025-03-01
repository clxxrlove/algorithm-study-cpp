//
//  main.cpp
//  21923
//
//  Created by 정지용 on 3/1/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MINF = -1000000001;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(){
    setDefault();
    
    int n, m; cin >> n >> m;
    
    vvi grid(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { cin >> grid[i][j];
        }
    }
    
    vvi dp0(n, vi(m, MINF));
    
    dp0[n - 1][0] = grid[n - 1][0];
    
    for (int i = n - 2; i >= 0; i--) {
        dp0[i][0] = dp0[i + 1][0] + grid[i][0];
    }
    
    for (int j = 1; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            int best = MINF;
            best = max(best, dp0[i][j - 1]);
            if (i + 1 < n)
                best = max(best, dp0[i + 1][j]);
            dp0[i][j] = best + grid[i][j];
        }
    }
    
    vvi dp1(n, vi(m, MINF));
    
    dp1[0][0] = dp0[0][0] + grid[0][0];
    for (int i = 1; i < n; i++) {
        dp1[i][0] = max(dp1[i - 1][0], dp0[i][0]) + grid[i][0];
    }
    
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int best = MINF;
            best = max(best, dp1[i][j - 1]);
            if (i - 1 >= 0)
                best = max(best, dp1[i - 1][j]);
            best = max(best, dp0[i][j]);
            dp1[i][j] = best + grid[i][j];
        }
    }
    
    cout << dp1[n - 1][m - 1] << "\n";
    
    return 0;
}
