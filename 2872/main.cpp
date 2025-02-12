//
//  main.cpp
//  2872
//
//  Created by 정지용 on 2/12/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int n; cin >> n;
    
    vector<int> book(n);
    for (int i = 0; i < n; ++i) cin >> book[i];
    
    int count = 1;
    int target = n - 1;
    int start = find(book.begin(), book.end(), n) - book.begin();
    
    for (int i = start - 1; i >= 0; --i) {
        if (book[i] == target) {
            ++count; --target;
        }
    }
    
    cout << n - count;
    
    return 0;
}
