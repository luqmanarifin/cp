#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], lef[N];

long long take(int l, int r) {
  if (l > r) return 0;
  return lef[r] - lef[l - 1];
}

int main() {
  int n;
  scanf("%I64d", &n);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
    sum += a[i];
    lef[i] = lef[i - 1] + a[i];
  }
  if (sum % 2) {
    puts("NO");
    return 0;
  }
  sum /= 2;
  for (int i = 1; i <= n; i++) {
    if (lef[i] == sum) {
      puts("YES");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    long long cur = take(1, i - 1);
    int l = i + 1, r = n;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (cur + take(i + 1, mid) > sum) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    if (cur + take(i + 1, l) == sum) {
      puts("YES");
      return 0;
    }
    
    cur = take(i + 1, n);
    l = 1, r = i - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (cur + take(mid, i - 1) > sum) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    if (cur + take(l, i - 1) == sum) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
