//
//  main.cpp
//  13905
//
//  Created by 정지용 on 3/5/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

struct Edge {
    int start, end, weight;
    Edge(int start, int end, int weight): start(start), end(end), weight(weight) {}
    
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int __find(int x, vector<int>& parent) {
    if (x != parent[x]) {
        parent[x] = __find(parent[x], parent);
    }
    return parent[x];
}

void __union(int a, int b, vector<int>& parent) {
    parent[__find(b, parent)] = __find(a, parent);
}

int bfs(int start, int end, const vector<Edge>& edges, vector<bool>& visited) {
    queue<pair<int, int>> q;
    q.emplace(start, 0);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front().first;
        int cost = q.front().second;
        q.pop();
        
        if (current == end) return cost;
//        for (
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    
    vector<Edge> edges;
    int h1, h2, k;
    for (int i = 0; i < m; ++i) {
        cin >> h1 >> h2 >> k;
        edges.emplace_back(h1, h2, k);
    }
    
    sort(edges.begin(), edges.end());
    
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; ++i) parent[i] = i;
    
    vector<Edge> result;
    int count = 0;
    for (auto& e: edges) {
        if (__find(e.start, parent) != __find(e.end, parent)) {
            __union(e.start, e.end, parent);
            result.push_back(e);
            if (++count == n - 1) break;
        }
    }
    
    return 0;
}
