//
//  main.cpp
//  10989
//
//  Created by 정지용 on 12/31/24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
  int n, num;
  vector<int> arr(10001, 0);
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> num;
    arr[num] += 1;
  }
  
  for (int i = 1; i <= 10000; i++) {
    for (int j = 0; j < arr[i]; j++) {
      printf("%d\n", i);
    }
  }
  
  return 0;
}
