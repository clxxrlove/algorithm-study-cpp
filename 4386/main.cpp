//
//  main.cpp
//  4386
//
//  Created by 정지용 on 3/20/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using vi = vector<int>;
using dd = pair<double, double>;
using vdd = vector<pair<double, double>>;

struct Edge {
    int u, v; double w;
    Edge(int u, int v, double w): u(u), v(v), w(w) {}
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct UF {
    vi parent;
    vi urank;
    
    UF(int n): parent(n + 1), urank(n + 1, 0) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
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

int n;
vdd vertex;
vector<Edge> edge;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void input() {
    cin >> n;
    
    double s, e;
    for (int i = 0; i < n; ++i) {
        cin >> s >> e;
        vertex.emplace_back(s, e);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dist = sqrt(pow(abs(vertex[i].first - vertex[j].first), 2) +
                               pow(abs(vertex[i].second - vertex[j].second), 2));
            edge.emplace_back(i + 1, j + 1, dist);
        }
    }
}

void solution() {
    sort(edge.begin(), edge.end());
    UF uf(n);
    
    double answer = 0;
    int cnt = 0;
    for (auto& e: edge) {
        if (uf.merge(e.u, e.v)) {
            answer += e.w;
            if (++cnt == n - 1) break;
        }
    }
    
    cout << round(answer * 100) / 100 << '\n';
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
