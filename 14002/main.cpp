//
//  main.cpp
//  14002
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
    
    int n, ans = 0, last = 0;
    cin >> n;
    vector<int> nums(n + 1, 0), dp(n + 1, 0), prev(n + 1, -1);
    vector<int> result;
    for (int i = 1; i <= n; ++i) cin >> nums[i];
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[i] < (dp[j] + 1)) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (ans < dp[i]) {
            ans = dp[i];
            last = i;
        }
    }
    
    while (last != 0) {
        result.push_back(nums[last]);
        last = prev[last];
    }
    
    reverse(result.begin(), result.end());
    
    cout << ans << "\n";
    for (int i = 0; i < ans; ++i) {
        cout << result[i] << " ";
    }
    
    return 0;
}
