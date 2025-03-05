//
//  main.cpp
//  codeforce/1323/problem/C
//
//  Created by 정지용 on 3/5/25.
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
    setDefault();
    
    int n; cin >> n;
    if (n % 2 == 1) {
        cout << -1; return 0;
    }
    
    int balance = 0;
    int track = 0;
    bool flag = false;
    int answer = 0;
    char ch;
    for (int i = 0; i < n; ++i) {
        cin >> ch;
        
        if (ch == '(') {
            balance++;
            if (balance == 0 && flag) {
                answer += i - track + 1;
                flag = false;
            }
        } else {
            balance--;
            if (balance < 0) {
                if (!flag) {
                    flag = true;
                    track = i;
                }
            }
        }
    }
    
    if (balance == 0) {
        cout << answer;
    } else {
        cout << -1;
    }
    
    return 0;
}
