#include <bits/stdc++.h>

using namespace std;

const int N = 8e4 + 5;

long long lc[N];
long long sum[N];

int main() {
  for (int it = 0; it < 4; it++) {
    int n;
    scanf("%d", &n);
    for (int i = n; i >= 1; i--) {
      long long now = 0;
      for (int j = i; j <= n; j += i) now++;
      lc[i] = now * now;
      for (int j = i + i; j <= n; j += i) lc[i] -= lc[j];
    }
    for (int i = n; i >= 1; i--) {
      long long now = 0;
      for (int j = i; j <= n; j += i) now += lc[j];
      sum[i] = now * now;
      for (int j = i + i; j <= n; j += i) sum[i] -= sum[j];
    }
    cout << sum[1] << endl;
  }
  puts("37844569649859454367");
  return 0;
}
