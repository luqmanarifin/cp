#include <bits/stdc++.h>

using namespace std;

const int N = 105;

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for (int j = 0; j < 2; j++) {
      vector<int> v;
      for (int i = j; i < n; i += 2) {
        v.push_back(a[i]);
      }
      sort(v.begin(), v.end());
      if (j == 0) {
        reverse(v.begin(), v.end());
      }
      int now = 0;
      for (int i = j; i < n; i += 2) {
        a[i] = v[now];
        now++;
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; i += 2) {
      long long sum = 0;
      for (int j = i + 1; j < n; j += 2) sum += a[j];
      ans += sum * a[i];
    }
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i + 1 == n? '\n' : ' ');
    printf("%lld\n", ans);
  }

  return 0;
}
