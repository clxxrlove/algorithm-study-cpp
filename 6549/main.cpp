//
//  main.cpp
//  6549
//
//  Created by 정지용 on 4/1/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
using vi = vector<int>;
using ll = long long;

int n;
vi height;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool input() {
    height.clear();
    cin >> n;
    
    int m;
    if (n == 0) return false;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        height.push_back(m);
    }
    
    return true;
}

ll solution(int left, int right) {
    if (left == right) return height[left];
    int mid = (left + right) / 2;
    ll answer = max(solution(left, mid), solution(mid + 1, right));
    
    int l = mid, r = mid + 1;
    int h = INT_MAX;
    
    while (l >= left && r <= right) {
        h = min({h, height[l], height[r]});
        answer = max(answer, 1LL * h * (r - l + 1));
        
        if (r < right && (left == l || height[l - 1] <= height[r + 1])) ++r;
        else --l;
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    fast_io();
    
    while (input()) {
        cout << solution(0, n - 1) << '\n';
    }
    
    return 0;
}
