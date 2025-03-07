//
//  main.cpp
//  16236
//
//  Created by 정지용 on 3/7/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;

struct Pos {
    int x, y, count;
    Pos(int x, int y, int count): x(x), y(y), count(count) {}
};

int n;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

pair<int, vector<ii>> bfs(vvi& board, ii start, int& size, int& ate) {
    queue<Pos> q;
    q.emplace(start.first, start.second, 0);
    vvb visited(n, vb(n));
    visited[start.second][start.first] = true;
    pair<int, vector<ii>> result;
    result.first = 0;
    
    while (!q.empty()) {
        int qx = q.front().x;
        int qy = q.front().y;
        int count = q.front().count;
        q.pop();
        
        for (int d = 0; d < 4; ++d) {
            int nx = qx + dx[d];
            int ny = qy + dy[d];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[ny][nx] > size) continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                if (board[ny][nx] == 0 || board[ny][nx] == size) {
                    q.emplace(nx, ny, count + 1);
                } else if (result.first == 0 || result.first == count + 1) {
                    if (result.first == 0) result.first = count + 1;
                    result.second.emplace_back(nx, ny);
                }
            }
        }
    }
    
    return result;
}

void print(const vvi& board) {
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << ' ';
        } cout << '\n';
    }
}

ii find_start(const vvi& board) {
    ii result;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 9) {
                result = {j, i};
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    return result;
}

void clear(vvi& board, vector<ii>& options, ii& start) {
    if (options.size() == 0) return;
    sort(options.begin(), options.end(), [](const ii& lhs, const ii& rhs) {
        if (lhs.second == rhs.second) {
            return lhs.first < rhs.first;
        }
        return lhs.second < rhs.second;
    });
    
    board[start.second][start.first] = 0;
    board[options[0].second][options[0].first] = 9;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    cin >> n;
    
    vvi board(n, vi(n));
    ii start;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    
    int answer = 0;
    int size = 2;
    int ate = 0;
    int attempt;
    vector<ii> options;
    do {
        start = find_start(board);
        auto result = bfs(board, start, size, ate);
        attempt = result.first; options = result.second;
        clear(board, options, start);
        if (++ate == size) {
            ++size; ate = 0;
        }
        answer += attempt;
    } while(options.size());
    cout << answer;
    
    return 0;
}
