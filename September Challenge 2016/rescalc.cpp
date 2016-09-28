#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int score[N];
int cnt[10];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int m;
      scanf("%d", &m);
      memset(cnt, 0, sizeof(cnt));
      for (int j = 0; j < m; j++) {
        int v;
        scanf("%d", &v);
        cnt[v]++;
      }
      sort(cnt + 1, cnt + 7);
      score[i] = m;
      score[i] += cnt[1] * 4 + (cnt[2] - cnt[1]) * 2 + (cnt[3] - cnt[2]) * 1;
    }
    int best = -1, p = -1;
    for (int i = 0; i < n; i++) {
      //printf("%d %d\n", i, score[i]);
      if (score[i] > best) {
        best = score[i];
        p = i;
      } else if (score[i] == best) {
        p = -1;
      }
    }
    if (p == -1) {
      puts("tie");
    } else {
      if (p == 0) {
        puts("chef");
      } else {
        printf("%d\n", p + 1);
      }
    }
  }

  return 0;
}
