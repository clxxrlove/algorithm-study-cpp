//
//  main.cpp
//  2887
//
//  Created by 정지용 on 1/19/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

struct Edge {
    int start, end, weight;
    
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

vector<int> parent;
vector<int> urank;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    
    return parent[x];
}

void _union(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    
    if (fa != fb) {
        if (urank[fa] > urank[fb]) {
            parent[fb] = fa;
        } else if (urank[fa] < urank[fb]) {
            parent[fa] = fb;
        } else {
            parent[fb] = fa;
            ++urank[fa];
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    cin >> n;
    
    int x1, y1, z1;
    vector<tuple<int, int, int, int>> planets;
    vector<Edge> edges;
    parent.resize(n + 1);
    urank.resize(n + 1, 0);
    
    for (int i = 0; i <= n; ++i) parent[i] = i;
    for (int i = 1; i <= n; ++i) {
        cin >> x1 >> y1 >> z1;
        planets.emplace_back(x1, y1, z1, i);
    }
    
    for (int dimension = 0; dimension < 3; ++dimension) {
        sort(planets.begin(), planets.end(), [dimension](const auto& a, const auto& b) {
            switch (dimension) {
                case 0: return get<0>(a) < get<0>(b); break;
                case 1: return get<1>(a) < get<1>(b); break;
                case 2: return get<2>(a) < get<2>(b); break;
                default: return false;
            }
        });
        
        for (int i = 1; i < n; ++i) {
            int cost = 0;
            switch (dimension) {
                case 0: cost = abs(get<0>(planets[i - 1]) - get<0>(planets[i])); break;
                case 1: cost = abs(get<1>(planets[i - 1]) - get<1>(planets[i])); break;
                case 2: cost = abs(get<2>(planets[i - 1]) - get<2>(planets[i])); break;
            }
            
            edges.push_back({get<3>(planets[i - 1]), get<3>(planets[i]), cost});
        }
    }
    
    sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
        return a.weight < b.weight;
    });
    
    int ans = 0, count = 0;
    
    for (Edge& e: edges) {
        if (find(e.start) != find(e.end)) {
            _union(e.start, e.end);
            ans += e.weight;
            if (++count == n - 1) break;
        }
    }
    
    cout << ans;
    
    return 0;
}
