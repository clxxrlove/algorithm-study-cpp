//
//  main.cpp
//  1541
//
//  Created by 정지용 on 1/3/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  int ans = 0, tmp;
  bool flag = false;
  vector<char> buf;
  string expression;
  cin >> expression;
  expression += "+";
  
  for (char c: expression) {
    if (c == '-' || c == '+') {
      tmp = stoi(string(buf.begin(), buf.end()));
      ans += !flag ? tmp : -tmp;
      if (c == '-') flag = true;
      buf.clear();
    } else {
      buf.push_back(c);
    }
  }
  
  cout << ans;
  
  return 0;
}
