#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long b[N], c[N], a[N];
long long bit[64];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
    sum += b[i] + c[i];
  }
  if (sum % (2 * n)) {
    puts("-1");
    return 0;
  }
  sum /= 2 * n;
  for (int i = 0; i < n; i++) {
    a[i] = (b[i] + c[i]) - sum;
    if (a[i] % n) {
      puts("-1");
      return 0;
    }
    a[i] /= n;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 63; j++) {
      if (a[i] & (1LL << j)) {
        bit[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    long long andd = 0, orr = 0;
    for (int j = 0; j < 63; j++) {
      if (a[i] & (1LL << j)) {
        orr += (1LL << j) * n;
        andd += (1LL << j) * bit[j];
      } else {
        orr += (1LL << j) * bit[j];
      }
    }
    if (andd != b[i] || orr != c[i]) {
      puts("-1");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) printf("%I64d ", a[i]);
  return 0;
}
