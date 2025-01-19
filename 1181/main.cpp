//
//  main.cpp
//  1181
//
//  Created by 정지용 on 12/31/24.
//

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct CustomCompare {
  bool operator()(string lhs, string rhs) const {
    if (lhs.size() == rhs.size()) {
      return lhs < rhs;
    } else {
      return lhs.size() < rhs.size();
    }
  }
};

int main(int argc, const char * argv[]) {
  int t;
  set<string, CustomCompare> s;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    string word;
    cin >> word;
    
    s.insert(word);
  }
  
  for (string word: s) {
    printf("%s\n", word.c_str());
  }
  
  return 0;
}
