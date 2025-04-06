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

ll solution(ll x) {
    if (x == 0) return 0;
    if (x % 2 == 0) return solution(x / 2) * 2 + (x / 2) * (x / 2 + 1);
    else return solution(x / 2) * 2 + (x / 2 + 1) * (x / 2 + 1);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    cout << solution(n) << '\n';
    
    return 0;
}
