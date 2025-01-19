//
//  main.cpp
//  11723
//
//  Created by 정지용 on 1/2/25.
//

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

void defaultSetting() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  defaultSetting();
  
  int n;
  cin >> n;
  cin.ignore();
  
  int bitmask = 0;
  
  string input, command;
  int value;
  
  for (int i = 0; i < n; i++) {
    getline(cin, input);
    istringstream ist(input);
    ist >> command;
    ist >> value;
    
    if (command == "add") {
      bitmask = bitmask | (1 << value);
    } else if (command == "check") {
      printf("%d\n", (bitmask & (1 << value)) != 0);
    } else if (command == "remove") {
      bitmask = bitmask & ~(1 << value);
    } else if (command == "toggle") {
      bitmask = bitmask ^ (1 << value);
    } else if (command == "all") {
      bitmask = (1 << 21) - 1;
    } else if (command == "empty") {
      bitmask = 0;
    }
  }
  
  return 0;
}
