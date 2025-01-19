//
//  main.cpp
//  10816
//
//  Created by 정지용 on 1/2/25.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

int main(int argc, const char * argv[]) {
  int n, m;
  string ns, ms;
  unordered_map<int, int> um;
  
  cin >> n;
  cin.ignore();
  
  getline(cin, ns);
  
  cin >> m;
  cin.ignore();
  
  getline(cin, ms);
  
  istringstream nst(ns), mst(ms);
  int tmp;
  
  while (nst >> tmp) {
    um[tmp] += 1;
  }
  
  while (mst >> tmp) {
    printf("%d ", um[tmp]);
  }
  
  return 0;
}
