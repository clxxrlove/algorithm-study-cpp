//
//  main.cpp
//  30406
//
//  Created by 정지용 on 2/24/25.
//

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    int n; cin >> n;
    int tmp;
    int answer = 0;
    
    map<int, int> p;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        p[tmp]++;
    }
    
    int lower = min(p[0], p[3]);
    p[0] -= lower; p[3] -= lower;
    answer += lower * 3;
    lower = min(p[1], p[2]);
    p[1] -= lower; p[2] -= lower;
    answer += lower * 3;
    
    int first = 0, second = 0;
    for (auto m: p) {
        if (first == 0 && m.second > 0) {
            first = m.first;
        } else if (m.second > 0) {
            second = m.first;
        }
    }
    
    answer += min(p[first], p[second]) * (first ^ second);
    cout << answer;
    
    return 0;
}
