#include "jump.h"

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int inf = 1e9;

// L - K - R
string S;
int dp[N];

int solve(int l, int k, int r) {
  if (r - l <= k) return 0;
  for (int i = 0; i < r - l + 1; i++) dp[i] = inf;
  dp[0] = 0;
  multiset<int> s;
  s.insert(0);
  for (int pos = l + 1; pos <= r; pos++) {
    if (pos - k - 1 >= l) {
      s.erase(s.find(dp[pos - k - 1 - l]));
    }
    dp[pos - l] = *(s.begin()) + (S[pos] - '0');
    s.insert(dp[pos - l]);
  }
  return dp[pos - r] - (S[r] - '0');
}

vector<int> getMinimumPoints(int n, int q, string _S, vector<int> L, vector<int> R, vector<int> K) {
  S = _S;
  for (int i = 0; i < q; i++) {
    L[i]--;
    R[i]--;
  }
  vector<int> non;
  for (int i = 0; i < n; i++) if (S[i] != '0') non.push_back(i);
  vector<int> ret;
  for (int it = 0; it < q; it++) {
    int cur = S[L[it]] - '0' + S[R[it]] - '0';
    int p = lower_bound(non.begin(), non.end(), L[it]) - non.begin();
    int q = lower_bound(non.begin(), non.end(), R[it]) - non.begin();
    if (p < non.size() && non[p] == L[it]) {
      
    } else {
      p--;
    }
    for (int i = p + 1; i < q; i++) {
      int j = i;
      while (j + 1 < q && non[j+1] == non[j] + 1) j++;
      
      int l = non[i] - 1;
      int r = non[j] + 1;
      int k = K[it];
      if (r - l > k) {
        for (int i = 0; i < r - l + 1; i++) dp[i] = inf;
        dp[0] = 0;
        multiset<int> s;
        s.insert(0);
        for (int pos = l + 1; pos <= r; pos++) {
          if (pos - k - 1 >= l) {
            s.erase(s.find(dp[pos - k - 1 - l]));
          }
          dp[pos - l] = *(s.begin()) + (S[pos] - '0');
          s.insert(dp[pos - l]);
        }
        cur += dp[r - l] - (S[r] - '0');
      }
      i = j;
    }
    ret.push_back(cur);
  }
  return ret;
}
