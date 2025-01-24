//
//  main.cpp
//  14500
//
//  Created by 정지용 on 1/24/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// vertical, horizontal
int n, m;
int answer = 0;
vector<vector<int>> graph;
vector<vector<bool>> visited;

int dx[] = {0, 0, -1 ,1};
int dy[] = {-1, 1, 0, 0};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(int x,
         int y,
         int depth,
         int acc) {
    if (depth == 4) {
        answer = max(answer, acc);
        return;
    }
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx]) {
            visited[ny][nx] = true;
            dfs(nx, ny, depth + 1, acc + graph[ny][nx]);
            visited[ny][nx] = false;
        }
    }
}

void tShape(int x, int y) {
    int acc = graph[y][x];
    int able = 0;
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            acc += graph[ny][nx];
            ++able;
        }
    }
    
    if (able == 4) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                answer = max(answer, acc - graph[ny][nx]);
            }
        }
    } else if (able == 3) {
        answer = max(answer, acc);
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    cin >> n >> m;
    
    graph.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> graph[i][j];
    }
    
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            visited[y][x] = true;
            dfs(x, y, 1, graph[y][x]);
            tShape(x, y);
            visited[y][x] = false;
        }
    }
    
    cout << answer;
    
    return 0;
}
