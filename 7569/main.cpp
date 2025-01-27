//
//  main.cpp
//  7569
//
//  Created by 정지용 on 1/27/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ii = pair<int, int>;

int n, m, h; // x, y, z
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

struct Point {
    int x, y, z, depth;
    Point(int x, int y, int z, int depth): x(x), y(y), z(z), depth(depth) {}
    Point(int x, int y, int z): x(x), y(y), z(z), depth(0) {}
};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void bfs(queue<Point>& q,
         int& answer,
         vector<vector<vector<int>>>& graph,
         vector<vector<vector<bool>>>& visited) {
    while (!q.empty()) {
        Point np = q.front();
        q.pop();
        
        for (int i = 0; i < 6; ++i) {
            int qx = np.x + dx[i];
            int qy = np.y + dy[i];
            int qz = np.z + dz[i];
            
            if (qx < 0 || qx >= n || qy < 0 || qy >= m || qz < 0 || qz >= h) continue;
            
            if (!visited[qz][qy][qx] && graph[qz][qy][qx] == 0) {
                visited[qz][qy][qx] = true;
                graph[qz][qy][qx] = 1;
                answer = max(answer, np.depth + 1);
                q.push({qx, qy, qz, np.depth + 1});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int answer = 0;
    cin >> n >> m >> h;
    
    vector<vector<vector<int>>> graph(h, vector<vector<int>>(m, vector<int>(n, 0)));
    vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(m, vector<bool>(n, false)));
    queue<Point> tomatos;
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> graph[i][j][k];
                if (graph[i][j][k] == 1) {
                    tomatos.push({k, j, i});
                }
            }
        }
    }
    
    bfs(tomatos, answer, graph, visited);
    
    bool flag = true;
    for (int z = 0; z < h; ++z) {
        for (int y = 0; y < m; ++y) {
            if (find(graph[z][y].begin(), graph[z][y].end(), 0) != graph[z][y].end()) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    
    cout << (flag ? answer : -1);
    
    return 0;
}
