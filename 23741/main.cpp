//
//  main.cpp
//  23741
//
//  Created by 정지용 on 2/16/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;
using ii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvb = vector<vector<bool>>;
using vb = vector<bool>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void bfs(const vvi& graph, vvb& visited, int start, int cnt) {
    queue<int> q;
    q.push(start);
    visited[start][0] = true;
    
    while (!q.empty()) {
        int current = q.front(); q.pop();
        
        for (int next: graph[current]) {
            visited[next][cnt + 1] = true;
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m, x, y, s, e;
    cin >> n >> m >> x >> y;
    
    vvi graph(n + 1, vi());
    
    for (int i = 0; i < m; ++i) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    if (graph[x].size() == 0) {
        cout << -1; return 0;
    }
    
    vvb visited(n + 1, vb(y + 1, false));
    visited[x][0] = true;
    for (int i = 0; i < y; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (visited[j][i]) bfs(graph, visited, j, i);
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (visited[i][y]) cout << i << ' ';
    }
    
    return 0;
}
