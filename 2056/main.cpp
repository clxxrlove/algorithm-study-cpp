//
//  main.cpp
//  2056
//
//  Created by 정지용 on 2/1/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int topological_sort(int n,
                     vi& in_degree,
                     const vi& task_time,
                     const vector<vi>& graph) {
    queue<int> q;
    vi dp(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
            dp[i] = task_time[i];
        }
    }
    
    while (!q.empty()) {
        int current_node = q.front(); q.pop();
        
        for (int next_node: graph[current_node]) {
            --in_degree[next_node];
            dp[next_node] = max(dp[next_node], dp[current_node] + task_time[next_node]);
            if (in_degree[next_node] == 0) {
                q.push(next_node);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    int time, k, start;
    cin >> n;
    
    vi in_degree(n + 1);
    vi task_time(n + 1, 0);
    vector<vi> graph(n + 1, vi());
    
    for (int i = 1; i <= n; ++i) {
        cin >> time >> k;
        task_time[i] = time;
        in_degree[i] = k;
        for (int j = 0; j < k; ++j) {
            cin >> start;
            graph[start].push_back(i);
        }
    }
    
    cout << topological_sort(n, in_degree, task_time, graph);
    
    return 0;
}
