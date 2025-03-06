//
//  main.cpp
//  20002
//
//  Created by 정지용 on 3/7/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n; cin >> n;
    
    vvi psum(n + 1, vi(n + 1));
    int answer = -2e9;
    int item;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> item;
            psum[i][j] = item + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }
    }
    
    for (int k = 0; k < n; ++k) {
        for (int i = 1; i <= n - k; ++i) {
            for (int j = 1; j <= n - k; ++j) {
                answer = max(answer, psum[i + k][j + k] - psum[i - 1][j + k] - psum[i + k][j - 1] + psum[i - 1][j - 1]);
            }
        }
    }
    
    cout << answer;
    
    return 0;
}
