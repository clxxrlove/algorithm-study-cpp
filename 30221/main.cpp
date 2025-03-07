//
//  main.cpp
//  30221
//
//  Created by 정지용 on 3/8/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
using vi = vector<int>;

int n, m;
const int MAX = 2e9;

struct Pos {
    int x, y, cost;
    Pos(int x, int y, int cost): x(x), y(y), cost(cost) {}
};

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void bellman_ford(vector<Pos>& edges, vi& dists) {
    dists[1] = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        for (auto edge: edges) {
            int start = edge.x;
            int end = edge.y;
            int dist = edge.cost;
            
            if (dists[start] == MAX) continue;
            if (dists[end] > dist + dists[start]) {
                dists[end] = dist + dists[start];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    cin >> n >> m;
    vector<Pos> edges;
    for (int i = 0; i < m; ++i) {
        int s, e, c;
        char t;
        cin >> s >> e >> t >> c;
        if (t == 'r') c = -c;
        
        edges.emplace_back(s, e, c);
    }
    
    vi dists(n + 1, MAX);
    bellman_ford(edges, dists);
    
    for (int i = 1; i <= n; ++i) {
        if (dists[i] < 0) cout << i << '\n';
    }
    
    return 0;
}
