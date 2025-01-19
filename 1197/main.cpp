//
//  main.cpp
//  1197
//
//  Created by 정지용 on 1/19/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int start, end, cost;
    
    bool operator>(const Edge& other) const {
        return cost > other.cost;
    }
};

vector<int> parent;
vector<int> ufrank;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    
    return parent[x];
}

void _union(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    
    if (fa != fb) {
        if (ufrank[fa] > ufrank[fb]) {
            parent[fb] = fa;
        } else if (ufrank[fa] < ufrank[fb]) {
            parent[fa] = fb;
        } else {
            parent[fb] = fa;
            ++ufrank[fa];
        }
    }
}

int kruskal(priority_queue<Edge, vector<Edge>, greater<Edge>>& heap, int n) {
    int ans = 0;
    int count = 0;
    
    while (!heap.empty() && count < n - 1) {
        Edge edge = heap.top();
        heap.pop();
        
        if (find(edge.start) != find(edge.end)) {
            _union(edge.start, edge.end);
            ans += edge.cost;
            ++count;
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int v, e;
    cin >> v >> e;
    
    priority_queue<Edge, vector<Edge>, greater<Edge>> heap;
    
    parent.resize(v + 1);
    ufrank.resize(v + 1, 0);
    for (int i = 0; i <= v; ++i) parent[i] = i;
    
    int start, end, cost;
    
    for (int i = 0; i < e; ++i) {
        cin >> start >> end >> cost;
        heap.push({start, end, cost});
    }
    
    cout << kruskal(heap, v);
    
    return 0;
}
