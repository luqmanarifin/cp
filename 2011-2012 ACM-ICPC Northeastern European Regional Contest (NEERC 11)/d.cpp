#include <bits/stdc++.h>

using namespace std;

const string NAME = "dictionary";

const int N = 1e4 + 4;

int to[N * 44][26], nodes = 2, last[N];
set<string> st[26];

void add(char * s, int len) {
  int now = 1;
  for (int i = 0; i < len; ++i) {
    int c = s[i] - 'a';
    if (!to[now][c])
      to[now][c] = nodes++;
    now = to[now][c];
  }
}

long long dfs(int now) {
  long long ret = 0;
  for (int i = 0; i < 26; ++i) {
    if (!to[now][i])
      ret += now > 1 ? st[i].size() : 0;
    else {
      ret += (now > 1 ? last[i] : 0) + dfs(to[now][i]);
    }
  }
  return ret;
}
char s[N];

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  set<string> distinct;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int len;
    add(s, len = strlen(s));
    if (len == 1)
      distinct.insert(s);
    last[s[len-1]-'a'] = 1;
    for (int j = 0; j < len; ++j)
      st[s[j]-'a'].insert(s+j);
  }
  printf("%lld\n", dfs(1) + distinct.size());

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif

  return 0;
}
