//
//  main.cpp
//  1676
//
//  Created by 정지용 on 4/17/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
}

void solution() {
    int answer = 0;
    
    while (n > 1) {
        answer += n / 5;
        n /= 5;
    }
    
    cout << answer << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    return 0;
}
