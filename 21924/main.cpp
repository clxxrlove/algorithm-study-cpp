//
//  main.cpp
//  21924
//
//  Created by 정지용 on 3/11/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using ll = long long;

struct Edge {
    int start, end, weight;
    Edge(int start, int end, int weight): start(start), end(end), weight(weight) {}
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int n, m;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int __find(int x, vi& parent) {
    if (x != parent[x]) {
        parent[x] = __find(parent[x], parent);
    }
    return parent[x];
}

void __union(int a, int b, vi& parent, vi& urank) {
    int pa = __find(a, parent);
    int pb = __find(b, parent);
    
    if (urank[pa] > urank[pb]) {
        parent[pb] = pa;
    } else if (urank[pa] < urank[pb]) {
        parent[pa] = pb;
    } else {
        parent[pb] = pa;
        urank[pa]++;
    }
}

ll kruskal(vector<Edge>& edges) {
    ll result = 0, cnt = 0;
    vi parent(n + 1);
    vi urank(n + 1, 0);
    for (int i = 0; i <= n; ++i) parent[i] = i;
    sort(edges.begin(), edges.end());
    
    for (auto edge: edges) {
        if (__find(edge.start, parent) != __find(edge.end, parent)) {
            __union(edge.start, edge.end, parent, urank);
            result += 1LL * edge.weight;
            ++cnt;
            
            if (cnt == n - 1) break;
        }
    }
    
    return cnt == n - 1 ? result : -1;
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    cin >> n >> m;
    vector<Edge> edges;
    
    ll answer = 0;
    
    int s, e, w;
    for (int i = 0; i < m; ++i) {
        cin >> s >> e >> w;
        edges.emplace_back(s, e, w);
        answer += 1LL * w;
    }
    
    ll mst = kruskal(edges);
    
    if (mst == -1) cout << -1 << '\n';
    else cout << answer - mst << '\n';
    
    return 0;
}
