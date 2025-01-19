//
//  main.cpp
//  1238
//
//  Created by 정지용 on 1/16/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 2100000000

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dist;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        int qdist = -pq.top().first;
        int vert = pq.top().second;
        pq.pop();
        
        if (dist[vert] < qdist) continue;
        
        for (pair<int, int> v: graph[vert]) {
            int vdist = qdist + v.second;
            
            if (vdist < dist[v.first]) {
                dist[v.first] = vdist;
                pq.push({-vdist, v.first});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m, x;
    int s, e, c;
    int ans = 0;
    cin >> n >> m >> x;
    
    graph.resize(n + 1, vector<pair<int, int>>());
    dist.resize(n + 1, 0);
    
    for (int i = 0; i < m; ++i) {
        cin >> s >> e >> c;
        graph[s].push_back({e, c});
    }
    
    int tmp = 0;
    for (int i = 1; i <= n; ++i) {
        fill(dist.begin(), dist.end(), MAX);
        dijkstra(i);
        tmp += dist[x];
        fill(dist.begin(), dist.end(), MAX);
        dijkstra(x);
        tmp += dist[i];
        ans = max(ans, tmp);
        tmp = 0;
    }
    
    cout << ans;
    
    return 0;
}
