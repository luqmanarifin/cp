#include <bits/stdc++.h>

using namespace std;

const int N = 105;

bool done[N];
int ans[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(done, 0, sizeof(done));

    int n, k;
    scanf("%d %d", &n, &k);
    bool can = 1;
    for (int i = 1; i <= n; i++) {
      bool udah = 0; int at = -1;
      vector<int> num;
      for (int j = 1; j <= i; j++) {
        int v;
        scanf("%d", &v);
        num.push_back(v);
      }
      sort(num.begin(), num.end());
      for (auto it : num) {
        if (!done[it] && !udah) {
          done[it] = 1;
          at = it;
          udah = 1;
        }
      }
      ans[i] = at;
      if (!udah) {
        can = 0;
      }
    }
    printf("Kasus #%d:", tt);
    if (!can) {
      printf(" Tidak ada pembagian\n");
    } else {
      for (int i = 1; i <= n; i++) printf(" %d", ans[i]); printf("\n");
    }
  }

  return 0;
}
