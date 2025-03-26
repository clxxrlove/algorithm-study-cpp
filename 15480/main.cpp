//
//  main.cpp
//  15480
//
//  Created by 정지용 on 3/26/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

struct Query {
    int r, u, v;
    Query(int r, int u, int v): r(r), u(u), v(v) {}
};

using ve = vector<Query>;

int n, m;
const int LOG = 17;
vvi tr;
vvi anc;
vi d;
ve q;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    
    tr.resize(n + 1);
    anc.resize(n + 1, vi(LOG, 0));
    d.resize(n + 1, 0); --d[0];
    
    int s, e, x;
    for (int i = 0; i < n - 1; ++i) {
        cin >> s >> e;
        tr[s].push_back(e);
        tr[e].push_back(s);
    }
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s >> e >> x;
        q.emplace_back(s, e, x);
    }
}

void dfs(int u, int p) {
    d[u] = d[p] + 1;
    anc[u][0] = p;
    
    for (int i = 1; i < LOG; ++i) {
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    }
    
    for (auto& v: tr[u]) {
        if (v != p)
            dfs(v, u);
    }
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    
    for (int i = LOG - 1; i >= 0; --i) {
        if (d[u] - (1 << i) >= d[v])
            u = anc[u][i];
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

int max_depth(int a, int b, int c) {
    if (d[a] >= d[b] && d[a] >= d[c]) return a;
    else if (d[b] >= d[a] && d[b] >= d[c]) return b;
    else return c;
}

void solution() {
    dfs(1, 0);
    for (auto& [r, u, v]: q) {
        cout << max_depth(lca(r, u), lca(r, v), lca(u, v)) << '\n';
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
