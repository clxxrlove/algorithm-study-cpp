//
//  main.cpp
//  1003
//
//  Created by 정지용 on 1/3/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> zero;
vector<int> one;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  int t, target;
  cin >> t;
  
  zero.resize(41, -1);
  one.resize(41, -1);
  
  zero[0] = 1; one[0] = 0;
  zero[1] = 0; one[1] = 1;
  zero[2] = 1; one[2] = 1;
  
  for (int i = 3; i <= 40; i++) {
    zero[i] = zero[i - 1] + zero[i - 2];
    one[i] = one[i - 1] + one[i - 2];
  }
  
  for (int _ = 0; _ < t; _++) {
    cin >> target;
    cout << zero[target] << " " << one[target] << "\n";
  }
  
  return 0;
}
