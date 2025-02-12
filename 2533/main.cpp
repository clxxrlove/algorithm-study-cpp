//
//  main.cpp
//  2533
//
//  Created by 정지용 on 2/13/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

vector<bool> visited;
vvi graph;
vvi dp;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(int node) {
    visited[node] = true;
    dp[node][0] = 0; // 얼리x
    dp[node][1] = 1; // 얼리o
    
    for (int child: graph[node]) {
        if (visited[child]) continue;
        dfs(child);
        dp[node][0] += dp[child][1];
        dp[node][1] += min(dp[child][0], dp[child][1]); // 내가 얼리니까 걍 싼거 고름
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n; cin >> n;
    graph.resize(n + 1, vi());
    dp.resize(n + 1, vi(2, 0));
    visited.resize(n + 1, false);
    
    for (int i = 0; i < n - 1; ++i) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
    
    return 0;
}
