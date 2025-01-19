//
//  main.cpp
//  9663
//
//  Created by 정지용 on 1/5/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, ans = 0;
vector<bool> row;
// diag1 = right, diag2 = left
vector<bool> diag1, diag2;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

bool check(int x, int y) {
  if (row[x]) {
    return false;
  }
  
  if (diag1[x - y + n - 1] || diag2[x + y]) {
    return false;
  }
  return true;
}

void backtracking(int count, int h) {
  if (count == n) {
    ans++;
    return;
  }
  
  for (int i = 0; i < n; i++) {
    if (check(i, h)) {
      row[i] = diag1[i - h + n - 1] = diag2[i + h] = true;
      backtracking(count + 1, h + 1);
      row[i] = diag1[i - h + n - 1] = diag2[i + h] = false;
    }
  }
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  cin >> n;
  row.resize(n, false);
  diag1.resize(n * 2, false);
  diag2.resize(n * 2, false);
  
  backtracking(0, 0);
  cout << ans;
  
  return 0;
}
