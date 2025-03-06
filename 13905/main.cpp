//
//  main.cpp
//  13905
//
//  Created by 정지용 on 3/5/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ii = pair<int, int>;
using vvi = vector<vector<int>>;
using vi = vector<int>;

struct Edge {
    int start, end, weight;
    Edge(int start, int end, int weight): start(start), end(end), weight(weight) {}
    
    bool operator<(const Edge& other) const {
        if (weight == other.weight) {
            if (start == other.start) return end < other.end;
            return start < other.start;
        }
        return weight > other.weight;
    }
};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int __find(int x, vector<int>& parent) {
    if (x != parent[x]) {
        parent[x] = __find(parent[x], parent);
    }
    return parent[x];
}

void __union(int a, int b, vector<int>& parent, vector<int>& __rank) {
    int fa = __find(a, parent);
    int fb = __find(b, parent);
    
    if (__rank[fa] > __rank[fb]) {
        parent[fb] = fa;
    } else if (__rank[fa] < __rank[fb]) {
        parent[fa] = fb;
    } else {
        parent[fb] = fa;
        __rank[fa]++;
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    
    vector<Edge> edges;
    int h1, h2, k;
    for (int i = 0; i < m; ++i) {
        cin >> h1 >> h2 >> k;
        edges.emplace_back(h1, h2, k);
    }
    
    sort(edges.begin(), edges.end());
    
    vector<int> parent(n + 1);
    vector<int> __rank(n + 1, 0);
    for (int i = 0; i <= n; ++i) parent[i] = i;
    
    int count = 0;
    int answer = 1e9;
    for (auto& edge: edges) {
        if (__find(edge.start, parent) != __find(edge.end, parent)) {
            __union(edge.start, edge.end, parent, __rank);
            answer = min(answer, edge.weight);
        }
        if (__find(s, parent) == __find(e, parent)) {
            cout << answer << '\n';
            return 0;
        }
    }
    
    cout << 0 << '\n';
    
    return 0;
}
