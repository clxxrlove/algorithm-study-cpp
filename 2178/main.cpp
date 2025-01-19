//
//  main.cpp
//  2178
//
//  Created by 정지용 on 1/4/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Point {
public:
  int x, y, count;
  
  Point(
    int x,
    int y,
    int count
  ): x(x), y(y), count(count) {}
};

int h, w, ans = 10000;
vector<vector<int>> graph;
vector<vector<bool>> visited;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

void bfs() {
  queue<Point> q;
  visited[0][0] = true;
  q.push(Point(0, 0, 1));
  
  while (!q.empty()) {
    Point p = q.front();
    q.pop();
    
    if (p.x == w - 1 && p.y == h - 1) {
      ans = min(ans, p.count);
    }
    
    Point move[] = {
      Point(p.x + 1, p.y, p.count + 1), Point(p.x - 1, p.y, p.count + 1),
      Point(p.x, p.y + 1, p.count + 1), Point(p.x, p.y - 1, p.count + 1)
    };
    
    for (Point qp: move) {
      if (qp.x >= 0 && qp.y >= 0 && qp.x < w && qp.y < h &&
          !visited[qp.y][qp.x] && graph[qp.y][qp.x] == 1) {
        visited[qp.y][qp.x] = true;
        q.push(qp);
      }
    }
  }
}

int main(int argc, const char * argv[]) {
  cin >> h >> w;
  string input;
  
  graph.resize(h, vector<int>());
  visited.resize(h);
  
  for (int i = 0; i < h; i++) {
    cin >> input;
    visited[i].resize(w, false);
    
    for (char c: input) {
      graph[i].push_back(c == '1' ? 1 : 0);
    }
  }
  
  bfs();
  cout << ans;
  
  return 0;
}
