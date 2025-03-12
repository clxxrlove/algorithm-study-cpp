//
//  main.cpp
//  21278
//
//  Created by 정지용 on 3/12/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vii = vector<pair<int, int>>;

int n, m;
const int INF = 1e9;
vii graph;
vvi adj;
pair<int, int> answer_pair;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void combi(int idx, int depth, vi& arr, int& answer) {
    if (depth == 2) {
        int first = arr[0], second = arr[1];
        int result = 0;
        
        for (int i = 1; i <= n; ++i) {
            result += min(adj[i][first], adj[i][second]) * 2;
        }
        
        if (result < answer) {
            answer = result;
            answer_pair = {first, second};
        }
        return;
    }
    
    for (int i = idx; i <= n; ++i) {
        arr.push_back(i);
        combi(i + 1, depth + 1, arr, answer);
        arr.pop_back();
    }
}

void floyd_warshall() {
    for (int i = 1; i <= n; ++i) {
        adj[i][i] = 0;
    }
    for (auto v: graph) {
        adj[v.first][v.second] = 1;
    }
    
    for (int k = 1; k <= n; ++k) { // 경유지
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (adj[i][k] == INF || adj[k][j] == INF) continue;
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    cin >> n >> m;
    adj.resize(n + 1, vi(n + 1, INF));
    
    for (int i = 0; i < m; ++i) {
        int s, e;
        cin >> s >> e;
        graph.emplace_back(s, e);
        graph.emplace_back(e, s);
    }
    
    floyd_warshall();
    
    vi v;
    int answer = INF;
    combi(1, 0, v, answer);
    
    cout << answer_pair.first << ' ' << answer_pair.second << ' ' << answer << '\n';
    
    return 0;
}
