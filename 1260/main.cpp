//
//  main.cpp
//  1260
//
//  Created by 정지용 on 1/2/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

void dfs(int n) {
  visited[n] = true;
  cout << n << " ";
  for (int sn: graph[n]) {
    if (!visited[sn]) {
      dfs(sn);
    }
  }
}

void bfs(int start) {
  queue<int> q;
  visited[start] = true;
  q.push(start);
  
  while(!q.empty()) {
    int n = q.front();
    q.pop();
    cout << n << " ";
    
    for (int qn: graph[n]) {
      if (!visited[qn]) {
        q.push(qn);
        visited[qn] = true;
      }
    }
  }
}

int main(int argc, const char * argv[]) {
  int n, m, v;
  int v1, v2;
  cin >> n >> m >> v;
  
  graph.resize(n + 1);
  
  for (int i = 0; i < m; i++) {
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }
  
  for (int i = 1; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }
  
  visited.resize(n + 1, false);
  dfs(v);
  cout << "\n";
  
  fill(visited.begin(), visited.end(), false);
  bfs(v);
  cout << "\n";
  
  return 0;
}
