//
//  main.cpp
//  4153
//
//  Created by 정지용 on 4/15/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a, b, c;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool input() {
    cin >> a >> b >> c;
    
    if (a == 0 && b == 0 && c == 0) return false;
    return true;
}

void solution() {
    int tmp = max(a, max(b, c));
    int sum = a * a + b * b + c * c;
    int ptmp = tmp * tmp;
    
    if (ptmp == sum - ptmp) {
        cout << "right" << '\n';
    } else cout << "wrong" << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    while (input()) {
        solution();
    }
    
    return 0;
}
