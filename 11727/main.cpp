//
//  main.cpp
//  11727
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
  
  int n;
  vector<int> dp(1001, 0);
  cin >> n;
  
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 3;
  
  for (int i = 3; i <= 1000; i++) {
    dp[i] = (dp[i - 1] % 10007) + ((dp[i - 2] * 2) % 10007);
  }
  
  cout << dp[n] % 10007;
}
