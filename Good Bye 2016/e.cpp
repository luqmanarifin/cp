#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int to[N];

int six[N], sev[N];
set<int> pos[10];

int main() {
  fill(to, to + N, 2e9);
  
  int n, q;
  scanf("%d %d %s", &n, &q, s + 1);
  for (int i = n; i >= 1; i--) {
    pos[s[i] - '0'].insert(i);
    int now = -1;
    auto it = pos[2].lower_bound(now);
    if (it != pos[2].end()) {
      now = *it;
      it = pos[0].lower_bound(now);
      if (it != pos[0].end()) {
        now = *it;
        it = pos[1].lower_bound(now);
        if (it != pos[1].end()) {
          now = *it;
          to[i] = now;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i) {
      six[i] += six[i - 1];
      sev[i] += sev[i - 1];
    }
    if (s[i] == '6') {
      six[i]++;
    }
    if (s[i] == '7') {
      sev[i]++;
    }
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    if (to[l] >= r) {
      puts("-1");
      continue;
    }
    if (sev[r] - sev[to[l]] == 0) {
      puts("-1");
      continue;
    }
    printf("%d\n", six[r] - six[to[l]]);
  }

  return 0;
}
