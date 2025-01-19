//
//  main.cpp
//  14003
//
//  Created by 정지용 on 1/11/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<int> calcLIS(const vector<int>& nums) {
    int n = nums.size();
    vector<int> tail;
    vector<int> tail_indices;
    vector<int> parent(n, -1);
    
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(tail.begin(), tail.end(), nums[i]) - tail.begin();
        
        if (pos == tail.size()) {
            tail.push_back(nums[i]);
            tail_indices.push_back(i);
        } else {
            tail[pos] = nums[i];
            tail_indices[pos] = i;
        }
        
        if (pos != 0) {
            parent[i] = tail_indices[pos - 1];
        }
    }
    
    vector<int> lis(tail.size());
    int index = tail_indices.back();
    
    for (int i = tail.size() - 1; i >= 0; --i) {
        lis[i] = nums[index];
        index = parent[index];
    }
    
    return lis;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<int> ans = calcLIS(nums);
    
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
    
    return 0;
}
