//
//  main.cpp
//  23254
//
//  Created by 정지용 on 2/28/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;

struct Compare {
    bool operator()(const ii& lhs, const ii& rhs) const {
        return min(100 - lhs.first, lhs.second) < min(100 - rhs.first, rhs.second);
    }
};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m; cin >> n >> m;
    n *= 24;
    int answer = 0;

    vector<ii> v(m);
    
    for (int i = 0; i < m; ++i) cin >> v[i].first;
    for (int i = 0; i < m; ++i) cin >> v[i].second;
    
    priority_queue<ii, vector<ii>, Compare> pq;
    
    for (ii& vi: v) pq.push(vi);
    for (int i = 0; i < n; ++i) {
        if (pq.empty()) break;
        
        ii current = pq.top(); pq.pop();
        current.first = min(100, current.first + current.second);
        
        if (current.first == 100) {
            answer += 100; continue;
        }
        
        pq.push(current);
    }
    
    while (!pq.empty()) {
        answer += pq.top().first;
        pq.pop();
    }
    
    cout << answer;
    
    return 0;
}
