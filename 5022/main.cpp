//
//  main.cpp
//  5022
//
//  Created by 정지용 on 2/18/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

struct Point {
    int x, y, count;
    Point(int x, int y, int count): x(x), y(y), count(count) {}
};

// 상 좌 하 우
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int bfs(vvi& visited, ii start, ii target, int n, int m, ii other_f, ii other_s) {
    queue<Point> q;
    q.push({start.first, start.second, 0});
    visited[start.second][start.first] = -2; // 재접근방지 0~3도 아닌 애매한 수
    
    while (!q.empty()) {
        int qx = q.front().x;
        int qy = q.front().y;
        int qcount = q.front().count;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            
            if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
            if ((nx == other_f.first && ny == other_f.second) || (nx == other_s.first && ny == other_s.second)) continue;
            if (visited[ny][nx] == -1) {
                visited[ny][nx] = i;
                
                if (nx == target.first && ny == target.second) {
                    return qcount + 1;
                }
                
                q.push({nx, ny, qcount + 1});
            }
        }
    }
    
    return -1;
}

vector<ii> backtrack(ii start, ii target, const vvi& visited) {
    vector<ii> result;
    
    int x = target.first;
    int y = target.second;
    
    result.push_back(target);
    
    while (!(x == start.first && y == start.second)) {
        int d = visited[y][x];
        x = x - dx[d];
        y = y - dy[d];
        
        result.push_back({x, y});
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m; cin >> n >> m;
    
    vector<ii> a_pos;
    vector<ii> b_pos;
    
    int x, y;
    for (int i = 0; i < 2; ++i) {
        cin >> x >> y;
        a_pos.push_back({x, y});
    }
    
    for (int i = 0; i < 2; ++i) {
        cin >> x >> y;
        b_pos.push_back({x, y});
    }
    
    vvi visited(m + 1, vi(n + 1, -1));

    int first_length = 1e9;
    int second_length = 1e9;
    // 1번 시행 = A의 최단거리 시작
    int first_a = bfs(visited, a_pos[0], a_pos[1], n, m, b_pos[0], b_pos[1]);
    if (first_a != -1) {
        vector<ii> a_res = backtrack(a_pos[0], a_pos[1], visited);
        
        for (auto& row: visited) fill(row.begin(), row.end(), -1);
        for (auto& pos: a_res) visited[pos.second][pos.first] = -2;
        
        int first_b = bfs(visited, b_pos[0], b_pos[1], n, m, a_pos[0], a_pos[1]);
        
        if (first_b != -1) {
            first_length = first_a + first_b;
        }
    }
    
    for (auto& row: visited) fill(row.begin(), row.end(), -1);
    
    int second_b = bfs(visited, b_pos[0], b_pos[1], n, m, a_pos[0], a_pos[1]);
    if (second_b != -1) {
        vector<ii> sb_res = backtrack(b_pos[0], b_pos[1], visited);
        
        for (auto& row: visited) fill(row.begin(), row.end(), -1);
        for (auto& pos: sb_res) visited[pos.second][pos.first] = -2;
        
        int second_a = bfs(visited, a_pos[0], a_pos[1], n, m, b_pos[0], b_pos[1]);
        
        if (second_a != -1) {
            second_length = second_a + second_b;
        }
    }
    
    if (first_length == 1e9 && second_length == 1e9) {
        cout << "IMPOSSIBLE";
    } else cout << min(first_length, second_length);
    
    return 0;
}
