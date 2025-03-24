//
//  main.cpp
//  3176
//
//  Created by 정지용 on 3/24/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

#define fi first
#define se second
#define ROOT 1

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;

int n, m;
const int LOG = 17;
vvii tree;
vii q;
vvi ancestor;
vvi min_anc;
vvi max_anc;
vi depth;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    
    int u, v, w;
    tree.resize(n + 1, vii());
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v >> w;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        q.emplace_back(u, v);
    }
    
    depth.resize(n + 1);
    ancestor.resize(n + 1, vi(LOG, 0));
    min_anc.resize(n + 1, vi(LOG, 0));
    max_anc.resize(n + 1, vi(LOG, 0));
}

void dfs(int u, int parent, int weight) {
    ancestor[u][0] = parent;
    min_anc[u][0] = max_anc[u][0] = weight;
    
    for (int i = 1; i < LOG; ++i) {
        int node = ancestor[u][i - 1];
        ancestor[u][i] = ancestor[node][i - 1];
        min_anc[u][i] = min(min_anc[u][i - 1], min_anc[node][i - 1]);
        max_anc[u][i] = max(max_anc[u][i - 1], max_anc[node][i - 1]);
    }
    
    for (auto& [v, w]: tree[u]) {
        if (v != parent) {
            depth[v] = depth[u] + 1;
            dfs(v, u, w);
        }
    }
}

pair<int, int> lca(int u, int v) {
    int __max = INT_MIN;
    int __min = INT_MAX;
    
    if (depth[u] < depth[v]) swap(u, v);
    
    for (int i = LOG - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            __max = max(__max, max_anc[u][i]);
            __min = min(__min, min_anc[u][i]);
            u = ancestor[u][i];
        }
    }
    
    if (u == v) return {__max, __min};
    for (int i = LOG - 1; i >= 0; --i) {
        if (ancestor[u][i] != ancestor[v][i]) {
            __max = max({__max, max_anc[u][i], max_anc[v][i]});
            __min = min({__min, min_anc[u][i], min_anc[v][i]});
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }
    
    __max = max({__max, max_anc[u][0], max_anc[v][0]});
    __min = min({__min, min_anc[u][0], min_anc[v][0]});
    
    return {__max, __min};
}

void solution() {
    dfs(ROOT, 0, 0);
    
    for (auto& v: q) {
        auto [__max, __min] = lca(v.fi, v.se);
        cout << __min << ' ' << __max << '\n';
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
