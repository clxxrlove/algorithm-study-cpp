//
//  main.cpp
//  2015
//
//  Created by 정지용 on 2/2/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using ll = long long;
using vi = vector<int>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, k;
    ll answer = 0;
    cin >> n >> k;
    vi a(n + 1, 0);
    vi s(n + 1, 0);
    map<ll, ll> result;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    
    result[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        answer += result[s[i] - k];
        ++result[s[i]];
    }
    
    cout << answer;
    
    return 0;
}
