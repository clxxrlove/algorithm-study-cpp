//
//  main.cpp
//  13537
//
//  Created by 정지용 on 1/6/25.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100001];
vector<int> mergetree[400001];

void setDefault() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

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
    return upper_bound(vec.begin(), vec.end(), k) - vec.begin();
  }
  
  int mid = (start + end) / 2;
  int left = query(2 * node, start, mid, i, j, k);
  int right = query(2 * node + 1, mid + 1, end, i, j, k);
  return left + right;
}

int main(int argc, const char * argv[]) {
  setDefault();
  
  int n, m;
  cin >> n;
  
  for (int i = 1; i <= n; i++) cin >> arr[i];
  build(1, 1, n);
  
  cin >> m;
  for (int idx = 0; idx < m; idx++) {
    int i, j, k;
    cin >> i >> j >> k;
    cout << (j - i + 1) - query(1, 1, n, i, j, k) << "\n";
  }
  
  return 0;
}
