//
//  main.cpp
//  2350
//
//  Created by 정지용 on 3/18/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<pair<int, int>>;

struct Edge {
    int start, end, weight;
    Edge(int start, int end, int weight): start(start), end(end), weight(weight) {}
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};

struct Query {
    int start, end;
    bool checked;
    Query(int start, int end): start(start), end(end), checked(false) {}
};

struct union_find {
    vi parent;
    vi urank;
    
    union_find(int n) {
        parent.resize(n);
        urank.resize(n, 0);
        for (int i = 1; i < n; ++i) parent[i] = i;
    }
    
    int find(int x) {
        if (x != parent[x]) {
            return find(parent[x]);
        }
        return parent[x];
    }
    
    void __union(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (urank[a] > urank[b]) {
            parent[b] = a;
        } else if (urank[a] < urank[b]) {
            parent[a] = b;
        } else {
            parent[b] = a;
            ++urank[a];
        }
    }
};

int n, m, k;
vector<Edge> edges;
vector<Query> queries;
vi answer;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void kruskal() {
    union_find uf(n + 1);
    
    int count = 0;
    for (auto edge: edges) {
        if (uf.find(edge.start) != uf.find(edge.end)) {
            uf.__union(edge.start, edge.end);
            
            for (int i = 0; i < queries.size(); ++i) {
                auto& query = queries[i];
                if (query.checked) continue;
                if (uf.find(query.start) == uf.find(query.end)) {
                    answer[i] = edge.weight;
                    query.checked = true;
                }
            }
            
            if (++count == n - 1) break;
        }
    }
}

void solution() {
    sort(edges.begin(), edges.end());
    kruskal();
    
    for (auto v: answer) cout << v << '\n';
}

void input() {
    cin >> n >> m >> k;
    
    answer.resize(k);
    
    int start, end, weight;
    for (int i = 0; i < m; ++i) {
        cin >> start >> end >> weight;
        edges.emplace_back(start, end, weight);
    }
    
    for (int i = 0; i < k; ++i) {
        cin >> start >> end;
        queries.emplace_back(start, end);
    }
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    input();
    solution();
    
    return 0;
}
