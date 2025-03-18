//
//  main.cpp
//  14503
//
//  Created by 정지용 on 3/18/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;

struct Pos {
    int x, y, d;
    Pos(): x(0), y(0), d(0) {}
    Pos(int x, int y, int d): x(x), y(y), d(d) {}
};

int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int check(const vvi& graph, Pos pos) {
    int d = pos.d - 1;
    while (true) {
        if (d < 0) d += 4;
        int nx = pos.x + dx[d];
        int ny = pos.y + dy[d];
        
        if (graph[ny][nx] == 0) return d;
        if (--d == pos.d - 1) break;
    }
    return -1;
}

int bfs(Pos start, vvi& graph) {
    queue<Pos> q;
    q.push(start);
    int result = 0;
    
    if (graph[start.y][start.x] == 0) result++;
    graph[start.y][start.x] = -1;
    
    while (!q.empty()) {
        auto qf = q.front(); q.pop();
        auto [qx, qy, qd] = qf;
        
        if (graph[qy][qx] == 0) result++;
        graph[qy][qx] = -1;
        
        int d = check(graph, qf);
        if (d != -1) {
            q.emplace(qx + dx[d], qy + dy[d], d);
        } else {
            Pos nPos = {qx - dx[qd], qy - dy[qd], qd};
            if (graph[nPos.y][nPos.x] == 1) return result;
            q.push(nPos);
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    cin >> n >> m;
    Pos start;
    cin >> start.y >> start.x >> start.d;
    
    vvi graph(n, vi(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> graph[i][j];
        }
    }
    
    cout << bfs(start, graph) << '\n';
    
    return 0;
}
