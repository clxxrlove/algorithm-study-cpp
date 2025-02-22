//
//  main.cpp
//  22944
//
//  Created by 정지용 on 2/23/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;

struct Pos {
    int x, y, count, hp, um;
    Pos(int x, int y, int count, int hp, int um): x(x), y(y), count(count), hp(hp), um(um) {}
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int bfs(const vs& graph,
        int hp,
        int durability,
        int sx,
        int sy) {
    int n = graph.size();
    
    queue<Pos> q;
    q.emplace(sx, sy, 0, hp, 0);
    vvi visited(n, vi(n, false));
    visited[sy][sx] = hp;
    
    while (!q.empty()) {
        int qx = q.front().x;
        int qy = q.front().y;
        int count = q.front().count;
        int qhp = q.front().hp;
        int umbrella = q.front().um;
        q.pop();
        
        for (int d = 0; d < 4; ++d) {
            int nx = qx + dx[d];
            int ny = qy + dy[d];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            
            int new_umbrella = umbrella;
            if (graph[ny][nx] == 'U') new_umbrella = durability;
            if (graph[ny][nx] == 'E') return count + 1;
            
            int condition = qhp + new_umbrella - 1;
            if (new_umbrella > 0) {
                if (visited[ny][nx] >= condition) continue;
                visited[ny][nx] = condition;
                q.emplace(nx, ny, count + 1, qhp, new_umbrella - 1);
            } else if (qhp > 0) {
                if (visited[ny][nx] >= condition) continue;
                visited[ny][nx] = condition;
                q.emplace(nx, ny, count + 1, qhp - 1, new_umbrella);
            }
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    setDefault();
    int n, h, d;
    cin >> n >> h >> d;
    
    vs graph(n);
    for (int i = 0; i < n; ++i) cin >> graph[i];
    
    int sx = 0, sy = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == 'S') {
                sx = j; sy = i;
                break;
            }
        }
    }
    
    cout << bfs(graph, h, d, sx, sy);
    
    return 0;
}
