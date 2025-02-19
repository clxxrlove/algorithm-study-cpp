//
//  main.cpp
//  25689
//
//  Created by 정지용 on 2/19/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Pos {
    int x, y, mask, count;
    Pos(int x, int y, int mask, int count):
        x(x), y(y), mask(mask), count(count) {}
};

int graph[5][5];
bool visited[5][5][1 << 6];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int bfs(int x, int y) {
    queue<Pos> q;
    q.emplace(x, y, 0, 0);
    
    visited[y][x][0] = true;
    int target = (1 << 6) - 1;
    
    while (!q.empty()) {
        auto [qx, qy, mask, count] = q.front();
        q.pop();
        
        if (mask == target) return count;
        
        for (int i = 0; i < 4; ++i) {
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            
            if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
            if (graph[ny][nx] == -1) continue;
            
            int next = mask;
            if (graph[ny][nx] >= 1 && graph[ny][nx] <= 6) {
                next |= (1 << (graph[ny][nx] - 1));
            }
            
            // 해당 땅을 밟겠다는 경우
            if (!visited[ny][nx][next]) {
                visited[ny][nx][next] = true;
                
                // 어차피 0이면 못 밟음. 아래에서 처리.
                q.emplace(nx, ny, next, count + 1);
            }
            
            int tx = qx, ty = qy;
            while (true) {
                int rx = tx + dx[i];
                int ry = ty + dy[i];
                
                // 한번 더 가면 죽는 경우 기존으로
                if (rx < 0 || rx > 4 || ry < 0 || ry > 4) break;
                if (graph[ry][rx] == -1) break;
                
                tx = rx; ty = ry;
                
                if (graph[ty][tx] == 7) break;
            }
            
            if (tx != qx || ty != qy) {
                int run = mask;
                if (graph[ty][tx] >= 1 && graph[ty][tx] <= 6) {
                    run |= (1 << (graph[ty][tx] -1));
                }
                
                if (!visited[ty][tx][run]) {
                    visited[ty][tx][run] = true;
                    q.emplace(tx, ty, run, count + 1);
                }
            }
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) cin >> graph[i][j];
    }
    
    int x, y;
    cin >> y >> x;
    
    int answer = bfs(x, y);
    cout << answer;
    
    return 0;
}
