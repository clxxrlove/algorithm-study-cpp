//
//  main.cpp
//  15654
//
//  Created by 정지용 on 1/5/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int n, m;
vector<int> nums;
vector<int> ans;
vector<bool> visited;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

void backtracking(int count) {
  if (count == m) {
    for (int num: ans) {
      cout << num << " ";
    }
    cout << "\n";
  }
  
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      ans.push_back(nums[i]);
      backtracking(count + 1);
      visited[i] = false;
      ans.pop_back();
    }
  }
}

int main(int argc, const char * argv[]) {
  int tmp;
  string input;
  cin >> n >> m;
  cin.ignore();
  getline(cin, input);
  
  istringstream ist(input);
  visited.resize(m, false);
  
  while (ist >> tmp) {
    nums.push_back(tmp);
  }
  
  sort(nums.begin(), nums.end());
  
  backtracking(0);
  
  return 0;
}
