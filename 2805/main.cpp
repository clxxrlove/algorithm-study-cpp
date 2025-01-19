//
//  main.cpp
//  2805
//
//  Created by 정지용 on 1/3/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  int n, m;
  long long start = 1, end = 0, mid, tmp;
  vector<int> tree;
  cin >> n >> m;
  cin.ignore();
  
  string str;
  getline(cin, str);
  istringstream ist(str);
  
  while (ist >> tmp) {
    tree.push_back(tmp);
    end = max(end, tmp);
  }
  
  while (start <= end) {
    mid = (start + end) / 2;
    tmp = 0;
    
    for (int t: tree) {
      if (t > mid) {
        tmp += t - mid;
      }
    }
    
    if (tmp >= m) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  
  cout << end;
  
  return 0;
}
