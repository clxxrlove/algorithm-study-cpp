//
//  main.cpp
//  3099
//
//  Created by 정지용 on 3/10/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
const int MAX = 2e9;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    string input; cin >> input;
    vvi dp(input.size() + 1, vi(26, MAX));
    dp[1][input[0] - 65] = 2;
    
    for (int i = 1; i < input.size(); ++i) {
        int curr = input[i] - 65;
        
        for (int ch = 0; ch < 26; ++ch) {
            if (dp[i][ch] == MAX) continue;
            if (curr == ch) {
                dp[i + 1][curr] = min(dp[i + 1][curr], dp[i][curr] + 1);
            } else {
                dp[i + 1][ch] = min(dp[i + 1][ch], dp[i][ch] + 2);
                dp[i + 1][curr] = min(dp[i + 1][curr], dp[i][ch] + 2);
            }
        }
    }
    
    int answer = MAX;
    for (int v: dp[input.size()]) {
        answer = min(v, answer);
    }
    
    cout << answer;
    
    return 0;
}
