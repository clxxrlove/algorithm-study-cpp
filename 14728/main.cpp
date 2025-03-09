//
//  main.cpp
//  14728
//
//  Created by 정지용 on 3/9/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
const int MAX = 2e9;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    int n, w;
    cin >> n >> w;
    
    vi value(n);
    vi weight(n);
    vi dp(w + 1, 0);
    
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = w; j >= weight[i]; --j) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    
    cout << dp[w];
    
    return 0;
}
