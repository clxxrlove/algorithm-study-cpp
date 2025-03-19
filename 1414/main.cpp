//
//  main.cpp
//  1414
//
//  Created by 정지용 on 3/19/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

struct Edge {
    int u, v, w;
    
    Edge(): u(0), v(0), w(0) {}
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
    
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct UnionFind {
    vi parent;
    vi urank;
    
    UnionFind(int n): parent(n), urank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool __union(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a != b) {
            if (urank[a] > urank[b]) {
                parent[b] = a;
            } else if (urank[a] < urank[b]) {
                parent[a] = b;
            } else {
                parent[b] = a;
                ++urank[a];
            }
            return true;
        } else {
            return false;
        }
    }
};

int n;
int sum;
vector<Edge> edges;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    
    string input;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        
        for (int j = 0; j < input.length(); ++j) {
            auto ch = input[j];
            int len = 0;
            
            if (ch == '0') continue;
            if (ch >= 'a') {
                len = ch - 'a' + 1;
            } else {
                len = ch - 'A' + 27;
            }
            
            if (i != j) {
                edges.emplace_back(i, j, len);
            }
            
            sum += len;
        }
    }
}

void kruskal() {
    UnionFind uf(n);
    sort(edges.begin(), edges.end());
    
    int cnt = 0;
    for (auto edge: edges) {
        if (uf.__union(edge.u, edge.v)) {
            sum -= edge.w;
            
            if (++cnt == n - 1) return;
        }
    }
    
    if (cnt != n - 1) sum = -1;
}

void solution() {
    kruskal();
    cout << sum << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
