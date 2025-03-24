//
//  main.cpp
//  1654
//
//  Created by 정지용 on 3/24/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using ll = long long;

int n, m;
ll lo = 1, hi;
vi v;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    hi = *max_element(v.begin(), v.end());
}

void solution() {
    ll answer = 0;
    
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        
        for (auto& lan: v) {
            cnt += lan / mid;
        }
        
        if (cnt >= m) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    cout << answer;
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
