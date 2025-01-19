//
//  main.cpp
//  11286
//
//  Created by 정지용 on 1/4/25.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct CustomCompare {
  bool operator()(const tuple<int, int>& lhs, const tuple<int, int>& rhs) const {
    if (get<0>(lhs) == get<0>(rhs)) {
      return get<1>(lhs) > get<1>(rhs);
    }
    return get<0>(lhs) > get<0>(rhs);
  }
};

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  int n, input;
  cin >> n;
  
  priority_queue<
    tuple<int, int>,
    vector<tuple<int, int>>,
    CustomCompare
  > pq;
  
  for (int i = 0; i < n; i++) {
    cin >> input;
    
    if (input == 0) {
      if (!pq.empty()) {
        auto [_, element] = pq.top();
        cout << element << "\n";
        pq.pop();
      } else {
        cout << 0 << "\n";
      }
    } else {
      pq.push(make_tuple(abs(input), input));
    }
  }
  return 0;
}
