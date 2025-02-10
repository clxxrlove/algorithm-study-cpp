//
//  main.cpp
//  1759
//
//  Created by 정지용 on 2/10/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vc = vector<char>;
vc vowel = {'a', 'e', 'i', 'o', 'u'};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void printV(const vc& v) {
    for (char i: v) {
        cout << i;
    } cout << '\n';
}

void combi(vc& a,
           vc& v,
           int idx,
           int l,
           int v_count,
           int c_count) {
    if (v.size() == l && v_count >= 1 && c_count >= 2) {
        printV(v);
        return;
    }
    
    for (int i = idx; i < a.size(); ++i) {
        v.push_back(a[i]);
        
        bool is_vowel = find(vowel.begin(), vowel.end(), a[i]) != vowel.end();
        if (is_vowel) ++v_count; else ++c_count;
        
        combi(a, v, i + 1, l, v_count, c_count);
        
        if (is_vowel) --v_count; else --c_count;
        
        v.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int l, c;
    cin >> l >> c;
    vector<char> a(c);
    for (int i = 0; i < c; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    vc v;
    combi(a, v, 0, l, 0, 0);
    return 0;
}
