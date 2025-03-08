//
//  main.cpp
//  1106
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
    cin >> w >> n;
    
    vi weight(n);
    vi value(n);
    vi dp(w + 101, MAX);
    dp[0] = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = value[i]; j <= w + 100; ++j) {
            dp[j] = min(dp[j], dp[j - value[i]] + weight[i]);
        }
    }
    
    int answer = MAX;
    for (int i = 0; i <= 100; ++i) {
        answer = min(answer, dp[w + i]);
    }
    
    cout << answer;
    
    return 0;
}
