//
//  main.cpp
//  18110
//
//  Created by 정지용 on 1/1/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int main(int argc, const char * argv[]) {
  int n;
  cin >> n;
  vector<int> arr;
  
  if (n == 0) {
    printf("0");
    return 0;
  }
  
  for (int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    arr.push_back(tmp);
  }
  
  sort(arr.begin(), arr.end());
  int refer = round(n * 0.15);
  int sum = accumulate(arr.begin() + refer, arr.end() - refer, 0);
  int answer = round(static_cast<double>(sum) / (n - refer * 2));
  
  printf("%d", answer);
  
  return 0;
}
