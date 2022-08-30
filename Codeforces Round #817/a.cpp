#include <bits/stdc++.h>

using namespace std;

string dict = "Timur";

char cnt[256], s[20], good[256];

int main() {
  for (int i = 0; i < 5; i++) {
    good[dict[i]]++;
  }

  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));

    int n;
    scanf("%d %s", &n, s);
    for (int i = 0; i < n; i++) {
      cnt[s[i]]++;
    }
    bool ok = 1;
    for (int i = 0; i < 256; i++) {
      if (cnt[i] != good[i]) {
        ok = 0;
      }
    }
    puts(ok? "YES" : "NO");
  }

  return 0;
}
