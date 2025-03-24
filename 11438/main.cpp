//
//  main.cpp
//  11438
//
//  Created by 정지용 on 3/24/25.
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

int n;
const int LOG = 17;
vvi tree;
vi depth;
vvi ancestor;
int m;
vii q;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(int u, int parent) {
    depth[u] = depth[parent] + 1;
    ancestor[u][0] = parent;
    
    for (int i = 1; i < LOG; ++i) {
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
    }
    
    for (int v: tree[u]) {
        if (v != parent) dfs(v, u);
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

void input() {
    cin >> n;
    
    tree.resize(n + 1, vi());
    depth.resize(n + 1, 0);
    ancestor.resize(n + 1, vi(LOG, 0));
    
    depth[0] = -1;
    
    int s, e;
    for (int i = 0; i < n - 1; ++i) {
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s >> e;
        q.emplace_back(s, e);
    }
}

void solution() {
    dfs(1, 0);
    
    for (auto& v: q) {
        cout << lca(v.fi, v.se) << '\n';
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
