
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
vector<int> ans[N];
set<int> p[2];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int one = 0, zero = 0;
  for (int i = 0; i < n; i++) {
    p[s[i] - '0'].insert(i);
    if (s[i] == '0') {
      zero++;
    } else {
      one++;
    }
  }
  int dif = zero - one;
  if (dif <= 0) {
    puts("-1");
    return 0;
  }
  bool ok = 1;
  int at = 0;
  while (!p[0].empty()) {
    int st = *(p[0].begin()), c = 0;
    while (1) {
      auto it = p[c].lower_bound(st);
      if (it == p[c].end()) break;
      st = *it;
      ans[at].push_back(st);
      p[c].erase(st);
      c ^= 1;
    }
    if (ans[at].size() % 2 == 0) {
      puts("-1");
      return 0;
    }
    at++;
  }
  if (!p[1].empty()) {
    puts("-1");
    return 0;
  }
  printf("%d\n", at);
  for (int i = 0; i < at; i++) {
    printf("%d ", ans[i].size());
    for (auto it : ans[i]) printf("%d ", it + 1); printf("\n");
  }

  return 0;
}
