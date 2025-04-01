//
//  main.cpp
//  11444
//
//  Created by 정지용 on 4/1/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define MOD 1'000'000'007
using namespace std;
using ll = long long;

ll n;
map<ll, ll> mp;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    
    mp[0] = 0; mp[1] = mp[2] = 1;
}

ll solution(ll x) {
    if (mp[x]) return mp[x];
    
    ll k = x / 2;
    ll fk = solution(k);
    ll fk1 = solution(k + 1);
    
    if (x % 2 == 0) {
        ll sub = (2LL * fk1 % MOD - fk + MOD) % MOD;
        return mp[x] = fk * sub % MOD;
    } else {
        return mp[x] = (fk1 * fk1 % MOD + fk * fk % MOD) % MOD;
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    cout << solution(n) << '\n';
    
    return 0;
}
