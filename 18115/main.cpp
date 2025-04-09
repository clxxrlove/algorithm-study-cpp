//
//  main.cpp
//  18115
//
//  Created by 정지용 on 4/10/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;
using vi = vector<int>;
using di = deque<int>;

int n;
vi a;
di answer;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
}

void solution() {
    int card = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 1) {
            answer.push_back(card++);
        } else if (a[i] == 2) {
            int back = answer.back();
            answer.pop_back();
            answer.push_back(card++);
            answer.push_back(back);
        } else {
            answer.push_front(card++);
        }
    }
    
    for (int i = n - 1; i >= 0; --i) {
        cout << answer[i] << ' ';
    } cout << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
