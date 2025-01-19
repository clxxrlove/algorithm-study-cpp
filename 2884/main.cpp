//
//  main.cpp
//  2884
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
  int hh, mm;
  cin >> hh >> mm;
  
  if (mm - 45 < 0) {
    if (hh - 1 < 0) {
      printf("%d %d", 23, 60 + mm - 45);
    } else {
      printf("%d %d", hh - 1, 60 + mm - 45);
    }
  } else {
    printf("%d %d", hh, mm - 45);
  }
  
  return 0;
}
