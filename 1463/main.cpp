//
//  main.cpp
//  1463
//
//  Created by 정지용 on 1/3/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    if (!(i % 3)) dp[i] = min(dp[i], dp[i / 3] + 1);
    if (!(i % 2)) dp[i] = min(dp[i], dp[i / 2] + 1);
  }
  
  cout << dp[n];
  
  return 0;
}
