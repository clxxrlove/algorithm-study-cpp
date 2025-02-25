//
//  main.cpp
//  2636
//
//  Created by 정지용 on 2/25/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ii> bfs(const vvi& graph) {
    size_t n = graph.size();
    size_t m = graph[0].size();
    
    vector<ii> result;
    
    queue<ii> q; 
    q.emplace(0, 0);
    
    vvb visited(n, vb(m, false));
    visited[0][0] = true;
    
    while (!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        
        for (int d = 0; d < 4; ++d) {
            int nx = qx + dx[d];
            int ny = qy + dy[d];
            
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                
                if (graph[ny][nx] == 1) { result.emplace_back(nx, ny); }
                else q.emplace(nx, ny);
            }
        }
    }
    
    return result;
}

void clear(const vector<ii>& checked, vvi& graph) {
    for (auto item: checked) {
        int x = item.first, y = item.second;
        graph[y][x] = 0;
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m; cin >> n >> m;
    vvi graph(n, vi(m, 0));
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> graph[i][j];
    
    int ans_time = 0, ans_size = 0;
    while (true) {
        vector<ii> result = bfs(graph);
        if (result.size() == 0) break;
        
        clear(result, graph);
        ++ans_time;
        ans_size = result.size();
    }
    
    cout << ans_time << '\n' << ans_size;
    
    return 0;
}
