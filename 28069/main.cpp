//
//  main.cpp
//  28069
//
//  Created by 정지용 on 2/16/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using ii = pair<int, int>;

const int MAX = 1'000'001;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void bfs(vi& dp, int n, int k) {
    queue<ii> q;
    q.push({1, 1});
    dp[1] = 1;
    
    while (!q.empty()) {
        int current = q.front().first;
        int step = q.front().second;
        q.pop();
        
        if (step == k) continue;
        
        int next = current + 1;
        int s_next = current + 1 * floor(current / 2);
        
        if (s_next != current && s_next <= n && dp[s_next] > dp[current] + 1) {
            dp[s_next] = dp[current] + 1;
            q.push({s_next, step + 1});
        }
        if (next <= n && dp[next] > dp[current] + 1) {
            dp[next] = dp[current] + 1;
            q.push({next, step + 1});
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, k; cin >> n >> k;
    vi dp(n + 1, MAX);
    bfs(dp, n, k);
    
    cout << (dp[n] != MAX ? "minigimbob" : "water");
    
    return 0;
}
