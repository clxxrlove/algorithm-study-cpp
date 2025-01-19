//
//  main.cpp
//  10828
//
//  Created by 정지용 on 12/31/24.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <sstream>

using namespace std;

//push X: 정수 X를 스택에 넣는 연산이다.
//pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//size: 스택에 들어있는 정수의 개수를 출력한다.
//empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
//top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

int main(int argc, const char * argv[]) {
  int t;
  cin >> t;
  cin.ignore();
  stack<int> s;
  
  for (int i = 0; i < t; i++) {
    string command;
    getline(cin, command);
    
    if (command == "pop") {
      if (!s.empty()) {
        printf("%d\n", s.top());
        s.pop();
      } else {
        printf("-1\n");
      }
    } else if (command == "size") {
      printf("%zu\n", s.size());
    } else if (command == "empty") {
      printf("%d\n", s.empty() ? 1 : 0);
    } else if (command == "top") {
      if (!s.empty()) {
        printf("%d\n", s.top());
      } else {
        printf("-1\n");
      }
    } else {
      // push x의 case
      string c;
      int item;
      istringstream line(command);
      
      line >> c;
      line >> item;
      
      if (c != "push") {
        continue;
      }
      
      s.push(item);
    }
  }
  return 0;
}
