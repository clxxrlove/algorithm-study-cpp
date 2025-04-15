//
//  main.cpp
//  11050
//
//  Created by 정지용 on 4/15/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n, k;
vvi dp;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n >> k;
    dp.resize(n + 1, vi(k + 1, 0));
}

int solution(int n, int k) {
    if (dp[n][k] > 0) return dp[n][k];
    if (n == k || k == 0) return dp[n][k] = 1;
    return dp[n][k] = solution(n - 1, k) + solution(n - 1, k - 1);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    cout << solution(n, k) << '\n';
    
    return 0;
}
