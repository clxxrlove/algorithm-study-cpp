//
//  main.cpp
//  1202
//
//  Created by 정지용 on 1/26/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ii = pair<int, int>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    vector<ii> items;
    vector<int> bags;
    
    int n, k, answer = 0;
    cin >> n >> k;
    
    int weight, value;
    for (int i = 0; i < n; ++i) {
        cin >> weight >> value;
        items.push_back({weight, value});
    }
    
    for (int i = 0; i < k; ++i) {
        cin >> weight;
        bags.push_back(weight);
    }
    
    sort(items.begin(), items.end(), [](const ii a, const ii b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    sort(bags.begin(), bags.end());
    
    priority_queue<int> pq;
    
    int idx = 0;
    for (int i = 0; i < k; ++i) {
        while (idx < n && bags[i] >= items[idx].first) {
            pq.push(items[idx++].second);
        }
        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }
    
    cout << answer;
    
    return 0;
}
