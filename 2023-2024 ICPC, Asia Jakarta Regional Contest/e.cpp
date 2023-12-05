#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> c(2 * n), next_maxi(2 * n);
  vector<pair<int, int>> segments;
  set<int> st;
  for (int i = 0; i < 2 * n; ++i) {
    cin >> c[i];
    st.insert(c[i]);
  }
  int last = 2 * n-1;
  for (int i = 2 * n - 1; i >= 0; --i) {
    if (*st.rbegin() == c[i]) {
      segments.emplace_back(i, last);
      last = i-1;
    }
    st.erase(c[i]);
  }
  reverse(segments.begin(), segments.end());
  vector<vector<int>> dp(segments.size()+1, vector<int>(n+1, -1));
  dp[0][0] = 0;
  
  for (int i = 0; i < segments.size(); ++i) {
    int lef = segments[i].first, rig = segments[i].second;
    int sz = rig - lef + 1;
    for (int j = 0; j <= n; ++j) {
      if (dp[i][j] < 0) continue;
      dp[i+1][j] = 0;
      if (j + sz <= n) {
        dp[i+1][j+sz] = sz;
      }
    }
  }
  if (dp[segments.size()][n] < 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> a;
  int now = n;
  vector<int> picked(segments.size(), 0);
  for (int i = segments.size(); i > 0; --i) {
    assert(dp[i][now] >= 0);
    if (dp[i][now] > 0) {
      now -= dp[i][now];
      for (int j = segments[i-1].second; j >= segments[i-1].first; --j) {
        a.push_back(c[j]);
      }
      picked[i-1] = 1;
    }
  }
  reverse(a.begin(), a.end());
  vector<int> b;
  for (int i = 0; i < segments.size(); ++i) {
    if (picked[i]) continue;
    for (int j = segments[i].first; j <= segments[i].second; ++j) {
      b.push_back(c[j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << b[i] << ' ';
  }
  cout << endl;
  return 0;
}