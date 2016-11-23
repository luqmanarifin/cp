#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];

int main() {
  int n, a, b, k;
  scanf("%d %d %d %d %s", &n, &a, &b, &k, s + 1);
  a--;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') continue;
    int j = i;
    while (j + 1 <= n && s[j + 1] == '0') j++;
    int len = j - i + 1;
    int slot = len / b;
    int skip = min(slot, a);
    for (int it = skip + 1; it <= slot; it++) {
      ans.push_back(i + it * b - 1);
    }
    a -= skip;
    i = j;
  }
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d ", it);

  return 0;
}
