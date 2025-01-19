//
//  main.cpp
//  2751
//
//  Created by 정지용 on 1/1/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
  int n;
  cin >> n;
  vector<int> arr;
  
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    arr.push_back(tmp);
  }
  
  sort(arr.begin(), arr.end());
  
  for (int i: arr) {
    printf("%d\n", i);
  }
  
  return 0;
}
