//
//  main.cpp
//  11399
//
//  Created by 정지용 on 1/4/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  vector<int> line;
  int n, tmp, ans = 0; string input;
  cin >> n; cin.ignore();
  getline(cin, input);
  
  istringstream ist(input);
  
  while (ist >> tmp) {
    line.push_back(tmp);
  }
  
  sort(line.begin(), line.end(), greater<int>());
  
  for (int i = 0; i < line.size(); i++) {
    ans += line[i] * (i + 1);
  }
  
  cout << ans;
  
  return 0;
}
