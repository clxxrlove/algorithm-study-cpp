//
//  main.cpp
//  32406
//
//  Created by 정지용 on 2/27/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;
using ll = long long;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n; cin >> n;
    ll answer = 0;
    
    vector<int> ai(n);
    vector<int> bi(n);
    
    for (int i = 0; i < n; ++i) cin >> ai[i];
    for (int i = 0; i < n; ++i) cin >> bi[i];
    
    for (int i = 0; i < n - 2; ++i) {
        answer += abs(ai[i] - bi[i]);
    }
    answer += abs((ai[n - 1] - bi[n - 1]) - (ai[n - 2] - bi[n - 2]));
    cout << answer;
    
    return 0;
}
