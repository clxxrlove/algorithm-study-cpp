//
//  main.cpp
//  2606
//
//  Created by 정지용 on 1/2/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int answer = 0;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

void bfs(int start) {
  queue<int> q;
  visited[start] = true;
  q.push(start);
  
  while (!q.empty()) {
    int nx = q.front();
    q.pop();
    
    for (int qx: graph[nx]) {
      if (!visited[qx]) {
        visited[qx] = true;
        q.push(qx);
        answer++;
      }
    }
  }
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  int n, m, x, y;
  cin >> n >> m;
  
  graph.resize(n + 1, vector<int>());
  visited.resize(n + 1, false);
  
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  
  bfs(1);
  cout << answer;
  
  return 0;
}
