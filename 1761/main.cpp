//
//  main.cpp
//  1761
//
//  Created by 정지용 on 3/25/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

#define fi first
#define se second

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;

int n, m;
const int LOG = 16;
vvii tree;
vvi ancestor;
vi depth;
vi dist;
vii q;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    
    tree.resize(n + 1, vii());
    depth.resize(n + 1, 0);
    depth[0] = -1;
    
    dist.resize(n + 1, 0);
    ancestor.resize(n + 1, vi(LOG, 0));
    
    int s, e, x;
    for (int i = 0; i < n - 1; ++i) {
        cin >> s >> e >> x;
        tree[s].emplace_back(e, x);
        tree[e].emplace_back(s, x);
    }
    
    cin >> m;
    
    for (int i = 0; i < m; ++i) {
        cin >> s >> e;
        q.emplace_back(s, e);
    }
}

void dfs(int u, int parent, int weight) {
    dist[u] = dist[parent] + weight;
    ancestor[u][0] = parent;
    depth[u] = depth[parent] + 1;
    
    for (int i = 1; i < LOG; ++i) {
        int node = ancestor[u][i - 1];
        ancestor[u][i] = ancestor[node][i - 1];
    }
    
    for (auto& [v, w]: tree[u]) {
        if (v != parent) {
            dfs(v, u, w);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    /// 높이 맞추기
    for (int i = LOG - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = ancestor[u][i];
        }
    }
    
    if (u == v) return dist[u];
    /// 조상 찾기
    for (int i = LOG - 1; i >= 0; --i) {
        if (ancestor[u][i] != ancestor[v][i]) {
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }
    
    return dist[ancestor[u][0]];
}

void solution() {
    dfs(1, 0, 0);
    
    for (auto& [u, v]: q) {
        cout << dist[u] + dist[v] - lca(u, v) * 2 << '\n';
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
