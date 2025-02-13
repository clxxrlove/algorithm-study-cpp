//
//  main.cpp
//  1865
//
//  Created by 정지용 on 2/13/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using iip = pair<int, pair<int, int>>;
using ll = long long;

const ll MAX = 2e10; // 1.25e10이 최악

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool bellman_ford(const vector<iip>& graph,
                  vector<ll>& dists,
                  int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < graph.size(); ++j) {
            const iip& c = graph[j];
            int from = c.first;
            int to = c.second.first;
            int cost = c.second.second;
            
            if (dists[to] > dists[from] + cost) {
                dists[to] = dists[from] + cost;
                if (i == n) return true;
            }
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    setDefault();
    int t; cin >> t;
    
    for (int _ = 0; _ < t; ++_) {
        int n, m, w;
        cin >> n >> m >> w;
        
        vector<iip> graph;
        vector<ll> dists(n + 1, MAX);
        dists[0] = dists[1] = 0;
        
        int s, e, t;
        for (int i = 0; i < m; ++i) {
            cin >> s >> e >> t;
            graph.push_back({s, {e, t}});
            graph.push_back({e, {s, t}});
        }
        for (int i = 0; i < w; ++i) {
            cin >> s >> e >> t;
            graph.push_back({s, {e, -t}});
        }
        
        bool flag = bellman_ford(graph, dists, n);
        cout << (flag ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
