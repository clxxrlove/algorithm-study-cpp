//
//  main.cpp
//  11559
//
//  Created by 정지용 on 2/15/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using ii = pair<int, int>;

const int height = 12;
const int width = 6;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Point {
    int x, y, count;
    Point(int x, int y, int count): x(x), y(y), count(count) {}
};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<ii> bfs(const vvc& graph,
               vvb& visited,
               int x,
               int y,
               char color) {
    vector<ii> result;
    queue<Point> q;
    q.emplace(x, y, 0);
    visited[y][x] = true;
    result.emplace_back(x, y);
    
    while (!q.empty()) {
        int qx = q.front().x;
        int qy = q.front().y;
        int qcount = q.front().count;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            
            if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
            if (!visited[ny][nx] && graph[ny][nx] == color) {
                visited[ny][nx] = true;
                result.emplace_back(nx, ny);
                q.emplace(nx, ny, qcount + 1);
            }
        }
    }
    
    return result;
}

void clean(vvc& graph, const vector<ii>& poses) {
    map<int, int> remove_count;
    int height = graph.size();

    for (const ii& pos : poses) {
        remove_count[pos.first] += 1;
        graph[pos.second][pos.first] = '.';
    }

    for (auto& [x, count] : remove_count) {
        vector<char> temp_col;

        for (int y = height - 1; y >= 0; --y) {
            if (graph[y][x] != '.') temp_col.push_back(graph[y][x]);
        }

        int index = height - 1;
        for (char c : temp_col) {
            graph[index--][x] = c;
        }

        while (index >= 0) {
            graph[index--][x] = '.';
        }
    }
}

void print(vvc& graph) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << graph[i][j];
        } cout << '\n';
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int answer = 0;
    vvc graph(12, vc(6));
    
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) cin >> graph[i][j];
    }
    
    bool flag = true;
    
    while (flag) {
        flag = false;
        
        vvb visited(12, vector<bool>(6, false));
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (graph[i][j] != '.' && !visited[i][j]) {
                    vector<ii> result = bfs(graph, visited, j, i, graph[i][j]);
                    
                    if (result.size() >= 4) {
                        flag = true;
                        clean(graph, result);
                    }
                }
            }
        }
        
        if (flag) answer++;
    }
    
    cout << answer;
    
    return 0;
}
