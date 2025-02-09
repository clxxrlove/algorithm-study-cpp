//
//  main.cpp
//  17404
//
//  Created by 정지용 on 2/10/25.
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
    
    int n, answer = 1e9;
    cin >> n;
    
    vvi color(n, vi(3, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) cin >> color[i][j];
    }
    
    for (int first = 0; first < 3; ++first) {
        vi dp(3, 1e9);
        dp[first] = color[0][first];
        
        for (int i = 1; i < n; ++i) {
            int r = min(dp[1], dp[2]) + color[i][0];
            int g = min(dp[0], dp[2]) + color[i][1];
            int b = min(dp[0], dp[1]) + color[i][2];
            
            dp[0] = r; dp[1] = g; dp[2] = b;
        }
        
        for (int last = 0; last < 3; ++last) {
            if (first != last) {
                answer = min(answer, dp[last]);
            }
        }
    }
    
    cout << answer;
    
    return 0;
}
