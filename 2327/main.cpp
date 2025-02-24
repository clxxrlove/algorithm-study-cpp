//
//  main.cpp
//  2327
//
//  Created by 정지용 on 2/24/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAX = 1e9;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int h, n; cin >> h >> n;
    vector<ii> items(n);
    
    vi dp(h + 1, 0);
    dp[0] = MAX;
    
    for (int i = 0; i < n; ++i) {
        cin >> items[i].first >> items[i].second; // weight, value
    }
    
    for (int i = 0; i < n; ++i) {
        int weight = items[i].first;
        int value = items[i].second;
        for (int w = h; w >= weight; w--) {
            if (dp[w - weight] > 0)
                dp[w] = max(dp[w], min(dp[w - weight], value));
        }
    }
    
    cout << dp[h];
    
    return 0;
}
