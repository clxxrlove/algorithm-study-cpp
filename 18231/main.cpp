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
using vi = vector<int>;
using vvi = vector<vector<int>>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void bfs(const vvi& graph,
         const vector<bool>& destroyed,
         vector<bool>& visited,
         vector<int>& answer,
         int start) {
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        bool check = true;
        
        for (int pos: graph[current]) {
            if (!destroyed[pos]) {
                check = false;
                break;
            }
        }
        
        if (check) {
            answer.push_back(current);
            visited[current] = true;
            
            for (int pos: graph[current]) {
                visited[pos] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m, s, e;
    cin >> n >> m;
    
    vvi graph(n + 1, vi());
    for (int i = 0; i < m; ++i) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    int k; cin >> k;
    
    vector<bool> destroyed(n + 1, false);
    vi dcity(k);
    for (int i = 0; i < k; ++i) {
        cin >> dcity[i];
        destroyed[dcity[i]] = true;
    }
    
    vector<int> answer;
    vector<bool> visited(n + 1, false);
    for (int city: dcity) {
        if (destroyed[city]) {
            bfs(graph, destroyed, visited, answer, city);
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (visited[i] != destroyed[i]) {
            cout << -1; return 0;
        }
    }
    
    cout << answer.size() << '\n';
    for (int ans: answer) {
        cout << ans << ' ';
    }
    
    return 0;
}
