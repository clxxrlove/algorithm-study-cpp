//
//  main.cpp
//  5639
//
//  Created by 정지용 on 4/11/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

vi tree;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    int tmp;
    
    while (cin >> tmp) {
        tree.push_back(tmp);
    }
}

void dfs(int s, int e) {
    if (s >= e) return;
    int v = tree[s];
    int i = s + 1;
    
    while (i < e) {
        if (v < tree[i]) break;
        ++i;
    }
    
    dfs(s + 1, i);
    dfs(i, e);
    
    cout << v << '\n';
}

void solution() {
    dfs(0, tree.size());
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
