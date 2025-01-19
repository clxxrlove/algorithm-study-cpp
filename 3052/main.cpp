//
//  main.cpp
//  3052
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>
#include <unordered_set>

using namespace std;

int main(int argc, const char * argv[]) {
  unordered_set<int> s;
  
  for (int i = 0; i < 10; i++) {
    int n;
    cin >> n;
    s.insert(n % 42);
  }
  
  printf("%zu", s.size());
  return 0;
}
