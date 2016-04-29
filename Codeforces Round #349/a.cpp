#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

char s[N];
set<string> ans;
bool dp[N][3];

string get(int l, int r) {
  string str;
  for(int i = l; i <= r; i++) {
    str.push_back(s[i]);
  }
  return str;
}

void dfs(int now, string got) {
  if(dp[now][got.size()]) return;
  dp[now][got.size()] = 1;
  if(now < 4) return;
  if(got.size()) ans.insert(got);
  if(get(now - 1, now) != got) {
    dfs(now - 2, get(now - 1, now));
  }
  if(get(now - 2, now) != got) {
    dfs(now - 3, get(now - 2, now));
  }
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  dfs(n - 1, "");
  printf("%d\n", ans.size());
  for(auto it : ans) printf("%s\n", it.c_str());
  return 0;
}