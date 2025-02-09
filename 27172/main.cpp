//
//  main.cpp
//  27172
//
//  Created by 정지용 on 2/10/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MAX = 1'000'001;
int score[MAX];
int counter[MAX];

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    cin >> n;
    
    vi cards(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
        ++counter[cards[i]];
    }
    
    for (int i: cards) {
        for (int multi = 2 * i; multi < MAX; multi += i) {
            if (counter[multi] != 0) {
                ++score[i];
                --score[multi];
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << score[cards[i]] << ' ';
    }
    
    return 0;
}
