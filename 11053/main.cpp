//
//  main.cpp
//  11053
//
//  Created by 정지용 on 1/9/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, ans = 0;
    cin >> n;
    vector<int> nums(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> nums[i];
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    for (int i = 0; i <= n; ++i) ans = max(ans, dp[i]);
    cout << ans;
    
    return 0;
}
