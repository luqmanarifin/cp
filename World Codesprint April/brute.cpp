#include <bits/stdc++.h>

using namespace std;

int kmp[20];

int sum(string s) {
  int n = s.length() - 1;
  kmp[1] = 0;
  for (int i = 2; i <= n; i = i + 1){
      int l = kmp[i - 1];
      while (l > 0 && s[i] != s[l + 1]){
          l = kmp[l];
      }
      if (s[i] == s[l + 1]){
          kmp[i] = l + 1;
      }
      else{
          kmp[i] = 0;
      }
  }
  int all = 0;
  for(int i = 1; i <= n; i++) {
    all += kmp[i];
  }
  return all;
}

int main() {
  string a = "$aaaacccc", best;
  int ans = 1e9;
  do {
    int cur = sum(a);
    if(cur < ans) {
      ans = cur;
      best = a;
    }
  } while(next_permutation(a.begin() + 1, a.end()));
  cout << ans << endl;
  cout << best << endl;
  return 0;
}