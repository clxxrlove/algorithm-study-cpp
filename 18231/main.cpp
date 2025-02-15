//
//  main.cpp
//  18231
//
//  Created by 정지용 on 2/16/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int _find(int a, vector<int>& parent) {
    if (a != parent[a]) {
        parent[a] = _find(parent[a], parent);
    }
    return parent[a];
}

void _union(int a, int b, vector<int>& parent, vector<int>& urank) {
    int fa = _find(a, parent);
    int fb = _find(b, parent);
    
    if (urank[fa] > urank[fb]) {
        parent[fb] = fa;
    } else if (urank[fa] < urank[fb]) {
        parent[fa] = fb;
    } else {
        parent[fb] = fa;
        ++urank[fa];
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m, s, e;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    int k; cin >> k;
    
    vector<bool> destroyed(n + 1, false);
    vector<int> dcity(k);
    for (int i = 0; i < k; ++i) {
        cin >> dcity[i];
        destroyed[dcity[i]] = true;
    }
    
    vector<int> parent(n + 1);
    vector<int> urank(n + 1, 0);
    for (int i = 1; i <= n; ++i) parent[i] = i;
    for (int city: dcity) {
        for (int neighbor: graph[city]) {
            if (destroyed[neighbor]) {
                _union(city, neighbor, parent, urank);
            }
        }
    }
    
    set<int> bomb_sites;
    set<int> visited;
    queue<int> q;

    for (int city: dcity) {
        int root = _find(city, parent);
        if (visited.count(root)) continue;  // 이미 선택된 루트는 스킵
        visited.insert(root);
        
        // 🔹 BFS를 이용하여 최소한의 폭탄 위치 찾기
        q.push(root);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (destroyed[curr]) {
                bomb_sites.insert(curr);
                break;  // 해당 연결 요소에서 하나만 선택하면 됨
            }
            
            for (int neighbor: graph[curr]) {
                if (destroyed[neighbor] && !bomb_sites.count(neighbor)) {
                    bomb_sites.insert(neighbor);
                    break;
                }
                q.push(neighbor);
            }
        }
    }
    
    for (int tmp: bomb_sites) cout << tmp << " ";
    
    return 0;
}
