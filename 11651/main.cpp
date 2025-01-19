//
//  main.cpp
//  11651
//
//  Created by 정지용 on 1/2/25.
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
    if (y == other.y) {
      return x < other.x;
    }
    return y < other.y;
  }
};

int main(int argc, const char * argv[]) {
  int n;
  cin >> n;
  vector<Point> arr;
  
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    
    arr.push_back(Point(x, y));
  }
  
  sort(arr.begin(), arr.end());
  
  for (Point& p: arr) {
    printf("%d %d\n", p.x, p.y);
  }
  
  return 0;
}
