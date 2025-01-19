//
//  main.cpp
//  9251
//
//  Created by 정지용 on 1/11/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int calcLCS(const string& l, const string& r) {
    int n = l.size(), m = r.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (l[i - 1] == r[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    
    return dp[n][m];
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    string lhs, rhs;
    cin >> lhs;
    cin >> rhs;
    
    cout << calcLCS(lhs, rhs);
    
    return 0;
}
