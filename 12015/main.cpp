//
//  main.cpp
//  12015
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
        size_t pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        
        if (pos == lis.size()) {
            lis.push_back(arr[i]);
        } else {
            lis[pos] = arr[i];
        }
    }
    
    return lis.size();
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    cout << findLis(arr);
    
    return 0;
}
