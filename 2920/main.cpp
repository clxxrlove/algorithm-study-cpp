//
//  main.cpp
//  2920
//
//  Created by 정지용 on 12/30/24.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
  string s;
  getline(cin, s);
  
  istringstream stream(s);
  vector<int> nums;
  int num;
  
  while (stream >> num) {
    nums.push_back(num);
  }
  
  int streak = 0, back = nums[0];
  
  for (int i = 1; i < 8; i++) {
    if (nums[i] > back) {
      if (streak == -1) {
        streak = 0;
        break;
      }
      streak = 1;
    } else if (nums[i] < back) {
      if (streak == 1) {
        streak = 0;
        break;
      }
      streak = -1;
    } else {
      streak = 0;
      break;
    }
    back = nums[i];
  }
  
  if (streak == 0) {
    printf("mixed");
  } else if (streak == -1) {
    printf("descending");
  } else {
    printf("ascending");
  }
  
  return 0;
}
