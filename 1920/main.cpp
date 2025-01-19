//
//  main.cpp
//  1920
//
//  Created by 정지용 on 1/1/25.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

// 1. SET
//
//int main(int argc, const char * argv[]) {
//  int n, m;
//  string nline, mline;
//  set<int> ns, ms;
//  
//  cin >> n;
//  cin.ignore();
//  
//  getline(cin, nline);
//  
//  cin >> m;
//  cin.ignore();
//  
//  getline(cin, mline);
//  
//  istringstream nst(nline), mst(mline);
//  int tmp;
//  
//  while (nst >> tmp) {
//    ns.insert(tmp);
//  }
//  
//  while (mst >> tmp) {
//    if (ns.find(tmp) != ns.end()) {
//      printf("1\n");
//    } else {
//      printf("0\n");
//    }
//  }
//  return 0;
//}

// 2. Binary Search
//
int main(int argc, const char * argv[]) {
  int n, m;
  string nline, mline;
  vector<int> ns;
  
  cin >> n;
  cin.ignore();
  
  getline(cin, nline);
  
  cin >> m;
  cin.ignore();
  
  getline(cin, mline);
  
  istringstream nst(nline), mst(mline);
  int tmp;
  
  while (nst >> tmp) {
    ns.push_back(tmp);
  }
  
  sort(ns.begin(), ns.end());
  
  while (mst >> tmp) {
    if (binary_search(ns.begin(), ns.end(), tmp)) {
      printf("1\n");
    } else printf("0\n");
  }
  
  return 0;
}
