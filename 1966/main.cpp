//
//  main.cpp
//  1966
//
//  Created by 정지용 on 12/31/24.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
  int t;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    int n, m, tmp;
    string s;
    queue<int> q;
    vector<int> order;
    
    cin >> n >> m;
    cin.ignore();
    getline(cin, s);
    
    istringstream stream(s);
    
    while (stream >> tmp) {
      q.push(tmp);
      order.push_back(tmp);
    }
    
    sort(order.begin(), order.end());
    int count = 0;
    
    while (!q.empty()) {
      if (q.front() == order[order.size() - 1]) {
        order.pop_back();
        q.pop();
        count++;
        if (m == 0) { printf("%d\n", count); break; }
      } else {
        q.push(q.front());
        q.pop();
      }
      if (m - 1 < 0) {
        m = !q.empty() ? q.size() - 1 : 0;
      } else { m = m - 1; }
    }
  }
  
  return 0;
}
