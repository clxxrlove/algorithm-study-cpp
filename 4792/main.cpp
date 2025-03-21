//
//  main.cpp
//  4792
//
//  Created by 정지용 on 3/21/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

using ve = vector<Edge>;

struct UF {
    vi parent;
    vi urank;
    
    UF(int n): parent(n + 1), urank(n + 1, 0) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a != b) {
            if (urank[a] > urank[b]) {
                parent[b] = a;
            } else if (urank[a] < urank[b]) {
                parent[a] = b;
            } else {
                parent[b] = a;
                ++urank[a];
            }
            return true;
        }
        return false;
    }
};

int n, m, k;
ve r;
ve b;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool input() {
    cin >> n >> m >> k;
    if (n == 0 && m == 0 && k == 0) return false;
    
    r.clear();
    b.clear();
    
    char c; int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> c >> u >> v;
        if (c == 'R') {
            r.emplace_back(u, v, 0);
            b.emplace_back(u, v, 1);
        } else {
            r.emplace_back(u, v, 1);
            b.emplace_back(u, v, 0);
        }
    }
    
    return true;
}

void solution() {
    UF uf(n);
    
    sort(r.begin(), r.end());
    sort(b.begin(), b.end());
    
    int b_min = 0;
    int b_max = 0;
    int cnt = 0;
    for (auto e: r) {
        if (uf.merge(e.u, e.v)) {
            b_min += e.w;
            
            if (++cnt == n - 1) break;
        }
    }
    
    uf = UF(n);
    cnt = 0;
    for (auto e: b) {
        if (uf.merge(e.u, e.v)) {
            b_max += e.w;
            
            if (++cnt == n - 1) break;
        }
    }
    
    b_max = n - 1 - b_max;
    if (k >= b_min && k <= b_max) cout << 1 << '\n';
    else cout << 0 << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    while (true) {
        if (!input()) return 0;
        solution();
    }
    
    return 0;
}
