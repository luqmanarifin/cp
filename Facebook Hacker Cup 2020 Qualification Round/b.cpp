#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int n, bef[N], aft[N];
vector<int> cnt[2];

void remove(int x) {
  aft[bef[x]] = aft[x];
  bef[aft[x]] = bef[x];
}

int check(int x) {
  int ori = x;

  int step = 0;
  cnt[0].clear();
  cnt[1].clear();
  while (x > 0 && step < 3) {
    cnt[s[x] - 'A'].push_back(x);
    step++;
    x = bef[x];
  }
  if (step < 3 || cnt[0].size() == 3 || cnt[1].size() == 3) return ori;
  remove(cnt[0][0]);
  remove(cnt[1][0]);
  if (cnt[0].size() > cnt[1].size()) {
    return cnt[0][1];
  } else {
    return cnt[1][1];
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d %s", &n, s + 1);
    for (int i = 0; i < N; i++) {
      bef[i] = i - 1;
      aft[i] = i + 1;
    }
    for (int i = 1; i <= n; i = aft[i]) {
      i = check(i);
    }
    int ada = 0;
    for (int i = aft[0]; i <= n; i = aft[i]) {
      ada++;
    }
    printf("Case #%d: %c\n", tt, ada == 1? 'Y' : 'N');
  }

  return 0;
}
