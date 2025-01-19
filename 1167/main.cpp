//
//  main.cpp
//  1167
//
//  Created by 정지용 on 1/15/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
int max_v = 0, long_v = 0;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(int node, int sum) {
    visited[node] = true;
    if (sum > max_v) {
        max_v = sum;
        long_v = node;
    }
    
    for (pair<int, int> v: graph[node]) {
        int vnode = v.first;
        int vcost = v.second;
        
        if (!visited[vnode]) {
            dfs(vnode, sum + vcost);
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    cin >> n;
    
    graph.resize(n + 1, vector<pair<int, int>>());
    visited.resize(n + 1, false);
    
    for (int i = 0; i < n; ++i) {
        int s, e, c;
        cin >> s;
        
        while (cin >> e) {
            if (e == -1) {
                break;
            }
            cin >> c;
            graph[s].push_back({e, c});
            graph[e].push_back({s, c});
        }
    }
    
    dfs(1, 0);
    fill(visited.begin(), visited.end(), false);
    max_v = 0;
    dfs(long_v, 0);
    
    cout << max_v;
    
    return 0;
}
