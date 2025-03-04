//
//  main.cpp
//  14502
//
//  Created by 정지용 on 3/4/25.
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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int counter(vvi& board) {
    int result = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 0) ++result;
        }
    }
    
    return result;
}

int bfs(const vector<ii>& viruses,
        vvi board) {
    queue<ii> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (ii v: viruses) {
        q.push(v);
        visited[v.second][v.first] = true;
    }
    
    while (!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        
        for (int d = 0; d < 4; ++d) {
            int nx = qx + dx[d];
            int ny = qy + dy[d];
            
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (!visited[ny][nx] && board[ny][nx] == 0) {
                board[ny][nx] = 2;
                visited[ny][nx] = true;
                q.emplace(nx, ny);
            }
        }
    }
    
    return counter(board);
}

void backtracking(int& answer,
                  int depth,
                  const vector<ii>& viruses,
                  vvi& board) {
    if (depth == 3) {
        answer = max(answer, bfs(viruses, board));
        return;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 0) {
                board[i][j] = 1;
                backtracking(answer, depth + 1, viruses, board);
                board[i][j] = 0;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int answer = 0;
    cin >> n >> m;
    vvi board(n, vi(m));
    vector<ii> viruses;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                viruses.emplace_back(j, i);
            }
        }
    }
    
    backtracking(answer, 0, viruses, board);
    cout << answer;
    
    return 0;
}
