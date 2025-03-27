//
//  main.cpp
//  23355
//
//  Created by 정지용 on 3/27/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

struct Query {
    int i, j, k, l;
    Query(int i, int j, int k): i(i), j(j), k(k), l(-1) {}
    Query(int i, int j, int k, int l): i(i), j(j), k(k), l(l) {}
};

using vq = vector<Query>;

int n, m;
const int LOG = 18;
vvi tree;
vvi anc;
vi depth;
vq q;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    
    tree.resize(n + 1);
    anc.resize(n + 1, vi(LOG, 0));
    depth.resize(n + 1, 0);
    --depth[0];
    
    int s, e, x, y;
    for (int i = 0; i < n - 1; ++i) {
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    
    cin >> m;
    int t;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> s >> e >> x;
            q.emplace_back(s, e, x);
        } else {
            cin >> s >> e >> x >> y;
            q.emplace_back(s, e, x, y);
        }
    }
}

void dfs(int u, int parent) {
    depth[u] = depth[parent] + 1;
    anc[u][0] = parent;
    
    for (int i = 1; i < LOG; ++i) {
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    }
    
    for (auto& v: tree[u]) {
        if (v != parent) dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    for (int i = LOG - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = anc[u][i];
        }
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

bool check1(int i, int j, int k) {
    int ij = lca(i, j);
    return (lca(i, k) == k || lca(j, k) == k) && (depth[k] >= depth[ij]);
}

bool check2(int i, int j, int k, int l) {
    return !(check1(i, j, k) && check1(i, j, l));
}

void solution() {
    dfs(1, 0);
    
    for (auto [i, j, k, l]: q) {
        bool flag = true;
        if (l == -1) {
            flag = !check1(i, j, k);
        } else {
            flag = check2(i, j, k, l);
        }
        
        cout << (flag ? "YES" : "NO") << '\n';
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
