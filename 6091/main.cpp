//
//  main.cpp
//  6091
//
//  Created by 정지용 on 3/19/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using vi = vector<int>;
using vsi = vector<set<int>>;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct UnionFind {
    vi parent;
    vi urank;
    
    UnionFind(int n): parent(n + 1), urank(n + 1, 0) {
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool __union(int a, int b) {
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
        } else {
            return false;
        }
    }
};

int n;
vector<Edge> edges;
vsi graph;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solution() {
    UnionFind uf(n);
    graph.resize(n + 1, set<int>());
    
    sort(edges.begin(), edges.end());
    
    int count = 0;
    for (auto edge: edges) {
        if (uf.__union(edge.u, edge.v)) {
            graph[edge.u].insert(edge.v);
            graph[edge.v].insert(edge.u);
            
            if (++count == n - 1) break;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        auto v = graph[i];
        cout << v.size() << ' ';
        for (auto s: v) {
            cout << s << ' ';
        } cout << '\n';
    }
}

void input() {
    cin >> n;
    
    int weight;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            cin >> weight;
            edges.emplace_back(i, j, weight);
        }
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
