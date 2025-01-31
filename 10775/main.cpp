//
//  main.cpp
//  10775
//
//  Created by 정지용 on 1/31/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int find(int x, vector<int>& parent) {
    if (x != parent[x]) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int g, p, gi, answer = 0;
    cin >> g >> p;
    
    vector<int> parent(g + 1);
    for (int i = 0; i <= g; ++i) parent[i] = i;

    for (int i = 0; i < p; ++i) {
        cin >> gi;
        
        int current = find(gi, parent);
        if (current == 0) break;
        
        ++answer;
        parent[current] = current - 1;
    }
    
    cout << answer;
    
    return 0;
}
