//
//  main.cpp
//  13549
//
//  Created by 정지용 on 1/23/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 2147483647

using namespace std;

int max_size;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dijkstra(vector<int>& dist,
              int start) {
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int v_dist = -pq.top().first;
        int vert = pq.top().second;
        pq.pop();
        
        if (dist[vert] < v_dist) continue;
        
        pair<int, int> graph[] = {{vert + 1, 1}, {vert - 1, 1}, {vert * 2, 0}};
        
        for (pair<int, int> p: graph) {
            if (p.first < 0 || p.first > max_size) continue;
            int new_dist = v_dist + p.second;
            if (new_dist < dist[p.first]) {
                dist[p.first] = new_dist;
                pq.push({-new_dist, p.first});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, k;
    cin >> n >> k;
    max_size = max(n, k) * 2 + 1;
    vector<int> dist(max_size + 1, MAX);
    
    dijkstra(dist, n);
    
    cout << dist[k];
    
    return 0;
}
