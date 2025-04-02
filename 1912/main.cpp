//
//  main.cpp
//  1912
//
//  Created by 정지용 on 4/2/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

int n;
vi nums;
vi dp;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    
    nums.resize(n);
    dp.resize(n, 0);
    
    for (int i = 0; i < n; ++i) cin >> nums[i];
}

void solution() {
    dp[0] = nums[0];
    
    int answer = dp[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        answer = max(answer, dp[i]);
    }
    
    cout << answer << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
