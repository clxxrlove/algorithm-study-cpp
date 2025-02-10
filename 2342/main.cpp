//
//  main.cpp
//  2342
//
//  Created by 정지용 on 2/10/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int INF = 2e9;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    vi seq;
    vvi cost(5, vi(5, 0));
    vvi dp(5, vi(5, INF));
    int tmp;
    dp[0][0] = 0;
    
    while (cin >> tmp) {
        seq.push_back(tmp);
    } seq.pop_back();
    
    for (int i = 1; i < 5; ++i) {
        cost[0][i] = 2;
        cost[i][i] = 1;
    }
    cost[1][2] = cost[1][4] = cost[2][3] = cost[3][4] = 3;
    cost[1][3] = cost[2][4] = 4;
    
    for (int s: seq) {
        vvi ndp(5, vi(5, INF));
        for (int left = 0; left < 5; ++left) {
            for (int right = 0; right < 5; ++right) {
                int c;
                if (s != right) {
                    if (left >= s) c = cost[s][left]; else c = cost[left][s];
                    ndp[s][right] = min(ndp[s][right], dp[left][right] + c);
                }
                if (s != left) {
                    if (right >= s) c = cost[s][right]; else c = cost[right][s];
                    ndp[left][s] = min(ndp[left][s], dp[left][right] + c);
                }
            }
        }
        dp = ndp;
    }
    
    int answer = INF;
    
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; j++) {
            answer = min(answer, dp[i][j]);
        }
    }
    
    cout << answer;
    
    return 0;
}
