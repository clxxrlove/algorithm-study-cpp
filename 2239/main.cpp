//
//  main.cpp
//  2239
//
//  Created by 정지용 on 1/22/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool check(int x,
           int y,
           int value,
           const vector<vector<int>>& graph) {
    int nx = x / 3 * 3;
    int ny = y / 3 * 3;
    
    for (int dx = 0; dx < 9; ++dx) {
        if (graph[y][dx] == value) {
            return false;
        }
    }
    
    for (int dy = 0; dy < 9; ++dy) {
        if (graph[dy][x] == value) {
            return false;
        }
    }
    
    for (int dx = nx; dx < nx + 3; ++dx) {
        for (int dy = ny; dy < ny + 3; ++dy) {
            if (graph[dy][dx] == value) {
                return false;
            }
        }
    }
    
    return true;
}

void backtracking(int seq,
                  vector<pair<int, int>>& targets,
                  vector<vector<int>>& graph) {
    if (seq == targets.size()) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << graph[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    
    int x = targets[seq].first;
    int y = targets[seq].second;
    
    for (int i = 1; i <= 9; ++i) {
        if (graph[y][x] == 0 && check(x, y, i, graph)) {
            graph[y][x] = i;
            backtracking(seq + 1, targets, graph);
            graph[y][x] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    string input;
    vector<vector<int>> graph(9, vector<int>());
    vector<pair<int, int>> targets;
    
    for (int i = 0; i < 9; ++i) {
        cin >> input;
        
        for (int j = 0; j < 9; ++j) {
            char ch = input[j];
            
            if (ch == '0') {
                targets.push_back({j, i});
            }
            graph[i].push_back(ch - '0');
        }
    }
    
    backtracking(0, targets, graph);
    
    return 0;
}
