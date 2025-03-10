//
//  main.cpp
//  1103
//
//  Created by 정지용 on 3/10/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using ii = pair<int, int>;
using vii = vector<pair<int, int>>;

int n, m;
int answer = 0;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

vvi graph;
vvi visited;
vvb in_stack;

void dfs(int x, int y, int depth) {
    answer = max(answer, depth);
    
    for (int d = 0; d < 4; ++d) {
        int k = graph[y][x];
        
        int nx = x + dx[d] * k;
        int ny = y + dy[d] * k;
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if (graph[ny][nx] == 0) continue;
        
        if (in_stack[ny][nx]) {
            cout << -1 << '\n';
            exit(0);
        }
        
        if (visited[ny][nx] < depth + 1) {
            visited[ny][nx] = depth + 1;
            
            in_stack[ny][nx] = true;
            dfs(nx, ny, depth + 1);
            in_stack[ny][nx] = false;
        }
    }
}

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    cin >> n >> m;
    graph.resize(n, vi(m));
    visited.resize(n, vi(m, -1));
    in_stack.resize(n, vb(m, false));
    
    char tmp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> tmp;
            if (tmp == 'H') graph[i][j] = 0;
            else graph[i][j] = tmp - '0';
        }
    }
    
    vii in_stack;
    visited[0][0] = 0;
    dfs(0, 0, 1);
    cout << answer << '\n';
    
    return 0;
}
