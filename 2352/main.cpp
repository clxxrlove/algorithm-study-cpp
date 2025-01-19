//
//  main.cpp
//  2352
//
//  Created by 정지용 on 1/9/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int> lis;
    
    for (int i = 0; i < n; ++i) {
        auto pos = lower_bound(lis.begin(), lis.end(), nums[i]);
        
        if (pos == lis.end()) {
            lis.push_back(nums[i]);
        } else {
            *pos = nums[i];
        }
    }
    
    cout << lis.size();
    return 0;
}
