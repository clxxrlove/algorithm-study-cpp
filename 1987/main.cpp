//
//  main.cpp
//  1987
//
//  Created by 정지용 on 1/22/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int answer = 0;
int r, c;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void backtracking(int x,
                  int y,
                  const vector<vector<char>>& graph,
                  int visited,
                  int count) {
    answer = max(answer, count);
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < c && ny >= 0 && ny < r) {
            char chr = graph[ny][nx];
            int bit = 1 << (chr - 'A');
            
            if ((visited & bit) == 0) {
                backtracking(nx, ny, graph, visited | bit, count + 1);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    cin >> r >> c;
    
    string tmp;
    vector<vector<char>> graph;
    
    for (int i = 0; i < r; ++i) {
        cin >> tmp;
        graph.push_back(vector<char>(tmp.begin(), tmp.end()));
    }
    
    int visited = 0;
    visited |= (1 << ((graph[0][0]) - 'A'));
    backtracking(0, 0, graph, visited, 1);
    
    cout << answer;
    
    return 0;
}
