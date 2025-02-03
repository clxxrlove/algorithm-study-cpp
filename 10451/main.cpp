//
//  main.cpp
//  10451
//
//  Created by 정지용 on 2/3/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void bfs(int start,
         const vi& perm,
         vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        int next = perm[current];
        if (!visited[next]) {
            visited[next] = true;
            q.push(next);
        }
    }
}

int find_perm_cycle(const vi& perm) {
    int count = 0;
    int n = perm.size();
    vector<bool> visited(n, false);
    
    for (int i = 1; i < n; ++i) {
        if (!visited[i]) {
            bfs(i, perm, visited);
            ++count;
        }
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int t;
    cin >> t;
    
    for (int _ = 0; _ < t; ++_) {
        int n;
        cin >> n;
        
        vi perm(n + 1, 0);
        for (int i = 1; i <= n; ++i) cin >> perm[i];
        
        cout << find_perm_cycle(perm) << "\n";
    }
    
    return 0;
}
