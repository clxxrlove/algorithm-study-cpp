//
//  main.cpp
//  2140
//
//  Created by 정지용 on 4/28/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vc = vector<char>;
using vvc = vector<vc>;

int n;
int answer = 0;
vvc board;

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    board.resize(n, vc(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            if (board[i][j] == '#') answer++;
        }
    }
}

void reflect(int x, int y) {
    for (int d = 0; d < 8; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
        if (board[ny][nx] > '0' && board[ny][nx] < '9') {
            --board[ny][nx];
        }
    }
}

bool check(int x, int y) {
    for (int d = 0; d < 8; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
        if (board[ny][nx] == '0') {
            return true;
        }
    }
    
    reflect(x, y);
    return false;
}

void solution() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[j][i] == '#' && check(i, j)) {
                --answer;
            }
        }
    }
    
    cout << answer << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
