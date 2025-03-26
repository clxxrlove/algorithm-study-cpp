//
//  main.cpp
//  8012
//
//  Created by 정지용 on 3/26/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;
using vii = vector<pair<int, int>>;

int n, m;
const int LOG = 15;
vvi tree;
vi depth;
vvi ancestor;
vii q;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    
    tree.resize(n + 1);
    depth.resize(n + 1, 0);
    depth[0] = -1;
    ancestor.resize(n + 1, vi(LOG, 0));
    
    int s, e;
    for (int i = 0; i < n - 1; ++i) {
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    
    cin >> m;
    vi dest(m + 1, 1);
    for (int i = 0; i < m; ++i) cin >> dest[i + 1];
    for (int i = 0; i < m; ++i) {
        q.emplace_back(dest[i], dest[i + 1]);
    }
}

void dfs(int u, int parent) {
    depth[u] = depth[parent] + 1;
    ancestor[u][0] = parent;
    
    for (int i = 1; i < LOG; ++i) {
        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
    }
    
    for (auto& v: tree[u]) {
        if (v != parent) {
            dfs(v, u);
        }
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

void solution() {
    dfs(1, 0);
    
    int answer = 0;
    for (auto& [u, v]: q) {
        answer += depth[u] + depth[v] - depth[lca(u, v)] * 2;
    }
    
    cout << answer << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
