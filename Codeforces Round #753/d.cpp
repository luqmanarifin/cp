#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], cnt[N];
char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) cnt[i] = 0;

    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    scanf("%s", s);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R') {
        pq.push(max(1, a[i]));
      } else {
        int at = min(n, a[i]);
        if (at >= 1) {
          cnt[at]++;
        }
      }
    }
    bool good = 1;
    int stock = 0;
    for (int i = n; i >= 1; i--) {
      while (!pq.empty() && pq.top() > i) pq.pop();
      stock += cnt[i];
      if (!pq.empty()) {
        pq.pop();
      } else {
        if (stock >= 1) {
          stock--;
        } else {
          good = 0;
        }
      }
    }
    puts(good? "YES" : "NO");
  }

  return 0;
}
