//
//  main.cpp
//  1647
//
//  Created by 정지용 on 1/28/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
    int start, end, cost;
    
    Point(int start, int end, int cost) : start(start), end(end), cost(cost) {}
    
    bool operator>(const Point& other) const {
        return cost < other.cost;
    }
};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int find(int x,
         vector<int>& parent) {
    if (x != parent[x]) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void __union(int a,
             int b,
             vector<int>& parent,
             vector<int>& urank) {
    int fa = find(a, parent);
    int fb = find(b, parent);
    
    if (urank[fa] > urank[fb]) {
        parent[fb] = fa;
    } else if (urank[fa] < urank[fb]) {
        parent[fa] = fb;
    } else {
        parent[fb] = fa;
        ++urank[fa];
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int v, e, answer = 0;
    int max_cost = 0;
    cin >> v >> e;
    
    vector<Point> edges;
    
    int start, end, cost;
    for (int i = 0; i < e; ++i) {
        cin >> start >> end >> cost;
        edges.emplace_back(start, end, cost);
    }
    
    vector<int> urank(v + 1, 0);
    vector<int> parent(v + 1);
    
    for (int i = 1; i <= v; ++i) parent[i] = i;
    
    sort(edges.begin(), edges.end(), greater<Point>());
    
    for (Point edge: edges) {
        if (find(edge.start, parent) != find(edge.end, parent)) {
            answer += edge.cost;
            max_cost = edge.cost;
            __union(edge.start, edge.end, parent, urank);
        }
    }
    
    cout << answer - max_cost;
    
    return 0;
}
