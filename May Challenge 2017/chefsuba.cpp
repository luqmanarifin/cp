#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], s[N];
int ans[N], take[N];
char q[N];

int main() {
  int n, k, p;
  scanf("%d %d %d", &n, &k, &p);
  k = min(k, n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    a[n + i] = a[i];
    s[i] += a[i];
    s[n + i] += a[i];
  }
  scanf("%s", q);
  for (int i = 1; i <= 2 * n; i++) s[i] += s[i - 1];
  for (int i = 1; i <= n; i++) {
    take[i] = s[i + k - 1] - s[i - 1];
    take[n + i] = take[i]; 
  }
  multiset<int> mul;
  for (int i = 1; i + k - 1 <= n; i++) mul.insert(take[i]);
  for (int i = 1; i <= n; i++) {
    int at = (i - 1);
    ans[at] = *(mul.rbegin());
    mul.insert(take[i+n-k+1]);
    mul.erase(mul.find(take[i]));
  }
  int now = 0;
  for (int i = 0; i < p; i++) {
    if (q[i] == '!') {
      now = (now - 1 + n) % n;
    } else {
      printf("%d\n", ans[now]);
    }
  }
  return 0;
}
