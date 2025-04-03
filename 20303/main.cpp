//
//  main.cpp
//  20303
//
//  Created by 정지용 on 4/3/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

struct UF {
    vi parent;
    vi urank;
    vi count;
    vi value;
    
    UF(int n): parent(n + 1), urank(n + 1, 0), count(n + 1, 1), value(n + 1, 0) {
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
                value[a] += value[b];
                count[a] += count[b];
            } else if (urank[a] < urank[b]) {
                parent[a] = b;
                value[b] += value[a];
                count[b] += count[a];
            } else {
                parent[b] = a;
                value[a] += value[b];
                count[a] += count[b];
                ++urank[a];
            }
        }
    }
};

int n, m, k;
vi v;
vii edge;
map<int, ii> mp;
vi dp;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n >> m >> k;
    
    v.resize(n + 1);
    edge.resize(m);
    dp.resize(k, 0);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 0; i < m; ++i) cin >> edge[i].first >> edge[i].second;
}

void solution() {
    UF uf(n);
    
    for (int i = 1; i <= n; ++i) uf.value[i] = v[i];
    for (auto& e: edge) {
        uf.merge(e.first, e.second);
    }
    
    for (int i = 1; i <= n; ++i) {
        int p = uf.find(i);
        if (p == i) mp[p] = {uf.count[p], uf.value[p]};
    }
    
    for (auto& m: mp) {
        auto [w, v] = m.second;
        for (int i = k - 1; i >= w; --i) {
            dp[i] = max(dp[i - w] + v, dp[i]);
        }
    }
    
    cout << dp[k - 1];
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
