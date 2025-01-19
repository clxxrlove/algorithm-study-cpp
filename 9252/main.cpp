//
//  main.cpp
//  9252
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

string calcLCS(const string& l, const string& r) {
    string ans = "";
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
    
    while (n > 0 && m > 0) {
        if (l[n - 1] == r[m - 1]) {
            ans += l[n - 1];
            n--; m--;
        } else if (dp[n - 1][m] > dp[n][m - 1]) {
            n--;
        } else {
            m--;
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    string lhs, rhs, ans;
    cin >> lhs;
    cin >> rhs;
    
    ans = calcLCS(lhs, rhs);
    cout << ans.size() << "\n" << ans;
    
    return 0;
}
