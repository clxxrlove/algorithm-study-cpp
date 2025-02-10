//
//  main.cpp
//  10942
//
//  Created by 정지용 on 2/10/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using vvb = vector<vector<bool>>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    cin >> n;
    vi v(n);
    vvb dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        dp[i][i] = true;
    }
    
    int m;
    cin >> m;
    vector<ii> qs;
    
    int s, e;
    for (int i = 0; i < m; ++i) {
        cin >> s >> e;
        qs.emplace_back(s, e);
    }
    
    for (int i = 0; i < n - 1; ++i) {
        dp[i][i + 1] = v[i] == v[i + 1];
    }
    
    for (int len = 3; len <= n; ++len) {
        for (s = 0; s <= n - len; ++s) {
            e = s + len - 1;
            dp[s][e] = v[s] == v[e] && dp[s + 1][e - 1];
        }
    }
    
    for (ii q: qs) {
        cout << 1 * dp[q.first - 1][q.second - 1] << '\n';
    }
    
    return 0;
}
