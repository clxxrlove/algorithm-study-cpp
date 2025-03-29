//
//  main.cpp
//  1949
//
//  Created by 정지용 on 3/29/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
vvi tree;
vi cost;
vi visited;
vvi dp;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    
    tree.resize(n + 1);
    cost.resize(n + 1);
    visited.resize(n + 1, false);
    dp.resize(n + 1, vi(2, 0));
    
    int s, e;
    for (int i = 1; i <= n; ++i) cin >> cost[i];
    for (int i = 0; i < n - 1; ++i) {
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
}

void dfs(int u) {
    visited[u] = true;
    
    dp[u][0] = 0;
    dp[u][1] = cost[u];
    
    for (auto& v: tree[u]) {
        if (visited[v]) continue;
        dfs(v);
        
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void solution() {
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
