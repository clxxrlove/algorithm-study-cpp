//
//  main.cpp
//  2039
//
//  Created by 정지용 on 3/4/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void backtracking(const vector<int>& items,
                  vector<int>& selected,
                  int index,
                  int depth,
                  int sum) {
    if (depth == 7) {
        if (sum == 100) {
            sort(selected.begin(), selected.end());
            for (int s: selected) cout << s << '\n';
            exit(0);
        }
        return;
    }
    
    for (int i = index; i < 9; ++i) {
        selected.push_back(items[i]);
        backtracking(items, selected, i + 1, depth + 1, sum + items[i]);
        selected.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    vector<int> items(9);
    vector<int> selected;
    for (int i = 0; i < 9; ++i) {
        cin >> items[i];
    }
    
    backtracking(items, selected, 0, 0, 0);
    
    return 0;
}
