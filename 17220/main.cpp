//
//  main.cpp
//  17220
//
//  Created by 정지용 on 3/5/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int bfs(const vvi& graph, vi& start) {
    int answer = 0;
    queue<int> q;
    vb visited(graph.size());
    
    for (int v: start) {
        q.push(v);
        visited[v] = true;
    }
    
    while (!q.empty()) {
        int current = q.front(); q.pop();
        for (int v: graph[current]) {
            if (!visited[v]) {
                answer++;
                q.push(v);
            }
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) mp[i] = 0;
    
    vvi graph(n, vi());
    for (int i = 0; i < m; ++i) {
        char start, end;
        cin >> start >> end;
        graph[start - 65].push_back(end - 65);
        mp[end - 65]++;
    }
    
    vi start;
    for (auto m: mp) {
        if (m.second == 0) start.push_back(m.first);
    }
    
    int r; cin >> r;
    char ch;
    vi ban;
    while (r--) {
        cin >> ch;
        ban.push_back(ch - 65);
    }
    
    for (auto& g: graph) {
        for (int v: ban) {
            g.erase(remove(g.begin(), g.end(), v), g.end());
            start.erase(remove(start.begin(), start.end(), v), start.end());
        }
    }
    
    cout << bfs(graph, start);
    
    return 0;
}
