//
//  main.cpp
//  2631
//
//  Created by 정지용 on 3/7/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

size_t findLis(vector<int>& arr) {
    vector<int> lis;
    
    for (int i: arr) {
        int pos = lower_bound(lis.begin(), lis.end(), i) - lis.begin();
        
        if (pos == lis.size()) {
            lis.push_back(i);
        } else {
            lis[pos] = i;
        }
    }
    
    return lis.size();
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n; cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << n - findLis(arr);
    return 0;
}
