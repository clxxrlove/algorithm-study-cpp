//
//  main.cpp
//  2194
//
//  Created by 정지용 on 3/17/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using ii = pair<int, int>;

struct Pos {
    int x, y, count;
    Pos(int x, int y, int count): x(x), y(y), count(count) {}
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
const int MAX = 2e9;

// n, a = height, m, b = width
int n, m, a, b, k;
int sx, sy;
int ex, ey;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool check(const vvi& graph,
           const vvb& visited,
           int nx,
           int ny) {
    if (nx < 0 || ny < 0 || nx + b > m || ny + a > n) return false;
    if (visited[ny][nx]) return false;
    
    for (int y = ny; y <= ny + a - 1; ++y) {
        for (int x = nx; x <= nx + b - 1; ++x) {
            if (graph[y][x] == -1) return false;
        }
    }
    
    return true;
}

int bfs(const vvi& graph) {
    queue<Pos> q;
    vvb visited(n, vb(m, false));
    q.emplace(sx, sy, 0);
    visited[sy][sx] = true;
    
    while (!q.empty()) {
        int qx = q.front().x;
        int qy = q.front().y;
        int count = q.front().count;
        q.pop();
        
        if (qx == ex && qy == ey) return count;
        
        for (int d = 0; d < 4; ++d) {
            int nx = qx + dx[d];
            int ny = qy + dy[d];
            
            if (!check(graph, visited, nx, ny)) {
                continue;
            }
            
            visited[ny][nx] = true;
            q.emplace(nx, ny, count + 1);
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    cin >> n >> m >> a >> b >> k;
    
    vvi graph(n, vi(m, 0));
    for (int i = 0; i < k; ++i) {
        int y, x;
        cin >> y >> x;
        graph[y - 1][x - 1] = -1;
    }
    
    cin >> sy >> sx >> ey >> ex;
    sx--; sy--; ex--; ey--;
    
    for (int y = ey; y <= ey + a - 1; ++y) {
        for (int x = ex; x <= ex + b - 1; ++x) {
            if (graph[y][x] == -1) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    
    cout << bfs(graph) << '\n';
    
    return 0;
}
