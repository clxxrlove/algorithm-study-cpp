//
//  main.cpp
//  1018
//
//  Created by 정지용 on 12/31/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
  int n, m;
  cin >> n >> m;
  int result = n * m;
  vector<string> board;
  
  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    board.push_back(line);
  }
  
  // board 자르는 로직
  
  for (int y = 0; y <= n - 8; y++) {
    for (int x = 0; x <= m - 8; x++) {
      int count;
      // start = b
      count = 0;
      vector<string> arr = board; // deepcopy
      
      if (arr[y][x] == 'W') {
        arr[y][x] = 'B';
        count += 1;
      }
      
      for (int i = y; i < y + 8; i++) { // col = n
        for (int j = x; j < x + 8; j++) { // row = m
          char current = arr[i][j];
          if (j > x) {
            if (arr[i][j - 1] == current) {
              count += 1;
              if (arr[i][j] == 'B') {
                arr[i][j] = 'W';
              } else {
                arr[i][j] = 'B';
              }
              continue;
            }
          }
          if (i > y) {
            if (arr[i - 1][j] == current) {
              count += 1;
              if (arr[i][j] == 'B') {
                arr[i][j] = 'W';
              } else {
                arr[i][j] = 'B';
              }
              continue;
            }
          }
        }
      }
      
      result = min(result, count);
      
      // start = w
      arr = board;
      count = 0;
      
      if (arr[y][x] == 'B') {
        arr[y][x] = 'W';
        count += 1;
      }
      
      for (int i = y; i < y + 8; i++) { // col = n
        for (int j = x; j < x + 8; j++) { // row = m
          char current = arr[i][j];
          if (j > x) {
            if (arr[i][j - 1] == current) {
              count += 1;
              if (arr[i][j] == 'B') {
                arr[i][j] = 'W';
              } else {
                arr[i][j] = 'B';
              }
              continue;
            }
          }
          if (i > y) {
            if (arr[i - 1][j] == current) {
              count += 1;
              if (arr[i][j] == 'B') {
                arr[i][j] = 'W';
              } else {
                arr[i][j] = 'B';
              }
              continue;
            }
          }
        }
      }
      
      result = min(result, count);
    }
  }
  
  printf("%d\n", result);
  
  return 0;
}
