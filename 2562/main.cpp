//
//  main.cpp
//  2562
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
  int n = 9;
  vector<int> list;
  
  while (n > 0) {
    int num;
    cin >> num;
    list.push_back(num);
    n--;
  }
  
  auto _m = max_element(list.begin(), list.end());
  size_t _i = distance(list.begin(), _m);
  cout << *_m << endl << _i + 1;
  
  return 0;
}
