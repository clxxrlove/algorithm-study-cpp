//
//  main.cpp
//  17827
//
//  Created by 정지용 on 4/7/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    int n, m, v, k;
    cin >> n >> m >> v;
    vector<int> vv(n);
    for (int i = 0; i < n; ++i) cin >> vv[i];
    for (int i = 0; i < m; ++i) {
        cin >> k;
        
        if (k < n) {
            cout << vv[k] << '\n';
        } else {
            int tmp = (k - n) % (n - v + 1);
            cout << vv[v + tmp - 1] << '\n';
        }
    }
    
    return 0;
}
