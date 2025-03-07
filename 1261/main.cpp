//
//  main.cpp
//  1261
//
//  Created by 정지용 on 3/7/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

struct Pos {
    int x, y, cost;
    Pos(int x, int y, int cost): x(x), y(y), cost(cost) {}
    
    bool operator>(const Pos& other) const {
        return cost > other.cost;
    }
};

int n;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
const int MAX = 2e9;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int dijkstra(const vvi& costs) {
    vvi dist(n, vi(n, MAX));
    priority_queue<Pos, vector<Pos>, greater<Pos>> pq;
    dist[0][0] = costs[0][0];
    pq.emplace(0, 0, dist[0][0]);
    
    while (!pq.empty()) {
        int qx = pq.top().x;
        int qy = pq.top().y;
        int cost = pq.top().cost;
        pq.pop();
        
        for (int d = 0; d < 4; ++d) {
            int nx = qx + dx[d];
            int ny = qy + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            
            int n_cost = cost + costs[ny][nx];
            if (n_cost < dist[ny][nx]) {
                dist[ny][nx] = n_cost;
                pq.emplace(nx, ny, n_cost);
            }
        }
    }
    
    return dist[n - 1][n - 1];
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    int count = 0;
    while (++count) {
        cin >> n;
        if (!n) break;
        
        vvi costs(n, vi(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> costs[i][j];
            }
        }
        
        cout << "Problem " << count << ": " << dijkstra(costs) << '\n';
    }
    
    return 0;
}
