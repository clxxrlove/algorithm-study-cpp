//
//  main.cpp
//  1929
//
//  Created by 정지용 on 1/1/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> arr(m + 1, 0);
  
  for (int i = 2; i <= m; i++) {
    arr[i] = i;
  }
  
  for (int i = 2; i * i <= m; i++) {
    if (arr[i] == 0) continue;
    
    for (int j = 2 * i; j <= m; j += i) {
      arr[j] = 0;
    }
  }
  
  for (int i = n; i <= m; i++) {
    if (arr[i] == 0) continue;
    printf("%d\n", arr[i]);
  }
  
  return 0;
}
