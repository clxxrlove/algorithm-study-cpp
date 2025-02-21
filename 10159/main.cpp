//
//  main.cpp
//  10159
//
//  Created by 정지용 on 2/21/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vb = vector<bool>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int bfs(const vvi& graph, int start) {
    vb visited(graph.size(), false);
    visited[start] = true;
    queue<int> q;
    q.push(start);
    
    int result = 0;
    
    while (!q.empty()) {
        int current = q.front(); q.pop();
        
        for (int next: graph[current]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                ++result;
            }
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m; cin >> n >> m;
    
    vvi graph(n + 1, vi());
    vvi r_graph(n + 1, vi());
    
    int s, e;
    for (int i = 0; i < m; ++i) {
        cin >> s >> e;
        graph[s].push_back(e);
        r_graph[e].push_back(s);
    }
    
    for (int i = 1; i <= n; ++i) {
        s = bfs(graph, i);
        e = bfs(r_graph, i);
        cout << n - 1 - s - e << '\n';
    }
    
    return 0;
}
