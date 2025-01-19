//
//  main.cpp
//  1043
//
//  Created by 정지용 on 1/13/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> __rank__;
vector<int> known;
vector<vector<int>> v;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void init(int n) {
    parent.resize(n + 1);
    __rank__.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        __rank__[i] = 1;
    }
}

int find(int a) {
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void union_parent(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    
    if (pa != pb) {
        if (__rank__[pa] > __rank__[pb]) {
            parent[pb] = pa;
        } else if (__rank__[pa] < __rank__[pb]) {
            parent[pa] = pb;
        } else {
            parent[pb] = pa;
            __rank__[pa] += 1;
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m, k, size, ans = 0;
    cin >> n >> m >> k;
    
    init(n);
    known.resize(k);
    v.resize(m);
    
    for (int i = 0; i < k; ++i) {
        cin >> known[i];
    }
    
    for (int i = 1; i < k; ++i) {
        union_parent(known[0], known[i]);
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> size;
        v[i].resize(size);
        
        for (int j = 0; j < size; ++j) {
            cin >> v[i][j];
        }
        
        for (int j = 0; j < size; ++j) {
            union_parent(v[i][0], v[i][j]);
        }
    }
    
    int comp = k > 0 ? find(known[0]) : -1;
    
    for (int i = 0; i < m; ++i) {
        bool flag = true;
        for (int p: v[i]) {
            if (find(p) == comp) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    }
    
    cout << ans;
    
    return 0;
}
