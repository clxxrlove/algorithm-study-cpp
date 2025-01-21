//
//  main.cpp
//  2096
//
//  Created by 정지용 on 1/21/25.
//

#include <iostream>
#include <algorithm>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int max_dp[3] = {0, };
    int min_dp[3] = {0, };
    int n, v0, v1, v2;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v0 >> v1 >> v2;
        
        int md0 = max_dp[0], md1 = max_dp[1], md2 = max_dp[2];
        int nd0 = min_dp[0], nd1 = min_dp[1], nd2 = min_dp[2];
        
        max_dp[0] = max(md0, md1) + v0;
        max_dp[1] = max({md0, md1, md2}) + v1;
        max_dp[2] = max(md1, md2) + v2;
        
        min_dp[0] = min(nd0, nd1) + v0;
        min_dp[1] = min({nd0, nd1, nd2}) + v1;
        min_dp[2] = min(nd1, nd2) + v2;
    }
    
    cout << max({max_dp[0], max_dp[1], max_dp[2]}) << " " << min({min_dp[0], min_dp[1], min_dp[2]});
    
    return 0;
}
