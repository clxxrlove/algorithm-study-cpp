//
//  main.cpp
//  1931
//
//  Created by 정지용 on 2/7/25.
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
    
    int n; cin >> n;
    int start, end, answer = 1;
    
    vector<ii> meetings;
    for (int i = 0; i < n; ++i) {
        cin >> start >> end;
        meetings.emplace_back(start, end);
    }
    
    sort(meetings.begin(), meetings.end(), [](const ii& a, const ii& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    
    start = meetings[0].first;
    end = meetings[0].second;
    
    for (int i = 1; i < n; ++i) {
        if (meetings[i].first < end) continue;
        start = meetings[i].first;
        end = meetings[i].second;
        ++answer;
    }
    
    cout << answer;
    
    return 0;
}
