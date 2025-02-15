//
//  main.cpp
//  12731
//
//  Created by 정지용 on 2/15/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct time_table {
    int depart, arrive, from;
};

void setDefault() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
    setDefault();
    
    int t; cin >> t;
    
    for (int _case = 1; _case <= t; ++_case) {
        char colon = ':';
        int rt, na, nb;
        cin >> rt >> na >> nb;
        
        vector<time_table> tables;
        
        for (int i = 1; i <= na + nb; ++i) {
            int hh, mm;
            int start, end;
            
            cin >> hh >> colon >> mm;
            start = hh * 60 + mm;
            cin >> hh >> colon >> mm;
            end = hh * 60 + mm;
            
            if (i <= na) tables.push_back({start, end, 0});
            else tables.push_back({start, end, 1});
        }
        
        sort(tables.begin(), tables.end(), [](const time_table& a, const time_table& b) {
            return a.depart < b.depart;
        });
        
        priority_queue<int, vector<int>, greater<int>> a, b;
        int aans = 0, bans = 0;
        
        for (auto time: tables) {
            if (time.from == 0) { // A -> B
                if (!a.empty() && a.top() <= time.depart) {
                    a.pop();
                } else {
                    ++aans;
                }
                b.push(time.arrive + rt);
            } else {
                if (!b.empty() && b.top() <= time.depart) {
                    b.pop();
                } else {
                    ++bans;
                }
                a.push(time.arrive + rt);
            }
        }
        
        cout << "Case #" << _case << ": " << aans << " " << bans << "\n";
    }
    
    return 0;
}
