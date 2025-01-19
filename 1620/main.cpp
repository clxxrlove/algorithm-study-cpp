//
//  main.cpp
//  1620
//
//  Created by 정지용 on 1/2/25.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  int n, m;
  string input;
  cin >> n >> m;
  unordered_map<string, string> um;
  
  for (int i = 0; i < n; i++) {
    cin >> input;
    string index = to_string(i + 1);
    um[input] = index;
    um[index] = input;
  }
  
  for (int i = 0; i < m; i++) {
    cin >> input;
    cout << um[input] << "\n";
  }
  
  return 0;
}
