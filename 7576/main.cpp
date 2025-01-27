//
//  main.cpp
//  7576
//
//  Created by 정지용 on 1/27/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ii = pair<int, int>;

int n, m; // x, y
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Point {
    int x, y, depth;
    Point(int x, int y, int depth): x(x), y(y), depth(depth) {}
    Point(int x, int y): x(x), y(y), depth(0) {}
};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void bfs(queue<Point>& q,
         int& answer,
         vector<vector<int>>& graph,
         vector<vector<bool>>& visited) {
    while (!q.empty()) {
        Point np = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int qx = np.x + dx[i];
            int qy = np.y + dy[i];
            
            if (qx < 0 || qx >= n || qy < 0 || qy >= m) continue;
            
            if (!visited[qy][qx] && graph[qy][qx] == 0) {
                visited[qy][qx] = true;
                graph[qy][qx] = 1;
                answer = max(answer, np.depth + 1);
                q.push({qx, qy, np.depth + 1});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int answer = 0;
    cin >> n >> m;
    
    vector<vector<int>> graph(m, vector<int>(n, 0));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<Point> tomatos;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                tomatos.push({j, i});
            }
        }
    }
    
    bfs(tomatos, answer, graph, visited);
    
    bool flag = true;
    for (int y = 0; y < m; ++y) {
        if (find(graph[y].begin(), graph[y].end(), 0) != graph[y].end()) {
            flag = false;
            break;
        }
    }
    
    cout << (flag ? answer : -1);
    
    return 0;
}
