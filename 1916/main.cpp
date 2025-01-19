//
//  main.cpp
//  1916
//
//  Created by 정지용 on 1/14/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 2000000000

using namespace std;

vector<vector<pair<int, int>>> v;
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
        int cost = -pq.top().first;
        int vert = pq.top().second;
        pq.pop();
        
        if (dist[vert] < cost) continue;
        
        // v[vert][i == start] = pair<end, cost>
        for (int i = 0; i < v[vert].size(); ++i) {
            int v_cost = cost + v[vert][i].second;
            
            if (v_cost < dist[v[vert][i].first]) {
                dist[v[vert][i].first] = v_cost;
                pq.push({-v_cost, v[vert][i].first});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m;
    cin >> n >> m;
    
    dist.resize(n + 1, MAX);
    v.resize(n + 1);
    
    int s, e, c;
    
    for (int i = 0; i < m; ++i) {
        cin >> s >> e >> c;
        v[s].push_back({e, c});
    }
    
    cin >> s >> e;
    
    dijkstra(s);
    cout << dist[e];
    
    return 0;
}
