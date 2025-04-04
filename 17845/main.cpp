//
//  main.cpp
//  17845
//
//  Created by 정지용 on 4/5/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

int n, k;
vi weight;
vi value;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> k >> n;
    
    int v, w;
    for (int i = 0; i < n; ++i) {
        cin >> v >> w;
        weight.push_back(w);
        value.push_back(v);
    }
}

void solution() {
    vi dp(k + 1, 0);
    
    for (int i = 0; i < n; ++i) {
        for (int w = k; w >= weight[i]; --w) {
            dp[w] = max(dp[w - weight[i]] + value[i], dp[w]);
        }
    }
    
    cout << dp[k];
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
