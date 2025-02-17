//
//  main.cpp
//  20943
//
//  Created by 정지용 on 2/17/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

const double MAX = 2e9;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

ll case_sum(int n) {
    return 1LL * n * (n - 1) / 2;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n; cin >> n;
    map<double, int> mp;
    
    double a, b, c;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c; // c는 필요 없음, 어차피 같은 직선은 없으니까.
        double slope = b != 0 ? -(a/b) : MAX;
        mp[slope]++;
    }
    
    ll answer = case_sum(n);
    for (auto m: mp) {
        answer -= case_sum(m.second);
    }
    
    cout << answer;
    
    return 0;
}
