//
//  main.cpp
//  32408
//
//  Created by 정지용 on 3/31/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using ll = long long;

int n;
vvi tree;
vb visited;
vb path;
vi ss;
vi v;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    
    tree.resize(n + 1, vi());
    visited.resize(n + 1, false);
    path.resize(n + 1, false);
    
    int s, e;
    for (int i = 0; i < n - 1; ++i) {
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
}

bool dfs_get_path(int x) {
    visited[x] = true;
    v.push_back(x);
    
    if (x == n) return true;
    
    for (auto node: tree[x]) {
        if (visited[node]) continue;
        if (dfs_get_path(node)) return true;
    }
    
    v.pop_back();
    return false;
}

int dfs(int x) {
    int depth = 1;
    visited[x] = true;
    
    for (auto node: tree[x]) {
        if (visited[node] || path[node]) continue;
        depth += dfs(node);
    }
    
    return depth;
}

void solution() {
    ll sum = 0;
    ll subsum = 0;
    dfs_get_path(1);
    visited = vb(n + 1, false);
    for (auto i: v) path[i] = true;
    for (auto i: v) {
        for (auto j: tree[i]) {
            if (!visited[j] && !path[j]) {
                int cnt = dfs(j);
                sum += cnt;
                subsum += 1LL * cnt * (cnt - 1) / 2;
            }
        }
    }
    
    sum = 1LL * sum * (sum - 1) / 2;
    cout << sum - subsum << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
