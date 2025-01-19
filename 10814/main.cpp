//
//  main.cpp
//  10814
//
//  Created by 정지용 on 1/1/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class User {
public:
  int age;
  string name;
  int order;
  
  User(int age, string name, int order): age(age), name(name), order(order) {}
  
  bool operator<(const User& other) const {
    if (age == other.age) {
      return order < other.order;
    }
    return age < other.age;
  }
};

int main(int argc, const char * argv[]) {
  int n;
  cin >> n;
  vector<User> arr;
  
  for (int i = 0; i < n; i++) {
    int age;
    string name;
    
    cin >> age >> name;
    arr.push_back(User(age, name, i));
  }
  
  sort(arr.begin(), arr.end());
  
  for (User& u: arr) {
    printf("%d %s\n", u.age, u.name.c_str());
  }
  
  return 0;
}
