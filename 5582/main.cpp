//
//  main.cpp
//  5582
//
//  Created by 정지용 on 3/7/25.
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
    
    string lhs, rhs;
    cin >> lhs >> rhs;
    
    int answer = 0;
    vvi dp(lhs.size() + 1, vi(rhs.size() + 1, 0));
    for (int i = 1; i <= lhs.size(); ++i) {
        for (int j = 1; j <= rhs.size(); ++j) {
            if (lhs[i - 1] == rhs[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }
    
    cout << answer;
    
    return 0;
}
