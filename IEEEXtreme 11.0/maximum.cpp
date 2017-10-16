#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], l, r, cnt[N];

void lef(int v) {
  a[l++] = v;
}

void rig(int v) {
  a[r--] = v;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    
    int n;
    scanf("%d", &n);
    l = 0; r = n - 1;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      cnt[a[i]]++;
    }
    // 0 kiri, 1 kanan
    int pt = 0;
    for (int i = 0; i < cnt[0]; i++) lef(0);
    for (int i = 1; i < N; i++) {
      if (cnt[i] > 1) {
        for (int j = 1; j < cnt[i]; j++) lef(i);
        rig(i);
        pt = 0;
      } else if (cnt[i] == 1) {
        if (pt == 0) {
          lef()
        }
      }
    }
  }

  return 0;
}
