//
//  main.cpp
//  4991
//
//  Created by 정지용 on 3/11/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vvvb = vector<vector<vector<bool>>>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;

int w, h;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Pos {
    int x, y, bit;
    Pos(int x, int y, int bit): x(x), y(y), bit(bit) {}
};

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int bfs(vvc& graph, int x, int y, int cnt) {
    queue<Pos> q;
    vvvi visited(h, vvi(w, vi(1 << cnt, 0)));
    
    q.emplace(x, y, 0);
    visited[y][x][0] = 1;
    int target = (1 << cnt) - 1;
    
    while (!q.empty()) {
        int qx = q.front().x;
        int qy = q.front().y;
        int bit = q.front().bit;
        int count = visited[qy][qx][bit];
        q.pop();
        
        for (int d = 0; d < 4; ++d) {
            int nx = qx + dx[d];
            int ny = qy + dy[d];
            
            int next_bit = bit;
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (graph[ny][nx] == 'x') continue;
            if (isdigit(graph[ny][nx])) next_bit |= (1 << (graph[ny][nx] - '0'));
            if (next_bit == target) return count;
            if (!visited[ny][nx][next_bit]) {
                visited[ny][nx][next_bit] = count + 1;
                q.emplace(nx, ny, next_bit);
            }
        }
    }
    
    return -1;
}

void solution() {
    vvc graph(h, vc(w));
    int sx, sy;
    int cnt = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 'o') {
                sx = j; sy = i;
            } else if (graph[i][j] == '*') {
                graph[i][j] = cnt++ + '0';
            }
        }
    }
    
    cout << bfs(graph, sx, sy, cnt) << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        
        solution();
    }
    
    return 0;
}
