#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int cnt[N];

long long sum(int n) {
  return 1LL * n * (n + 1) / 2;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    memset(a, 0, sizeof(a));
    
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    long long mini = sum(n) - 1;
    long long maxi = 0, nyawa = n - 1;
    for (int i = n; i >= 1; i--) {
      int del = min(nyawa, 2LL);
      maxi += del * i;
      nyawa -= del;
    }
    for (int i = 2; i <= n; i++) cnt[i] = 1;
    if (k < mini || maxi < k) {
      puts("-1");
      continue;
    }
    int to = n;
    k -= mini;
    for (int i = 2; k > 0; i++) {
      int del = min(k, 1LL* to - i);
      k -= del;
      cnt[i]--;
      cnt[i + del]++;
      to--;
    }
    int now = 0;
    for (int i = n; i >= 1; i--) {
      if (cnt[i] == 0) continue;
      now += cnt[i];
      a[now] = i;
    }
    now = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) a[i] = now++;
      printf("%d ", a[i]);
    }
    printf("\n");
  }

  return 0;
}
