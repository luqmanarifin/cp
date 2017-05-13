#include "jump.h"

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int inf = 1e9;

// L - K - R
vector<tuple<int, int, int>> query;
vector<int> ans;
vector<tuple<int, int, int>> ask[N];
string S;
int dp[N];

vector<int> getMinimumPoints(int n, int q, string _S, vector<int> L, vector<int> R, vector<int> K) {
  S = _S;
  int cnt = 0;
  for (int i = 0; i < n; i++) if (S[i] != '0') cnt++;
  if (cnt > 75) {
    for (int i = 0; i < q; i++) {
      L[i]--;
      R[i]--;
    }
    vector<int> non;
    for (int i = 0; i < n; i++) if (S[i] != '0') non.push_back(i);
    for (int it = 0; it < q; it++) {
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
        query.emplace_back(l, k, r);
        ask[it].emplace_back(l, k, r);
        i = j;
      }
    }
    //puts("populate done");
    sort(query.begin(), query.end());
    query.resize(distance(query.begin(), unique(query.begin(), query.end())));
    ans.resize(query.size());
    
    /*
    for (auto it : query) {
      int l, k, r;
      tie(l, k, r) = it;
      printf("%d %d %d\n", l, k, r);
    }
    */
    
    for (int i = 0; i < query.size(); ) {
      int l, k, r;
      tie(l, k, r) = query[i];
      
      int j = i + 1;
      vector<int> to;
      to.push_back(r);
      while (j < query.size()) {
        int ll, kk, rr;
        tie(ll, kk, rr) = query[j];
        if (l == ll && k == kk) {
          to.push_back(rr);
          j++;
        } else {
          break;
        }
      }
      //printf("answering %d to %d\n", i, j - 1);
      if (to.back() < l + k) {
        for (int p = i; p < j; p++) ans[p] = 0;
        i = j;
        continue;
      }
      
      int p = 0;
      for (int it = 0; it < to.back() - l + 1; it++) dp[it] = inf;
      dp[0] = 0;
      multiset<int> s;
      s.insert(0);
      if (to[p] == l) {
        ans[i] = 0;
        p++;
      }
      for (int pos = l + 1; p < to.size(); pos++) {
        if (pos - k - 1 >= l) {
          s.erase(s.find(dp[pos - k - 1 - l]));
        }
        //printf("k %d: %d %d\n", k, l, pos);
        //for (auto it : s) printf("%d ", it); printf("\n");
        dp[pos - l] = *(s.begin()) + (S[pos] - '0');
        s.insert(dp[pos - l]);
        if (to[p] == pos) {
          ans[i + p] = dp[pos - l] - (S[pos] - '0');
          p++;
        }
      }
      
      i = j;
    }
    /*
    for (int i = 0; i < query.size(); i++) {
      int l, k, r;
      tie(l, k, r) = query[i];
      printf("answer %d %d %d: %d\n", l, k, r, ans[i]);
    }
    */
    vector<int> ret;
    for (int i = 0; i < q; i++) {
      int cur = S[L[i]] - '0' + S[R[i]] - '0';
      for (auto it : ask[i]) {
        cur += ans[lower_bound(query.begin(), query.end(), it) - query.begin()];
      }
      ret.push_back(cur);
    }
    return ret;
  } else {
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
}