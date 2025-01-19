//
//  main.cpp
//  2439
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
  int n;
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    for (int j = i; j < n; j++) { printf(" "); }
    for (int j = n - i; j < n; j++) { printf("*"); }
    printf("\n");
  }
  
  return 0;
}
