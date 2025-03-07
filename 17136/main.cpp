//
//  main.cpp
//  17136
//
//  Created by 정지용 on 3/7/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

bool paper[10][10];
int cpaper[5] = {0, 0, 0, 0, 0};
int answer = 26;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

bool check() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (paper[i][j] == true) return false;
        }
    }
    return true;
}

void fill_paper(int x, int y, int size) {
    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            paper[i][j] = false;
        }
    }
}

bool check_range(int x, int y, int size) {
    if (x + size > 10 | y + size > 10) return false;
    
    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (!paper[i][j]) return false;
        }
    }
    
    return true;
}

void backtracking(int x, int y) {
    bool _paper[10][10];
    memcpy(_paper, paper, sizeof(_paper));
    
    int tmp = 0;
    for (int i = 0; i < 5; ++i) {
        tmp += cpaper[i];
    }
    
    if (check()) {
        answer = min(answer, tmp);
        return;
    }
    
    if (tmp > answer) return;
    
    for (int i = y; i < 10; ++i) {
        for (int j = x; j < 10; ++j) {
            if (!paper[i][j]) continue;
            for (int k = 5; k > 0; --k) {
                if (check_range(j, i, k) && cpaper[k - 1] < 5) {
                    fill_paper(j, i, k);
                    ++cpaper[k - 1];
                    backtracking(j, i);
                    --cpaper[k - 1];
                    memcpy(paper, _paper, sizeof(paper));
                }
            }
            return;
        } x = 0;
    }
}

int main(int argc, const char * argv[]) {
    fastio();
    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> paper[i][j];
        }
    }
    
    backtracking(0, 0);
    cout << (answer > 25 ? -1 : answer);
    
    return 0;
}
