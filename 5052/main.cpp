//
//  main.cpp
//  5052
//
//  Created by 정지용 on 2/12/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Trie {
    bool is_end;
    Trie* child[10] = {nullptr, };
    
    Trie() { is_end = false; }
    
    bool insert(const string& number) {
        Trie* node = this;
        
        for (char digit: number) {
            int idx = digit - '0';
            
            if (!node->child[idx]) {
                node->child[idx] = new Trie();
            }
            node = node->child[idx];
            
            if (node->is_end) { return false; }
        }
        
        node->is_end = true;
        
        for (int i = 0; i < 10; ++i) {
            if (node->child[i]) return false;
        }
        
        return true;
    }
};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int t; cin >> t;
    
    for (int _ = 0; _ < t; ++_) {
        int n; cin >> n;
        string s;
        
        Trie* trie = new Trie();
        vector<string> ss(n);
        
        bool flag = true;
        for (int i = 0; i < n; ++i) cin >> ss[i];
        sort(ss.begin(), ss.end());
        
        for (int i = 0; i < n; ++i) {
            flag = trie->insert(ss[i]);
            if (!flag) break;
        }
        
        cout << (flag ? "YES": "NO") << "\n";
    }
    
    return 0;
}
