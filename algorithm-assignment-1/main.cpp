//
//  main.cpp
//  algorithm-assignment-1
//
//  Created by 정지용 on 4/1/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

ll n;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
}

ll solution(ll left, ll right) {
    if (left == right) return left;
    ll mid = (left + right) / 2;
    return solution(left, mid) + solution(mid + 1, right);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    cout << solution(1, n) << '\n';
    
    return 0;
}
