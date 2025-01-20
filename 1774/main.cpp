//
//  main.cpp
//  1774
//
//  Created by 정지용 on 1/20/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
    
    Point(int x, int y): x(x), y(y) {}
    
    double euclid(Point& a) {
        double px = pow(x - a.x, 2);
        double py = pow(y - a.y, 2);
        return sqrt(px + py);
    }
};

struct Edge {
    int start, end;
    double weight;
    
    Edge(int s, int e, double w): start(s), end(e), weight(w) {}
    
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int find(int x, vector<int>& parent) {
    if (x != parent[x]) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void union_element(int a,
                   int b,
                   vector<int>& parent,
                   vector<int>& urank) {
    int fa = find(a, parent);
    int fb = find(b, parent);
    
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

void kruskal(priority_queue<Edge, vector<Edge>, greater<Edge>> edges,
             vector<int>& parent,
             vector<int>& urank,
             double& answer,
             const int& n) {
    int count = 0;
    
    while (!edges.empty() && count < n - 1) {
        Edge edge = edges.top();
        edges.pop();
        
        if (find(edge.start, parent) != find(edge.end, parent)) {
            union_element(edge.start, edge.end, parent, urank);
            answer += edge.weight;
            ++count;
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int v, m, x, y;
    cin >> v >> m;
    
    vector<int> parent(v + 1, 0);
    vector<int> urank(v + 1, 0);
    vector<Point> points;
    priority_queue<Edge, vector<Edge>, greater<Edge>> edges;
    
    for (int i = 1; i <= v; ++i) parent[i] = i;
    for (int i = 0; i < v; ++i) {
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    
    for (int i = 0; i < v; ++i) {
        for (int j = i + 1; j < v; ++j) {
            edges.emplace(i + 1, j + 1, points[i].euclid(points[j]));
        }
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        union_element(x, y, parent, urank);
    }
    
    double answer = 0;
    kruskal(edges, parent, urank, answer, v);
    
    printf("%.2f", answer);
    
    return 0;
}
