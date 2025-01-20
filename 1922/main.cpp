//
//  main.cpp
//  1922
//
//  Created by 정지용 on 1/20/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void prim(const vector<vector<pair<int, int>>>& graph,
          vector<bool>& visited,
          int start,
          int& answer) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int weight = -pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        
        if (visited[vertex]) continue;
        
        answer += weight;
        visited[vertex] = true;
        
        for (pair<int, int> edge: graph[vertex]) {
            if (!visited[edge.first]) {
                pq.push({-edge.second, edge.first});
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int v, e;
    cin >> v >> e;
    
    vector<vector<pair<int, int>>> graph(v + 1, vector<pair<int, int>>());
    vector<bool> visited(v + 1, false);
    
    int start, end, weight;
    for (int i = 0; i < e; ++i) {
        cin >> start >> end >> weight;
        
        graph[start].push_back({end, weight});
        graph[end].push_back({start, weight});
    }
    
    int answer = 0;
    prim(graph, visited, 1, answer);
    
    cout << answer;
    
    return 0;
}
