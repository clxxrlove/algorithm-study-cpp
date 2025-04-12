//
//  main.cpp
//  15663
//
//  Created by 정지용 on 4/12/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vb = vector<bool>;

int n, m;
vi arr;
vb visited;
vi ans;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n >> m;
    arr.resize(n);
    ans.resize(m, 0);
    visited.resize(n, false);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr.begin(), arr.end());
}

void solution(int len) {
    if (len == m) {
        for (auto v: ans) {
            cout << v << ' ';
        } cout << '\n';
        return;
    }
    
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && arr[i] != tmp) {
            tmp = ans[len] = arr[i];
            visited[i] = true;
            solution(len + 1);
            visited[i] = false;
        }
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution(0);
    
    return 0;
}
