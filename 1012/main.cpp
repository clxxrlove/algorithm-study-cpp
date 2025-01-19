//
//  main.cpp
//  1012
//
//  Created by 정지용 on 1/2/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
int m, n, k;

class Point {
public:
  int x;
  int y;
  
  Point(int x, int y): x(x), y(y) {}
};

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

void bfs(int x, int y) {
  queue<Point> q;
  q.push(Point(x, y));
  graph[y][x] = 0;
  
  while (!q.empty()) {
    Point v = q.front();
    q.pop();
    
    Point va[] = {
      Point(v.x + 1, v.y), Point(v.x - 1, v.y),
      Point(v.x, v.y + 1), Point(v.x, v.y - 1)
    };
    
    for (Point& qp: va) {
      if (qp.x >= 0 && qp.x < m && qp.y >= 0 && qp.y < n) {
        if (graph[qp.y][qp.x] == 1) {
          graph[qp.y][qp.x] = 0;
          q.push(Point(qp.x, qp.y));
        }
      }
    }
  }
}

void debugBoard() {
  for (int x = 0; x < m; x++) {
    for (int y = 0; y < n; y++) {
      cout << graph[y][x] << " \n";
    }
  }
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  int t;
  int ix, iy;
  
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    int count = 0;
    
    cin >> m >> n >> k;
    graph.resize(n);
    
    for (int j = 0; j < n; j++) {
      graph[j].resize(m);
      fill(graph[j].begin(), graph[j].end(), 0);
    }
    
    for (int j = 0; j < k; j++) {
      cin >> ix >> iy;
      graph[iy][ix] = 1;
    }
    
    for (int x = 0; x < m; x++) {
      for (int y = 0; y < n; y++) {
        if (graph[y][x] == 1) {
          bfs(x, y);
          count++;
        }
      }
    }
    
    cout << count << "\n";
  }
  
  return 0;
}
