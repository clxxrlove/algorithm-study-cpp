//
//  main.cpp
//  11054
//
//  Created by 정지용 on 1/10/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void calcLIS(const vector<int>& nums, vector<int>& lisLen) {
    vector<int> lis;
    int n = nums.size();
    
    for (int i = 0; i < n; ++i) {
        auto pos = lower_bound(lis.begin(), lis.end(), nums[i]);
        if (pos == lis.end()) {
            lis.push_back(nums[i]);
        } else {
            *pos = nums[i];
        }
        lisLen[i] = lis.size();
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, ans = 0;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<int> lisLen(n, 0);
    vector<int> ldsLen(n, 0);
    
    calcLIS(nums, lisLen);
    reverse(nums.begin(), nums.end());
    calcLIS(nums, ldsLen);
    reverse(ldsLen.begin(), ldsLen.end());
    
    for (int i = 0; i < n; ++i) {
        ans = max(ans, lisLen[i] + ldsLen[i] - 1);
    }
    
    cout << ans;
    
    return 0;
}
