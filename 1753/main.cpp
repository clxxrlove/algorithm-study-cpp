//
//  main.cpp
//  1753
//
//  Created by 정지용 on 1/18/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 2147483647

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dijkstra(int start,
              const vector<vector<pair<int, int>>>& graph,
              vector<int>& dist) {
    fill(dist.begin(), dist.end(), MAX);
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        int v_dist = -pq.top().first;
        int v_vert = pq.top().second;
        pq.pop();
        
        if (dist[v_vert] < v_dist) continue;
        
        for (pair<int, int> v: graph[v_vert]) {
            int new_dist = v_dist + v.second;
            
            if (new_dist < dist[v.first]) {
                dist[v.first] = new_dist;
                pq.push({-new_dist, v.first});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    int v, e, k;
    cin >> v >> e >> k;
    
    vector<vector<pair<int, int>>> graph(v + 1, vector<pair<int, int>>());
    vector<int> dist(v + 1, MAX);
    
    int start, end, cost;
    for (int i = 0; i < e; ++i) {
        cin >> start >> end >> cost;
        graph[start].push_back({end, cost});
    }
    
    dijkstra(k, graph, dist);
    
    for (int i = 1; i <= v; ++i) {
        if (dist[i] == MAX) {
            cout << "INF" << "\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
    
    return 0;
}
