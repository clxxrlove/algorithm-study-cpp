//
//  main.cpp
//  11657
//
//  Created by 정지용 on 2/13/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

// 6 * 10^7 * 500 = 3 * 10^3 * 10^7 = 3 * 10^10
using namespace std;
using ii = pair<int, int>;
using iip = pair<int, pair<int, int>>;
using ll = long long;

const ll MAX = 1LL * 3e10 + 1;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool bellman_ford(const vector<iip>& edges,
                  vector<ll>& dists,
                  int start,
                  int n,
                  int m) {
    dists[start] = 0;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            const iip& c = edges[j];
            int from = c.first;
            int to = c.second.first;
            int cost = c.second.second;
            
            if (dists[from] == MAX) continue;
            
            if (dists[to] > dists[from] + cost) {
                dists[to] = dists[from] + cost;
                if (i == n) return false;
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m; cin >> n >> m;
    vector<iip> edges;
    vector<ll> dists(n + 1, MAX);
    
    for (int i = 0; i < m; ++i) {
        int start, end, cost;
        cin >> start >> end >> cost;
        
        edges.push_back({start, {end, cost}});
    }
    
    bool flag = bellman_ford(edges, dists, 1, n, m);
    if (!flag) {
        cout << -1; return 0;
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << (dists[i] != MAX ? dists[i] : -1) << '\n';
    }
    
    return 0;
}
