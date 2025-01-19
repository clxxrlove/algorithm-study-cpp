//
//  main.cpp
//  21736
//
//  Created by 정지용 on 1/3/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int h, w, ans = 0;
vector<vector<char>> board;
vector<vector<bool>> visited;

class Point {
public:
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
};

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

void bfs(Point start) {
  queue<Point> q;
  q.push(start);
  visited[start.y][start.x] = true;
  
  while (!q.empty()) {
    Point f = q.front();
    q.pop();
    
    Point move[] = {
      Point(f.x + 1, f.y), Point(f.x - 1, f.y),
      Point(f.x, f.y + 1), Point(f.x, f.y - 1)
    };
    
    for (Point p: move) {
      if (p.x >= 0 && p.y >= 0 && p.x < w && p.y < h &&
          board[p.y][p.x] != 'X' && !visited[p.y][p.x]
      ) {
        if (board[p.y][p.x] == 'P') ans++;
        visited[p.y][p.x] = true;
        q.push(p);
      }
    }
  }
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  Point *start = nullptr;
  string input;
  cin >> h >> w;
  
  board.resize(h, vector<char>());
  visited.resize(h);
  
  for (int _ = 0; _ < h; _++) {
    cin >> input;
    visited[_].resize(w, false);
    
    for (char c: input) {
      if (c == 'I') {
        start = new Point(int(board[_].size()), _);
      }
      board[_].push_back(c);
    }
  }
  
  bfs(*start);
  
  if (ans) cout << ans;
  else cout << "TT";
  
  return 0;
}
