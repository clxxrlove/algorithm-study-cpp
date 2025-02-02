//
//  main.cpp
//  1766
//
//  Created by 정지용 on 2/2/25.
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

vector<int> topological_sort(int n,
                             const vector<ii>& edges) {
    priority_queue<int, vector<int>, greater<int>> q;
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<int> in_degree(n + 1, 0);
    vector<int> result;
    
    for (ii edge: edges) {
        ++in_degree[edge.second];
        graph[edge.first].push_back(edge.second);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int current_node = q.top(); q.pop();
        result.push_back(current_node);
        
        for (int next_node: graph[current_node]) {
            --in_degree[next_node];
            
            if (in_degree[next_node] == 0) {
                q.push(next_node);
            }
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m;
    int start, end;
    cin >> n >> m;
    
    vector<ii> edges;
    for (int i = 0; i < m; ++i) {
        cin >> start >> end;
        edges.emplace_back(start, end);
    }
    
    for (int element: topological_sort(n, edges)) {
        cout << element << " ";
    }

    return 0;
}
