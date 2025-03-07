//
//  main.cpp
//  11779
//
//  Created by 정지용 on 3/8/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;
using vii = vector<pair<int, int>>;
using vvii = vector<vector<pair<int, int>>>;

int n, m;
const int MAX = 2e9;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

pair<int, vi> dijkstra(const vvii& edges, int start, int end) {
    priority_queue<ii, vii, greater<ii>> pq;
    vi dists(n + 1, MAX);
    vi parents(n + 1, -1);
    
    dists[start] = 0;
    pq.emplace(0, start);
    
    while (!pq.empty()) {
        int dist = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        
        if (dist > dists[vertex]) continue;
        
        for (auto [next, cost]: edges[vertex]) {
            int new_dist = cost + dist;
            if (new_dist < dists[next]) {
                dists[next] = new_dist;
                parents[next] = vertex;
                pq.emplace(new_dist, next);
            }
        }
    }
    
    vector<int> path;
    for (int v = end; v != -1; v = parents[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    
    return {dists[end], path};
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    cin >> n >> m;
    
    vvii edges(n + 1, vii());
    for (int i = 0; i < m; ++i) {
        int s, e, c;
        cin >> s >> e >> c;
        edges[s].emplace_back(e, c);
    }
    
    int start, end;
    cin >> start >> end;
    
    auto [dist, path] = dijkstra(edges, start, end);
    
    cout << dist << '\n' << path.size() << '\n';
    for (int v: path) cout << v << ' ';
    
    return 0;
}
