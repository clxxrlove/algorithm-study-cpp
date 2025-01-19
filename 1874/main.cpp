//
//  main.cpp
//  1874
//
//  Created by 정지용 on 1/2/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
  int n;
  cin >> n;
  int current = 1;
  stack<int> s;
  vector<char> ans;
  
  for (int i = 0; i < n; i++) {
    int target;
    cin >> target;
    
    while (current <= target) {
      s.push(current++);
      ans.push_back('+');
    }
    
    if (s.top() == target) {
      s.pop();
      ans.push_back('-');
    } else {
      printf("NO");
      return 0;
    }
  }
  
  for (char c: ans) {
    printf("%c\n", c);
  }
  
  return 0;
}
