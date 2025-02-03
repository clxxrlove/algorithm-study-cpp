//
//  main.cpp
//  1644
//
//  Created by 정지용 on 2/3/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
using vi = vector<int>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vi create_prime_number(int n) {
    vi result;
    vector<bool> memo(n + 1, true);
    memo[0] = memo[1] = false;
    
    int sqrtn = sqrt(n);
    
    for (int i = 2; i <= sqrtn; ++i) {
        if (memo[i]) {
            for (int j = i * i; j <= n; j += i) {
                if (memo[i]) memo[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        if (memo[i]) result.push_back(i);
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    cin >> n;
    
    vi pn = create_prime_number(n);
    
    int start = 0, end = 0;
    int answer = 0, sum = 0;
    while (start < pn.size()) {
        sum += pn[start];
        while (sum > n && end < start) {
            sum -= pn[end++];
        }
        if (sum == n) ++answer;
        ++start;
    }
    
    cout << answer;
    
    return 0;
}
