//
//  main.cpp
//  tmp
//
//  Created by 정지용 on 2/8/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int m = 5;
int n = 10;
// 2D 벡터 q
vector<vector<int>> q = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {3, 7, 8, 9, 10},
    {2, 5, 7, 9, 10},
    {3, 4, 5, 6, 7}
};
// ans 배열
vector<int> ans = {2, 3, 4, 3, 3};
// result 값
int result = 3;
int answer = 0;

bool check(vector<int>& v) {
    int ret2 = 0;
    for (int i = 0; i < q.size(); ++i) {
        vector<int> nq = q[i];
        map<int, int> m;
        int ret = 0;
        
        for (int n: nq) {
            ++m[n];
        }
        for (int n: v) {
            ++m[n];
        }
        
        for (auto it: m) {
            if (it.second == 2) ++ret;
        }
        
        if (ans[i] == ret) ++ret2;
    }
    return ret2 == 5;
}

void combi(int idx, vector<int>& v) {
    if (v.size() == m) {
        answer += check(v);
    }
    
    for (int i = idx; i <= n; ++i) {
        v.push_back(i);
        combi(i + 1, v);
        v.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    vector<int> v;
    combi(1, v);
    cout << (answer == result);
    return 0;
}
