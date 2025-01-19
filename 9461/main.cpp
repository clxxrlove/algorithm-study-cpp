//
//  main.cpp
//  9461
//
//  Created by 정지용 on 1/4/25.
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
  setDefault();
  
  vector<long long> dp(101, 0);
  int t, n;
  cin >> t;
  
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 2;
  dp[5] = 2;
  
  for (int i = 6; i <= 100; i++) {
    dp[i] = dp[i - 1] + dp[i - 5];
  }
  
  for (int i = 0; i < t; i++) {
    cin >> n;
    cout << dp[n] << "\n";
  }
  
  return 0;
}
