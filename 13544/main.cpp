//
//  main.cpp
//  13544
//
//  Created by 정지용 on 1/6/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> mergetree[400001];
int arr[100001];

void build(int node, int start, int end) {
  if (start == end) {
    mergetree[node].push_back(arr[start]);
  } else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    
    vector<int>& l = mergetree[2 * node];
    vector<int>& r = mergetree[2 * node + 1];
    mergetree[node].resize(l.size() + r.size());
    merge(l.begin(), l.end(), r.begin(), r.end(), mergetree[node].begin());
  }
}

int query(int node, int start, int end, int i, int j, int k) {
  if (j < start || end < i) return 0;
  if (i <= start && end <= j) {
    const vector<int>& vec = mergetree[node];
    return vec.end() - upper_bound(vec.begin(), vec.end(), k);
  }
  
  int mid = (start + end) / 2;
  int left = query(2 * node, start, mid, i, j, k);
  int right = query(2 * node + 1, mid + 1, end, i, j, k);
  return left + right;
}

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  int n, m, last_ans = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  build(1, 1, n);
  
  cin >> m;
  for (int _ = 0; _ < m; ++_) {
    int i, j, k;
    cin >> i >> j >> k;
    last_ans = query(1, 1, n, i ^ last_ans, j ^ last_ans, k ^ last_ans);
    cout << last_ans << "\n";
  }
  
  return 0;
}
