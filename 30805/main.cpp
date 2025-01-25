//
//  main.cpp
//  30805
//
//  Created by 정지용 on 1/25/25.
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
    int n, m;
    vector<int> lcs;
    
    cin >> n;
    vector<int> narr(n, 0);
    for (int i = 0; i < n; ++i) cin >> narr[i];
    
    cin >> m;
    vector<int> marr(m, 0);
    for (int i = 0; i < m; ++i) cin >> marr[i];
    
    while (true) {
        vector<int> common;
        
        for (int a: narr) {
            if (find(marr.begin(), marr.end(), a) != marr.end()) {
                common.push_back(a);
            }
        }
        
        if (common.empty()) break;
        int max_common = *max_element(common.begin(), common.end());
        lcs.push_back(max_common);
        
        auto nit = find(narr.begin(), narr.end(), max_common);
        auto mit = find(marr.begin(), marr.end(), max_common);
        narr = vector<int>(nit + 1, narr.end());
        marr = vector<int>(mit + 1, marr.end());
    }
    
    if (!lcs.empty()) {
        cout << lcs.size() << "\n";
        for (int a: lcs) cout << a << " ";
    } else cout << "0";
    
    return 0;
}
