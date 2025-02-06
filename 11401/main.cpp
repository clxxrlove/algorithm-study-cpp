//
//  main.cpp
//  11401
//
//  Created by 정지용 on 2/6/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
using vll = vector<ll>;
const int MOD = 1e9 + 7;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll fast_exponentiation(ll base,
                       ll exp) {
    ll res = 1;
    while (exp) {
        if (exp % 2) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

void initialize(int n,
                vll& fact) {
    fact[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, r;
    cin >> n >> r;
    
    vll fact(n + 1);
    
    initialize(n, fact);
    ll answer = fact[n] * fast_exponentiation(fact[r], MOD - 2) % MOD * fast_exponentiation(fact[n - r], MOD - 2) % MOD;
    cout << answer;
    
    return 0;
}
