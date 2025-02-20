//
//  main.cpp
//  31863
//
//  Created by 정지용 on 2/20/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vvvb = vector<vector<vector<bool>>>;

struct Pos {
    int x, y, strength;
    Pos(int x, int y, int strength): x(x), y(y), strength(strength) {}
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int bfs(vs& graph, vvvb& visited, int sx, int sy) {
    queue<Pos> q;
    q.emplace(sx, sy, 2);
    visited[sy][sx][0] = true;
    
    int n = graph.size();
    int m = graph[0].size();
    
    while (!q.empty()) {
        int qx = q.front().x;
        int qy = q.front().y;
        int strength = q.front().strength;
        q.pop();
        
        for (int d = 0; d < 4; ++d) {
            int dstrength = strength;
            int nx = qx, ny = qy;
            while (dstrength--) {
                nx += dx[d];
                ny += dy[d];
                
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) break;
                if (graph[ny][nx] == '|') break;
                
                if (graph[ny][nx] == '*' && !visited[ny][nx][0]) {
                    visited[ny][nx][0] = true;
                    graph[ny][nx] = '.';
                    q.emplace(nx, ny, 1);
                    continue;
                }
                
                if (graph[ny][nx] == '#') {
                    if (!visited[ny][nx][0]) {
                        visited[ny][nx][0] = true;
                    } else if (!visited[ny][nx][1]) {
                        visited[ny][nx][1] = true;
                        graph[ny][nx] = '.';
                        q.emplace(nx, ny, 1);
                    }
                }
            }
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m; cin >> n >> m;
    
    vs graph(n);
    
    string line;
    for (int i = 0; i < n; ++i) cin >> graph[i];
    
    int ans1 = 0;
    int ans2 = 0;
    int sx = 0, sy = 0;
    
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            if (graph[y][x] == '*' || graph[y][x] == '#') ++ans1;
            if (graph[y][x] == '@') {
                sx = x; sy = y;
            }
        }
    }
    
    vvvb visited(n, vvb(m, vb(2, false)));
    
    bfs(graph, visited, sx, sy);
    
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            if (graph[y][x] == '*' || graph[y][x] == '#') ++ans2;
        }
    }
    
    cout << ans1 - ans2 << ' ' << ans2 << '\n';
    
    return 0;
}
