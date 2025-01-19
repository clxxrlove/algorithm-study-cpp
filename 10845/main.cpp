//
//  main.cpp
//  10845
//
//  Created by 정지용 on 12/31/24.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

//  push X: 정수 X를 큐에 넣는 연산이다.
//  pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//  size: 큐에 들어있는 정수의 개수를 출력한다.
//  empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
//  front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//  back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

int main(int argc, const char * argv[]) {
  int t;
  cin >> t;
  cin.ignore();
  queue<int> q;
  
  for (int i = 0; i < t; i++) {
    string command;
    getline(cin, command);
    
    if (command == "pop") {
      if (!q.empty()) {
        printf("%d\n", q.front());
        q.pop();
      } else {
        printf("-1\n");
      }
    } else if (command == "size") {
      printf("%zu\n", q.size());
    } else if (command == "empty") {
      printf("%d\n", q.empty() ? 1 : 0);
    } else if (command == "front") {
      if (!q.empty()) {
        printf("%d\n", q.front());
      } else {
        printf("-1\n");
      }
    } else if (command == "back") {
      if (!q.empty()) {
        printf("%d\n", q.back());
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
      
      q.push(item);
    }
  }
  return 0;
}
