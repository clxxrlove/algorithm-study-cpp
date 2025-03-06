//
//  main.cpp
//  2638
//
//  Created by 정지용 on 3/6/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;

int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool clear(vvi& board, vvi& visited) {
    bool flag = false;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (visited[i][j] >= 2) {
                board[i][j] = 0;
                flag = true;
            }
        }
    }
    
    return flag;
}

bool bfs(vvi& board) {
    queue<ii> q;
    q.emplace(0, 0);
    vvi visited(n + 2, vi(m + 2, 0));
    visited[0][0] = true;
    
    while (!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        
        for (int d = 0; d < 4; ++d) {
            int nx = qx + dx[d];
            int ny = qy + dy[d];
            
            if (nx < 0 || nx >= m + 2 || ny < 0 || ny >= n + 2) continue;
            if (board[ny][nx] == 1) {
                visited[ny][nx] += 1;
                continue;
            }
            if (!visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.emplace(nx, ny);
            }
        }
    }
    
    return clear(board, visited);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    cin >> n >> m;
    vvi board(n + 2, vi(m + 2));
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    
    int answer = 0;
    
    while (bfs(board)) answer++;
    cout << answer;
    
    return 0;
}
