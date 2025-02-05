//
//  main.cpp
//  1806
//
//  Created by 정지용 on 2/5/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, s;
    cin >> n >> s;
    
    vi arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    int left = 0, right = 0;
    int a_sum = 0;
    int answer = 100001;
    
    while (right < n) {
        a_sum += arr[right++];
        while (left < right && a_sum >= s) {
            answer = min(answer, right - left);
            a_sum -= arr[left++];
        }
    }
    
    cout << (answer == 100001 ? 0 : answer);
    
    return 0;
}
