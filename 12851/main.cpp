//
//  main.cpp
//  12851
//
//  Created by 정지용 on 1/23/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

pair<int, int> bfs(int start, int end) {
    int point = max(start, end) * 2 + 1;
    queue<pair<int ,int>> q;
    vector<int> dist(point, -1);
    vector<int> count(point, 0);
    
    q.push({0, start});
    dist[start] = 0;
    count[start] = 1;
    
    while (!q.empty()) {
        int v_dist = q.front().first;
        int current = q.front().second;
        q.pop();
        
        int ways[] = {current - 1, current + 1, current * 2};
        
        for (int next: ways) {
            if (next >= point || next < 0) continue;
            if (dist[next] == -1) {
                dist[next] = v_dist + 1;
                count[next] = count[current];
                q.push({v_dist + 1, next});
            } else if (dist[next] == v_dist + 1) {
                count[next] += count[current];
            }
        }
    }
    
    return { dist[end], count[end] };
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, k;
    cin >> n >> k;
    
    pair<int, int> ans = bfs(n, k);
    
    cout << ans.first << "\n" << ans.second;
    return 0;
}
