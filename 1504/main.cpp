//
//  main.cpp
//  1504
//
//  Created by 정지용 on 1/17/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 2147483647

using namespace std;

void setDefualt() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dijkstra(int start, vector<int>& dist, const vector<vector<pair<int, int>>> graph) {
    fill(dist.begin(), dist.end(), MAX);
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        int v_dist = -pq.top().first;
        int v_vert = pq.top().second;
        pq.pop();
        
        if (dist[v_vert] < v_dist) continue;
        
        for (pair<int, int> e: graph[v_vert]) {
            int e_dist = v_dist + e.second;
            
            if (e_dist < dist[e.first]) {
                dist[e.first] = e_dist;
                pq.push({-e_dist, e.first});
            }
        }
    }
}

int find_shortest_path(int start,
                        int v1,
                        int v2,
                        int end,
                        vector<int>& dist,
                        const vector<vector<pair<int, int>>> graph) {
    int result = 0;
    dijkstra(start, dist, graph);
    
    if (dist[v1] == MAX) {
        return MAX;
    }
    
    result += dist[v1];
    dijkstra(v1, dist, graph);
    
    if (dist[v2] == MAX) {
        return MAX;
    }
    
    result += dist[v2];
    dijkstra(v2, dist, graph);
    
    if (dist[end] == MAX) {
        return MAX;
    }
    
    result += dist[end];
    return result;
}

int main(int argc, const char * argv[]) {
    setDefualt();
    
    int n, e;
    int a, b, ans = 0;
    cin >> n >> e;
    
    vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
    vector<int> a_dist(n + 1, MAX);
    
    int start, end, dist;
    for (int i = 0; i < e; ++i) {
        cin >> start >> end >> dist;
        graph[start].push_back({end, dist});
        graph[end].push_back({start, dist});
    }
    
    cin >> a >> b;
    ans = min(find_shortest_path(1, a, b, n, a_dist, graph), find_shortest_path(1, b, a, n, a_dist, graph));
    ans = ans == MAX ? -1 : ans;
    
    cout << ans;
    
    return 0;
}
