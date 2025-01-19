//
//  main.cpp
//  8958
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
  int t;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    string s;
    int ans = 0, b = 0;
    cin >> s;
    
    for (char c: s) {
      if (c == 'O') {
        ans += ++b;
      } else {
        b = 0;
      }
    }
    
    printf("%d\n", ans);
  }
  
  return 0;
}
