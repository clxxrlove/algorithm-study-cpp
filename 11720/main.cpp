//
//  main.cpp
//  11720
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
  int n, result = 0;
  string input;
  cin >> n >> input;
  
  for (char c: input) {
    result += c - '0';
  }
  
  printf("%d", result);
  return 0;
}
