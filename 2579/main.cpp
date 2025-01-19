//
//  main.cpp
//  2579
//
//  Created by 정지용 on 1/3/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;
vector<int> s;

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  int n, tmp;
  cin >> n;
  
  a.resize(n >= 3 ? n + 1 : 4, 0);
  s.resize(n >= 3 ? n + 1 : 4, 0);
  
  for (int i = 1; i <= n; i++) {
    cin >> tmp;
    a[i] = tmp;
  }
  
  s[1] = a[1];
  s[2] = a[1] + a[2];
  s[3] = max(a[1] + a[3], a[2] + a[3]);
  
  for (int i = 4; i <= n; i++) {
    s[i] = max(s[i - 2] + a[i], s[i - 3] + a[i] + a[i - 1]);
  }
  
  cout << s[n];
  
  return 0;
}
