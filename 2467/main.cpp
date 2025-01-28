//
//  main.cpp
//  2467
//
//  Created by 정지용 on 1/28/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ii = pair<int, int>;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    int result = 2e9;
    ii answer;
    
    int start = 0, end = arr.size() - 1;
    
    while (start < end) {
        int current = arr[start] + arr[end];
        
        if (current == 0) {
            answer = {start, end};
            break;
        }
        
        if (abs(current) < abs(result)) {
            answer = {start, end};
            result = abs(current);
        }
        
        if (current > 0) {
            --end;
        } else {
            ++start;
        }
    }
    
    cout << arr[answer.first] << " " << arr[answer.second];
    
    return 0;
}
