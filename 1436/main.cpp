//
//  main.cpp
//  1436
//
//  Created by 정지용 on 12/31/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
  int t, n = 0, count = 0;
  cin >> t;
  
  while (count < t) {
    string s = to_string(n);
    if (s.find("666") != string::npos) {
      count++;
    }
    n++;
  }
  
  printf("%d", n - 1);
  return 0;
}
