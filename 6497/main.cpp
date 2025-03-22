//
//  main.cpp
//  6497
//
//  Created by 정지용 on 3/22/25.
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
        return w < other.w;
    }
};

struct UF {
    vi parent;
    vi urank;
    
    UF(int n): parent(n), urank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
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

int n, m;
vector<Edge> edges;
int sum;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool input() {
    cin >> n >> m;
    if (n == 0 && m == 0) return false;
    
    edges.clear();
    int u, v, w; sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        sum += w;
        edges.emplace_back(u, v, w);
    }
    
    return true;
}

void solution() {
    UF uf(n);
    sort(edges.begin(), edges.end());
    
    int cnt = 0;
    int w_sum = 0;
    for (auto e: edges) {
        if (uf.merge(e.u, e.v)) {
            w_sum += e.w;
            if (++cnt == n - 1) break;
        }
    }
    
    cout << sum - w_sum << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    while (input()) {
        solution();
    }
    
    return 0;
}
