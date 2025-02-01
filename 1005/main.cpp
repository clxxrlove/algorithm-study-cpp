//
//  main.cpp
//  1005
//
//  Created by 정지용 on 2/1/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ii = pair<int, int>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int topological_sort(int n,
                     int k,
                     int target,
                     const vector<int>& build_time,
                     const vector<ii>& order) {
    queue<int> q;
    vector<int> in_degree(n + 1, 0);
    vector<int> dp(n + 1, 0);
    vector<vector<int>> graph(n + 1, vector<int>());
    
    for (ii o: order) {
        graph[o.first].push_back(o.second);
        ++in_degree[o.second];
    }
    
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
            dp[i] = build_time[i];
        }
    }
    
    while (!q.empty()) {
        int current_node = q.front(); q.pop();
        
        for (int next_node: graph[current_node]) {
            --in_degree[next_node];
            dp[next_node] = max(dp[next_node], dp[current_node] + build_time[next_node]);
            
            if (in_degree[next_node] == 0) {
                q.push(next_node);
            }
        }
    }
    
    return dp[target];
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int t;
    cin >> t;
    
    for (int _ = 0; _ < t; ++_) {
        int n, k;
        int start, end, target;
        cin >> n >> k;
        
        vector<int> build_time(n + 1);
        vector<ii> order;
        for (int i = 1; i <= n; ++i) cin >> build_time[i];
        for (int i = 0; i < k; ++i) {
            cin >> start >> end;
            order.emplace_back(start, end);
        }
        cin >> target;
        cout << topological_sort(n, k, target, build_time, order) << "\n";
    }
    
    return 0;
}
