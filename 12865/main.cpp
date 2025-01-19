//
//  main.cpp
//  12865
//
//  Created by 정지용 on 1/7/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  int n, k;
  cin >> n >> k;
  
  vector<vector<int>> dp;
  dp.resize(n + 1, vector<int>(k + 1, 0));
  // tuple<w, v>
  vector<tuple<int, int>> item;
  item.emplace_back(0, 0);
  
  for (int _ = 0; _ < n; ++_) {
    int w, v;
    cin >> w >> v;
    item.emplace_back(w, v);
  }
  
  for (int i = 1; i <= n; ++i) {
    for (int w = 1; w <= k; ++w) {
      int weight = get<0>(item[i]), value = get<1>(item[i]);
      if (w >= weight) {
        dp[i][w] = max(dp[i - 1][w], value + dp[i - 1][w - weight]);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }
  
  cout << dp[n][k];
  
  return 0;
}
