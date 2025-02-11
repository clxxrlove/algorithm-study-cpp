//
//  main.cpp
//  17836
//
//  Created by 정지용 on 2/11/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;

struct Player {
    int x;
    int y;
    bool equipped;
    
    Player(int x, int y, bool equipped): x(x), y(y), equipped(equipped) {}
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int bfs(vvi& graph) {
    int n = graph.size();
    int m = graph[0].size();
    
    queue<Player> q;
    q.emplace(0, 0, false);
    
    vector<vvi> visited(n, vvi(m, vi(2, 0)));
    visited[0][0][0] = 1;
    
    while (!q.empty()) {
        Player current = q.front(); q.pop();
        
        if (current.x == m - 1 && current.y == n - 1) return visited[n - 1][m - 1][current.equipped] - 1;
        
        for (int d = 0; d < 4; ++d) {
            int nx = current.x + dx[d];
            int ny = current.y + dy[d];
            bool equipped = current.equipped;
            
            if (nx >= m || nx < 0 || ny >= n || ny < 0) continue;
            
            // 템빨
            if (equipped) {
                if (!visited[ny][nx][equipped]) {
                    q.emplace(nx, ny, equipped);
                    visited[ny][nx][equipped] = visited[current.y][current.x][equipped] + 1;
                }
            } else {
                // 템 없으면 벽 못뚫음
                if (!visited[ny][nx][equipped] && graph[ny][nx] != 1) {
                    bool new_equipped = graph[ny][nx] == 2;
                    q.emplace(nx, ny, new_equipped);
                    visited[ny][nx][new_equipped] = visited[current.y][current.x][0] + 1;
                }
            }
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m, t;
    cin >> n >> m >> t;
    
    vvi graph(n, vi(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> graph[i][j];
        }
    }
    
    int answer = bfs(graph);
    if (answer <= t && answer != -1) {
        cout << answer;
    } else cout << "Fail";
    
    return 0;
}
