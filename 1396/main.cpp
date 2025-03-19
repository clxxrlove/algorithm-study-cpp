//
//  main.cpp
//  1396
//
//  Created by 정지용 on 3/19/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<pair<int, int>>;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct Query {
    int u, v;
    int lo, hi;
    Query(int u, int v, int lo, int hi): u(u), v(v), lo(lo), hi(hi) {}
};

struct UF {
    vi parent;
    vi urank;
    vi usize;
    
    UF(int n): parent(n + 1), urank(n + 1, 0), usize(n + 1, 1) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a != b) {
            if (urank[a] > urank[b]) {
                parent[b] = a;
                usize[a] += usize[b];
            } else if (urank[a] < urank[b]) {
                parent[a] = b;
                usize[b] += usize[a];
            } else {
                parent[b] = a;
                usize[a] += usize[b];
                ++urank[a];
            }
        }
    }
};

int n, m, q;
vector<Edge> edges;
vector<Query> queries;
vii answer;
vi g[100001];

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n >> m;
    
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> u >> v;
        queries.emplace_back(u, v, 0, m - 1);
    }
    
    answer.resize(q, {0, 0});
}

void solution() {
    sort(edges.begin(), edges.end());
    
    while (true) {
        bool flag = false;
        for (int i = 0; i <= 100000; ++i) g[i].clear();
        for (int i = 0; i < q; ++i) {
            auto qr = queries[i];
            if (qr.lo <= qr.hi) {
                g[(qr.lo + qr.hi) / 2].push_back(i);
                flag = true;
            }
        }
        if (!flag) break;
        
        UF uf(n);
        for (int i = 0; i < m; ++i) {
            auto edge = edges[i];
            uf.merge(edge.u, edge.v);
            
            for (auto j: g[i]) {
                auto& qr = queries[j];
                if (uf.find(qr.u) == uf.find(qr.v)) {
                    qr.hi = i - 1;
                    answer[j] = {edge.w, uf.usize[uf.parent[qr.u]]};
                } else {
                    qr.lo = i + 1;
                }
            }
        }
    }
    
    for (int i = 0; i < q; ++i) {
        if (!answer[i].first) {
            cout << -1 << '\n'; continue;
        }
        cout << answer[i].first << ' ' << answer[i].second << '\n';
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
