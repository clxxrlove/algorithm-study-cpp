//
//  main.cpp
//  9935
//
//  Created by 정지용 on 1/23/25.
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
    
    string str, b;
    string b_stack = "";
    
    cin >> str >> b;
    
    for (int i = 0; i < str.size(); ++i) {
        b_stack.push_back(str[i]);
        
        if (b_stack.size() >= b.size()) {
            if (b_stack[b_stack.size() - 1] == b[b.size() - 1]) {
                bool flag = true;
                for (int j = 0; j < b.size(); ++j) {
                    if (b_stack[b_stack.size() - b.size() + j] != b[j]) {
                        flag = false;
                    }
                }
                
                if (flag) {
                    b_stack.erase(b_stack.end() - b.size(), b_stack.end());
                }
            }
        }
    }
    
    cout << (b_stack.empty() ? "FRULA" : b_stack);
    return 0;
}
