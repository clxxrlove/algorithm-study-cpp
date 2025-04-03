//
//  main.cpp
//  1011
//
//  Created by 정지용 on 4/4/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int t;
ll x, y;

void input() {
    cin >> x >> y;
}

void solution() {
    ll d = y - x;
    ll k = sqrt(d);
    
    if (d == k * k) {
        cout << 2 * k - 1 << '\n';
    } else if (d <= k * (k + 1)) {
        cout << 2 * k << '\n';
    } else {
        cout << 2 * k + 1 << '\n';
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    cin >> t;
    while (t--) {
        input();
        solution();
    }
    
    return 0;
}
