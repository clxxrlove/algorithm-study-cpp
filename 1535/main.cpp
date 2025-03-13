//
//  main.cpp
//  1535
//
//  Created by 정지용 on 3/14/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
using vi = vector<int>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    int n; cin >> n;
    
    vi weight(n);
    vi value(n);
    
    for (int i = 0; i < n; ++i) cin >> weight[i];
    for (int i = 0; i < n; ++i) cin >> value[i];
    
    int dp[101];
    memset(dp, 0, sizeof(dp));
        
    
    for (int i = 0; i < n; ++i) {
        for (int w = 100; w >= weight[i]; --w) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    
    cout << dp[99] << '\n';
    
    return 0;
}
