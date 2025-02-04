//
//  main.cpp
//  18111
//
//  Created by 정지용 on 2/4/25.
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

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n, m, b;
    cin >> n >> m >> b;
    
    vector<vi> board(n, vi(m));
    int min_time = 2e9;
    int tmp_height = 0, max_height = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
            tmp_height = max(tmp_height, board[i][j]);
        }
    }
    
    for (int height = tmp_height; height >= 0; height--) {
        int tmp_time = 0;
        int tmp_blocks = b;
        
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                int middle = board[y][x] - height;
                
                if (board[y][x] > height) {
                    tmp_time += middle * 2;
                    tmp_blocks += middle;
                } else if (board[y][x] < height) {
                    tmp_time -= middle;
                    tmp_blocks += middle;
                }
            }
        }
        
        if (tmp_blocks >= 0) {
            if (tmp_time < min_time) {
                min_time = tmp_time;
                max_height = height;
            } else if (tmp_time == min_time) {
                max_height = max(max_height, height);
            } else {
                break;
            }
        }
    }
    
    cout << min_time << " " << max_height;
    
    return 0;
}
