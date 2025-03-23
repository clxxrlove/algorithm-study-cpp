//
//  main.cpp
//  3584
//
//  Created by 정지용 on 3/23/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int t, n;
int uu, vv;
const int LOG = 14; // log2 1e4 = 13.x
vvi tree;
vi depth;
vvi anc;
vi child;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(int u, int parent) {
    depth[u] = depth[parent] + 1;
    anc[u][0] = parent;
    
    for (int i = 1; i < LOG; ++i) {
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    }
    
    for (int v: tree[u]) {
        if (v != parent) dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) u = anc[u][i];
    }
    
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    
    return anc[u][0];
}

void input() {
    cin >> n;
    
    child = vi(n + 1, 0);
    depth = vi(n + 1, 0);
    depth[0] = -1;
    anc = vvi(n + 1, vi(LOG, 0));
    tree = vvi(n + 1, vi());
    for (int i = 0; i < n - 1; ++i) {
        cin >> uu >> vv;
        child[vv]++;
        tree[uu].push_back(vv);
    }
    cin >> uu >> vv;
}

void solution() {
    int parent = -1;
    for (int i = 1; i <= n; ++i) {
        if (child[i] == 0) {
            parent = i;
            break;
        }
    }
    
    dfs(parent, 0);
    cout << lca(uu, vv) << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    cin >> t;
    
    while (t--) {
        input();
        solution();
    }
    
    return 0;
}
