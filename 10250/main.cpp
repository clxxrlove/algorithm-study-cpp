//
//  main.cpp
//  10250
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
  int t;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    int h, w, n;
    cin >> h >> w >> n;
    int f = n % h;
    int r = f == 0 ? n / h : n / h + 1;
    printf("%d%02d\n", f == 0 ? h : n % h, r);
  }
  
  return 0;
}
