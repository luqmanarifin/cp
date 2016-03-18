#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int dp[15], n, k;
int last[26];
vector<string> ans;
int best;
char s[15];

void find(string str) {
  int len = str.size();
  str = "+" + str;
  dp[0] = 1;
  memset(last, 0, sizeof(last));
  for(int i = 1; i <= len; i++) {
    //printf("%d good\n", i);
    dp[i] = dp[i - 1] * 2;
    int c = str[i] - 'a';
    if (last[c] != 0) dp[i] = (dp[i] - dp[last[c] - 1]);
    last[c] = i;
  }
  if(dp[len] > best) {
    //puts("better");
    best = dp[len];
    ans.clear();
    ans.push_back(str);
  } else if(dp[len] == best) {
    ans.push_back(str);
  }
  //puts("done");
}

void backtrack(int p, int rem) {
  if(rem == 0) {
    //puts("lolol");
    find((string) s);
    return;
  }
  for(int i = 0; i < k; i++) {
    s[p] = 'a' + i;
    backtrack(p + 1, rem - 1);
  }
}

int main() {
  k = 5;
  s[0] = 'b';
  s[1] = 'a';
  s[2] = 'b';
  backtrack(3, 6);
  cout << best << endl;
  for(auto it : ans) cout << it << endl;
  return 0;
}
