//
//  main.cpp
//  2675
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
  int t;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    int n;
    string s;
    cin >> n >> s;
    
    for (char c: s) {
      for (int j = 0; j < n; j++) { printf("%c", c); }
    }
    printf("\n");
  }
  
  return 0;
}
