//
//  main.cpp
//  1927
//
//  Created by 정지용 on 1/2/25.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  int n, tmp;
  priority_queue<int> pq;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (tmp == 0) {
      if (pq.empty()) {
        cout << 0 << "\n";
        continue;
      }
      cout << -pq.top() << "\n";
      pq.pop();
    } else {
      pq.push(-tmp);
    }
  }
  
  return 0;
}
