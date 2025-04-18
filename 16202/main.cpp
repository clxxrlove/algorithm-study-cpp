//
//  main.cpp
//  16202
//
//  Created by 정지용 on 3/19/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
using vi = vector<int>;

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

int n, m, k;
deque<Edge> edges;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n >> m >> k;
    
    int start, end;
    for (int i = 0; i < m; ++i) {
        cin >> start >> end;
        edges.emplace_back(start, end, i + 1);
    }
}

void kruskal() {
    UnionFind uf(n);
    
    int count = 0;
    int answer = 0;
    for (auto edge: edges) {
        if (uf.__union(edge.u, edge.v)) {
            answer += edge.w;
            if (++count == n - 1) {
                cout << answer << ' ';
                return;
            }
        }
    }
    
    cout << 0 << ' ';
}

void solution() {
    while (k--) {
        kruskal();
        edges.pop_front();
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
