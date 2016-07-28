#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
bool done[N];

int main() {
  int n;
  scanf("%d", &n);
  int root = -1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] == i) {
      root = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (done[i]) continue;
    set<int> s;
    int now = i;
    while (1) {
      if (done[a[now]]) {
        if (s.count(a[now])) {
          if (root == -1) {
            root = now;
            ans += now != a[now];
            a[now] = now;
          } else {
            ans += root != a[now];
            a[now] = root;
          }
        }
        break;
      }
      done[now] = 1;
      s.insert(now);
      now = a[now];
    }
    done[now] = 1;
    s.insert(now);
    now = a[now];
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
