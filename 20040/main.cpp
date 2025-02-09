//
//  main.cpp
//  20040
//
//  Created by 정지용 on 2/10/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int find(int a, vi& parent) {
    if (a != parent[a]) {
        parent[a] = find(parent[a], parent);
    }
    return parent[a];
}

void _union(int a,
            int b,
            vi& parent,
            vi& urank) {
    int pa = find(a, parent);
    int pb = find(b, parent);
    
    if (urank[pa] > urank[pb]) {
        parent[pb] = pa;
    } else if (urank[pa] < urank[pb]) {
        parent[pa] = pb;
    } else {
        parent[pb] = pa;
        ++urank[pa];
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m, start, end, i;
    cin >> n >> m;
    
    vi parent(n);
    vi urank(n, 0);
    
    for (i = 0; i < n; ++i) parent[i] = i;
    for (i = 1; i <= m; ++i) {
        cin >> start >> end;
        
        if (find(start, parent) != find(end, parent)) {
            _union(start, end, parent, urank);
        } else {
            break;
        }
    }
    
    cout << (i != m + 1 ? i : 0);
    
    return 0;
}
