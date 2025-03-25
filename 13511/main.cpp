//
//  main.cpp
//  13511
//
//  Created by 정지용 on 3/25/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

#define fi first
#define se second

using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;

struct Query {
    int u, v, n;
    Query(int u, int v, int n): u(u), v(v), n(n) {}
};

int n, m;
const int LOG = 17;
vvii tree;
vvi ancestor;
vi depth;
vll dist;
vector<Query> q;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    
    tree.resize(n + 1);
    ancestor.resize(n + 1, vi(LOG, 0));
    depth.resize(n + 1, 0);
    depth[0] = -1;
    dist.resize(n + 1, 0);
    
    int s, e, x;
    for (int i = 0; i < n - 1; ++i) {
        cin >> s >> e >> x;
        tree[s].emplace_back(e, x);
        tree[e].emplace_back(s, x);
    }
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        if (s == 1) {
            cin >> s >> e;
            q.emplace_back(s, e, -1);
        } else {
            cin >> s >> e >> x;
            q.emplace_back(s, e, x);
        }
    }
}

void dfs(int u, int parent, int weight) {
    depth[u] = depth[parent] + 1;
    dist[u] = dist[parent] + weight;
    ancestor[u][0] = parent;
    
    for (int i = 1; i < LOG; ++i) {
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
    }
    
    for (auto& [v, w]: tree[u]) {
        if (v != parent) dfs(v, u, w);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    for (int i = LOG - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) u = ancestor[u][i];
    }
    
    if (u == v) return u;
    
    for (int i = LOG - 1; i >= 0; --i) {
        if (ancestor[u][i] != ancestor[v][i]) {
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }
    
    return ancestor[u][0];
}

int lifting(int u, int len) {
    for (int i = LOG - 1; i >= 0; --i) {
        if (len >= (1 << i)) {
            u = ancestor[u][i];
            len -= (1 << i);
        }
    }
    
    return u;
}

void solution() {
    dfs(1, 0, 0);
    
    for (auto [u, v, k]: q) {
        int node = lca(u, v);
        // 1번 Query
        if (k == -1) {
            cout << dist[u] + dist[v] - dist[node] * 2 << '\n';
        } else {
            int du = depth[u] - depth[node];
            int dv = depth[v] - depth[node];
            int total_len = du + dv + 1;

            if (k <= du + 1) {
                cout << lifting(u, k - 1) << '\n';
            } else {
                int remain = total_len - k;
                cout << lifting(v, remain) << '\n';
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
