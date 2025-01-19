//
//  main.cpp
//  31403
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
  string a, b, c;
  cin >> a >> b >> c;
  
  printf("%d\n", stoi(a) + stoi(b) - stoi(c));
  printf("%d\n", stoi(a + b) - stoi(c));
  return 0;
}
