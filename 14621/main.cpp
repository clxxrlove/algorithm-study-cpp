//
//  main.cpp
//  14621
//
//  Created by 정지용 on 3/28/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vc = vector<char>;

struct Edge {
    int s, e, x;
    Edge(int s, int e, int x): s(s), e(e), x(x) {}
    bool operator<(const Edge& other) const {
        return x < other.x;
    }
};

struct UF {
    vi parent;
    vi urank;
    
    UF(int n): parent(n + 1), urank(n + 1, 0) {
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool merge(int a, int b) {
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
        }
        return false;
    }
};

using ve = vector<Edge>;

int n, m;
ve edge;
vc gd;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n >> m;
    
    gd.resize(n + 1);
    char c;
    for (int i = 1; i <= n; ++i) {
        cin >> c;
        gd[i] = c;
    }
    
    int s, e, x;
    for (int i = 0; i < m; ++i) {
        cin >> s >> e >> x;
        edge.emplace_back(s, e, x);
    }
}

void solution() {
    UF uf(n);
    sort(edge.begin(), edge.end());
    
    int cnt = 0;
    int answer = 0;
    for (auto v: edge) {
        if (gd[v.s] != gd[v.e] && uf.merge(v.s, v.e)) {
            answer += v.x;
            if (++cnt == n - 1) break;
        }
    }
    
    cout << (cnt == (n - 1) ? answer : -1) << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
