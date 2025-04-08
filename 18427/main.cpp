//
//  main.cpp
//  18427
//
//  Created by 정지용 on 4/9/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

const int MOD = 10'007;
int n, m, h;
vvi item;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n >> m >> h;
    cin.ignore();
    
    item.resize(n, vi());
    
    int num; string s;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        stringstream ss(s);
        
        while (ss >> num) {
            item[i].push_back(num);
        }
    }
}

void solution() {
    vvi dp(n + 1, vi(h + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 0; j <= h; ++j) {
            dp[i][j] = dp[i - 1][j];
            
            for (auto& v: item[i - 1]) {
                if (j >= v) {
                    dp[i][j] += dp[i - 1][j - v];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    
    cout << dp[n][h] << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
