//
//  main.cpp
//  11085
//
//  Created by 정지용 on 3/20/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator<(const Edge& other) const {
        return w > other.w;
    }
};

struct UF {
    vi parent;
    vi urank;
    
    UF(int n): parent(n + 1), urank(n + 1, 0) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a != b) {
            if (urank[a] > urank[b]) {
                parent[b] = a;
            } else if (urank[a] < urank[b]) {
                parent[a] = b;
            } else {
                parent[b] = a;
                ++urank[a];
            }
            return true;
        }
        return false;
    }
};

int n, m, s, e;
vector<Edge> edges;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n >> m >> s >> e;
    
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
}

void solution() {
    UF uf(n);
    sort(edges.begin(), edges.end());
    
    for (auto& edge: edges) {
        if (uf.merge(edge.u, edge.v)) {
            if (uf.find(s) == uf.find(e)) {
                cout << edge.w << '\n';
                return;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
