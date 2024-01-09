#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
long long s[N];
map<long long, int> done;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    done.clear();

    int n; long long sum = 0;
    scanf("%d", &n);
    done[0]++;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      if (i % 2) {
        sum += a[i];
      } else {
        sum -= a[i];
      }
      done[sum]++;
      s[i] = sum;
    }
    bool has = 0;
    for (int i = 1; i <= n; i++) {
      if (done[s[i]] > 1) {
        has = 1;
      }
    }
    puts(has? "YES" : "NO");
  }

  return 0;
}
