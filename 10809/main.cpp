//
//  main.cpp
//  10809
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
  vector<int> ans(26, -1);
  string s;
  cin >> s;
  
  for (int i = 0; i < s.size(); i++) {
    if (ans[s[i] - 'a'] == -1) {
      ans[s[i] - 'a'] = i;
    }
  }
  
  for (int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
  
  return 0;
}
