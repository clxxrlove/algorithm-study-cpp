//
//  main.cpp
//  2630
//
//  Created by 정지용 on 1/3/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int>> board;
int white = 0;
int blue = 0;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

// x, y는 사각형의 시작지점, len은 길이 (square)
void divide(int x, int y, int len) {
  int start = board[y][x];
  int half = len / 2;
  
  for (int i = x; i < len + x; i++) {
    for (int j = y; j < len + y; j++) {
      if (board[j][i] != start) {
        divide(x, y, half);
        divide(x + half, y, half);
        divide(x, y + half, half);
        divide(x + half, y + half, half);
        return;
      }
    }
  }
  
  if (start == 1) {
    blue++;
  } else { white++; }
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  int n, tmp;
  cin >> n;
  cin.ignore();
  string ns;
  board.resize(n);
  
  for (int i = 0; i < n; i++) {
    getline(cin, ns);
    istringstream nst(ns);
    
    while (nst >> tmp) {
      board[i].push_back(tmp);
    }
  }
  
  divide(0, 0, n);
  cout << white << "\n" << blue;
  
  return 0;
}
