//
//  main.cpp
//  15652
//
//  Created by 정지용 on 1/4/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int nums[9];
vector<int> arr;
vector<bool> visited;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

void backtracking(int count, int start) {
  if (count == m) {
    for (int num: arr) {
      cout << num << " ";
    }
    cout << "\n";
    return;
  }
  
  for (int i = start; i <= n; i++) {
    visited[i] = true;
    arr.push_back(i);
    backtracking(count + 1, i);
    visited[i] = false;
    arr.pop_back();
  }
}

int main(int argc, const char * argv[]) {
  setDefault();
  cin >> n >> m;
  
  for (int i = 0; i <= n; i++) {
    visited.push_back(false);
    nums[i] = i;
  }
  
  backtracking(0, 1);
  
  return 0;
}
