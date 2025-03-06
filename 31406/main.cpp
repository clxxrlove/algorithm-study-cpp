//
//  main.cpp
//  31406
//
//  Created by 정지용 on 3/6/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;
using vb = vector<bool>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void dfs(vi& visible,
         vi trees[],
         const vb& isOpen,
         int element) {
    visible.push_back(element);
    
    if (!isOpen[element]) return;
    for (int child: trees[element]) {
        dfs(visible, trees, isOpen, child);
    }
}

vi visibleList(vi trees[], const vb& isOpen) {
    vi result;
    dfs(result, trees, isOpen, 1);
    return result;
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, q;
    cin >> n >> q;
    
    vi trees[n + 1];
    vb isOpen(n + 1, false);
    isOpen[1] = true;
    for (int i = 1; i <= n; ++i) {
        int rp; cin >> rp;
        
        for (int j = 0; j < rp; ++j) {
            int element; cin >> element;
            trees[i].push_back(element);
        }
    }
    
    int idx = 1;
    vi visible = visibleList(trees, isOpen);
    for (int i = 0; i < q; ++i) {
        string command;
        int arg;
        
        cin >> command;
        if (command == "toggle") {
            int current = visible[idx];
            isOpen[current] = !isOpen[current];
            visible = visibleList(trees, isOpen);
            idx = min(idx, (int)visible.size() - 1);
        } else {
            cin >> arg;
            idx += arg;
            idx = max(1, min(idx, (int)visible.size() - 1));
            cout << visible[idx] << '\n';
        }
    }
    
    return 0;
}
