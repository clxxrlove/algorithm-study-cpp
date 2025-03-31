//
//  main.cpp
//  27498
//
//  Created by 정지용 on 3/30/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

struct Edge {
    int s, e, x;
    Edge(int s, int e, int x): s(s), e(e), x(x) {}
    bool operator<(const Edge& other) const {
        return x > other.x;
    }
};

struct UF {
    vi parent;
    vi urank;
    
    UF(): parent(), urank() {}
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

int n, m;
vector<Edge> edge;
int answer, cnt;
UF uf;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n >> m;
    uf = UF(n);
    
    int s, e, x, y;
    for (int i = 0; i < m; ++i) {
        cin >> s >> e >> x >> y;
        if (y == 0) {
            edge.emplace_back(s, e, x);
            answer += x;
        } else {
            uf.merge(s, e);
            ++cnt;
        }
    }
}

void solution() {
    sort(edge.begin(), edge.end());
    
    if (cnt == n - 1) {
        cout << answer << '\n';
        return;
    }
    
    for (auto& [u, v, w]: edge) {
        if (uf.merge(u, v)) {
            answer -= w;
            if (++cnt == n - 1) break;
        }
    }
    
    cout << answer << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
