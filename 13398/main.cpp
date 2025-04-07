//
//  main.cpp
//  13398
//
//  Created by 정지용 on 4/7/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

int n;
vi v;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
}

void solution() {
    vi dp(n, 0);
    vi dp2(n, 0);
    
    dp[0] = v[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = max(v[i], dp[i - 1] + v[i]);
    }
    
    dp2[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        dp2[i] = max(v[i], dp2[i + 1] + v[i]);
    }
    
    int ans = *max_element(dp.begin(), dp.end());
    
    for (int i = 1; i < n - 1; ++i) {
        ans = max(ans, dp[i - 1] + dp2[i + 1]);
    }
    
    cout << ans << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
