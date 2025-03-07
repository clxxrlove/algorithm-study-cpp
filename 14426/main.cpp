//
//  main.cpp
//  14426
//
//  Created by 정지용 on 3/7/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

struct Trie {
    Trie* next[26];
    bool isEnd;
    
    Trie() {
        isEnd = false;
        fill(next, next + 26, nullptr);
    }
    
    void insert(const string& str) {
        Trie* node = this;
        for (char ch: str) {
            int idx = ch - 'a';
            if (node->next[idx] == nullptr) node->next[idx] = new Trie();
            node = node->next[idx];
        }
        node->isEnd = true;
    }
    
    bool find(const string& prefix) {
        Trie* node = this;
        for (char ch: prefix) {
            int idx = ch - 'a';
            if (node->next[idx] == nullptr) return false;
            node = node->next[idx];
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
    
    cin >> n >> m;
    
    Trie trie;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        trie.insert(str);
    }
    
    int answer = 0;
    for (int i = 0; i < m; ++i) {
        string prefix;
        cin >> prefix;
        answer += trie.find(prefix);
    }
    
    cout << answer;
    
    return 0;
}
