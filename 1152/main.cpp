//
//  main.cpp
//  1152
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[]) {
  string s, tmp;
  int ans = 0;
  getline(cin, s);
  istringstream stream(s);
  
  while (stream >> tmp) { ++ans; }
  printf("%d", ans);
  return 0;
}
