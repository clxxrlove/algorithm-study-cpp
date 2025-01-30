//
//  main.cpp
//  2550
//
//  Created by 정지용 on 1/30/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<int> findLis(const vector<int>& arr) {
    size_t n = arr.size();
    vector<int> tail;
    vector<int> tail_indices;
    vector<int> parent(n, -1);
    
    for (int i = 0; i < n; ++i) {
        size_t pos = lower_bound(tail.begin(), tail.end(), arr[i]) - tail.begin();
        
        if (pos == tail.size()) {
            tail.push_back(arr[i]);
            tail_indices.push_back(i);
        } else {
            tail[pos] = arr[i];
            tail_indices[pos] = i;
        }
        
        if (pos != 0) {
            parent[i] = tail_indices[pos - 1];
        }
    }
    
    size_t lis_size = tail.size();
    vector<int> lis(lis_size);
    int pointer = tail_indices.back();
    
    for (int i = lis_size - 1; i >= 0; --i) {
        lis[i] = arr[pointer];
        pointer = parent[pointer];
    }
    
    return lis;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    cin >> n;
    
    vector<int> first(n);
    vector<int> second(n);
    
    for (int i = 0; i < n; ++i) cin >> first[i];
    for (int i = 0; i < n; ++i) cin >> second[i];
    
    vector<int> f_map(n + 1);
    vector<int> s_relative(n + 1);
    
    for (int i = 0; i < n; ++i) f_map[first[i]] = i;
    for (int i = 0; i < n; ++i) s_relative[i] = f_map[second[i]];
    
    vector<int> lis = findLis(s_relative);
    vector<int> answer;
    
    for (int i = 0; i < lis.size(); ++i) answer.push_back(first[lis[i]]);
    sort(answer.begin(), answer.end());
    
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); ++i) cout << answer[i] << " ";
    
    return 0;
}
