//
//  main.cpp
//  2577
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  string mul = to_string(a * b * c);
  vector<int> ans(10, 0);
  
  for (char c: mul) {
    ans[c - '0'] += 1;
  }
  
  for (int a: ans) {
    printf("%d\n", a);
  }
  
  return 0;
}
