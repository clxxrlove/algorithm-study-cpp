//
//  main.cpp
//  11279
//
//  Created by 정지용 on 1/3/25.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  int n, tmp;
  priority_queue<int> pq;
  cin >> n;
  
  for (int _ = 0; _ < n; _++) {
    cin >> tmp;
    if (!tmp && !pq.empty()) {
      cout << pq.top() << "\n";
      pq.pop();
    } else if (!tmp && pq.empty()) {
      cout << 0 << "\n";
    } else {
      pq.push(tmp);
    }
  }
  
  return 0;
}
