//
//  main.cpp
//  15685
//
//  Created by 정지용 on 3/7/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
bool curve[101][101];
vector<int> ds;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void make_curve(int x, int y, int g) {
    while (g--) {
        int size = ds.size();
        
        for (int i = size - 1; i >= 0; --i) {
            int d = (ds[i] + 1) % 4;
            x += dx[d];
            y += dy[d];
            
            curve[y][x] = true;
            ds.push_back(d);
        }
    }
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n; cin >> n;
    memset(curve, false, sizeof(curve));
    
    for (int i = 0; i < n; ++i) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        
        ds.clear();
        ds.push_back(d);
        
        curve[y][x] = true;
        x += dx[d];
        y += dy[d];
        curve[y][x] = true;
        
        make_curve(x, y, g);
    }
    
    int answer = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (curve[i][j] == true && curve[i + 1][j] == true && curve[i][j + 1] == true && curve[i + 1][j + 1] == true) {
                ++answer;
            }
        }
    }
    
    cout << answer;
    
    return 0;
}
