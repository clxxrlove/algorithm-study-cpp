//
//  main.cpp
//  11650
//
//  Created by 정지용 on 1/1/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Point {
public:
  int x;
  int y;
  
  Point(int x, int y): x(x), y(y) {}
  
  bool operator<(const Point& other) const {
    if (x == other.x) {
      return y < other.y;
    }
    return x < other.x;
  }
};

int main(int argc, const char * argv[]) {
  int n;
  cin >> n;
  vector<Point> p;
  
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    
    p.push_back(Point(x, y));
  }
  
  sort(p.begin(), p.end());
  
  for (Point pt: p) {
    printf("%d %d\n", pt.x, pt.y);
  }
  
  return 0;
}
