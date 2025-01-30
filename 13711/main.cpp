//
//  main.cpp
//  13711
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

size_t findLis(const vector<int>& arr) {
    size_t n = arr.size();
    vector<int> lis;
    
    for (int i = 0; i < n; ++i) {
        auto pos = lower_bound(lis.begin(), lis.end(), arr[i]);
        
        if (pos != lis.end()) {
            *pos = arr[i];
        } else {
            lis.push_back(arr[i]);
        }
    }
    
    return lis.size();
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    cin >> n;
    
    vector<int> first(n, 0);
    vector<int> second(n, 0);
    
    for (int i = 0; i < n; ++i) cin >> first[i];
    for (int i = 0; i < n; ++i) cin >> second[i];
    
    vector<int> f_map(n);
    vector<int> s_relative(n);
    for (int i = 0; i < n; ++i) f_map[first[i] - 1] = i;
    for (int i = 0; i < n; ++i) s_relative[i] = f_map[second[i] - 1];
    
    cout << findLis(s_relative);
    
    return 0;
}
