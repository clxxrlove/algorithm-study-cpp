//
//  main.cpp
//  14725
//
//  Created by 정지용 on 2/12/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Trie {
    map<string, Trie*> m;
    
    void insert(vector<string>& v, int idx) {
        if (v.size() == idx) return;
        
        if (m.find(v[idx]) == m.end()) {
            Trie* trie = new Trie;
            m.emplace(v[idx], trie);
        }
        
        m[v[idx]]->insert(v, idx + 1);
    }
    
    void print(int depth) {
        for (auto& element: m) {
            for (int i = 0; i < depth; ++i) cout << "--";
            cout << element.first << '\n';
            
            element.second->print(depth + 1);
            delete element.second;
        }
    }
};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    setDefault();
    
    Trie* trie = new Trie;
    
    int n, repeat;
    string s;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        vector<string> input;
        cin >> repeat;
        
        for (int j = 0; j < repeat; ++j) {
            cin >> s;
            input.push_back(s);
        }
        trie->insert(input, 0);
    }
    
    trie->print(0);
    delete trie;

    return 0;
}
