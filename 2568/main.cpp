//
//  main.cpp
//  2568
//
//  Created by 정지용 on 1/29/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using ii = pair<int, int>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    int n, start, end;
    cin >> n;
    vector<ii> edges;
    vector<int> b(n);
    vector<int> tail;
    vector<int> tail_indices;
    vector<int> parent(n, -1);
    
    for (int i = 0; i < n; ++i) {
        cin >> start >> end;
        edges.emplace_back(start, end);
    }
    
    sort(edges.begin(), edges.end(), [](const ii& lhs, const ii& rhs) {
        return lhs.first < rhs.first;
    });
    
    for (int i = 0; i < n; ++i) b[i] = edges[i].second;
    
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(tail.begin(), tail.end(), b[i]) - tail.begin();
        
        if (pos == tail.size()) {
            tail.push_back(b[i]);
            tail_indices.push_back(i);
        } else {
            tail[pos] = b[i];
            tail_indices[pos] = i;
        }
        
        if (pos != 0) {
            parent[i] = tail_indices[pos - 1];
        }
    }
    
    int lis_size = tail.size();
    vector<int> lis(lis_size);
    set<int> lis_set;
    int k = tail_indices.back();
    
    for (int i = lis_size - 1; i >= 0; --i) {
        lis[i] = b[k];
        lis_set.insert(b[k]);
        k = parent[k];
    }
    
    vector<int> answer;
    for (int i = 0; i < n; ++i) {
        if (lis_set.find(b[i]) == lis_set.end()) {
            answer.push_back(edges[i].first);
        }
    }
    
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); ++i) cout << answer[i] << "\n";
    
    return 0;
}
