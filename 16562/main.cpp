//
//  main.cpp
//  16562
//
//  Created by 정지용 on 3/20/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vb = vector<bool>;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int n, m, k;
vector<Edge> edges;
vi cost;

struct UF {
    vi parent;
    vi urank;
    vb checked;
    
    UF(int n): parent(n + 1), urank(n + 1, 0), checked(n + 1, false) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    pair<bool, int> merge(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        
        if (fa != fb) {
            if (cost[fa] < cost[fb]) {
                parent[fb] = fa;
            } else {
                parent[fa] = fb;
            }
//            if (urank[fa] > urank[fb]) {
//                parent[fb] = fa;
//            } else if (urank[fa] < urank[fb]) {
//                parent[fa] = fb;
//            } else {
//                parent[fb] = fa;
//                ++urank[fa];
//            }
            
            if (checked[a] && checked[b]) {
                return {1, max(cost[fa], cost[fb])};
            }
            
            if (checked[a] || checked[b]) {
                checked[a] = checked[b] = true;
                return {1, 0};
            }
            
            checked[a] = checked[b] = true;
            return {1, -1};
        }
        return {0, 0};
    }
};

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n >> m >> k;
    
    cost.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> cost[i];
    
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        edges.emplace_back(u, v, min(cost[u], cost[v]));
    }
}

void solution() {
    UF uf(n);
    sort(edges.begin(), edges.end());
    
    int sum = 0;
    for (auto edge: edges) {
        auto [fi, se] = uf.merge(edge.u, edge.v);
        if (fi) {
            if (se == -1) sum += edge.w;
            else if (se) {
                sum -= se;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!uf.checked[i]) {
            sum += cost[i];
        }
    }
    
    if (sum > k) cout << "Oh no\n";
    else cout << sum << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
