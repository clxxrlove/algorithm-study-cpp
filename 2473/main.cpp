//
//  main.cpp
//  2473
//
//  Created by 정지용 on 2/4/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    cin >> n;
    
    vector<int> liquids(n);
    for (int i = 0; i < n; ++i) cin >> liquids[i];
    sort(liquids.begin(), liquids.end());
    
    int start = 0, end = 0;
    tuple<int, int, int> result;
    ll answer = 4'000'000'001LL, sum;
    
    for (int i = 0; i < n - 2; ++i) {
        start = i + 1; end = n - 1;
        
        while (start < end) {
            sum = 1LL * liquids[i] + liquids[start] + liquids[end];
            
            if (abs(sum) < abs(answer)) {
                answer = sum;
                result = {liquids[i], liquids[start], liquids[end]};
            }
            
            if (sum < 0) ++start; else --end;
        }
    }
    
    cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result);
    
    return 0;
}
