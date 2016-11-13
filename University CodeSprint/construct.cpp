#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n, S, K;
int a[N];

int calc() {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      assert(a[i] <= a[j]);
      ret += a[j] - a[i];
    }
  }
  return ret;
}

void dfs(int now, int sum) {
  //printf("%d %d\n", now, sum);
  if (now == n - 1) {
    a[now] = sum;
    sort(a, a + n);
    if (calc() != K) {
      puts("-1");
    } else {
      for (int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
    }
    return;
  }
  int l = (now? a[now - 1] : 0), r = sum / (n - now);
  if (r < l) {
    puts("-1");
    return;
  }
  int ada = n - now - 1;
  //printf("saat %d: %d %d\n", now, l, r);
  while (l < r) {
    int mid = (l + r) >> 1;
    a[now] = mid;
    
    int rem = sum - mid;
    for (int i = now + 1; i < n; i++) {
      a[i] = rem / ada;
    }
    if (ada)
    for (int i = 1; i <= rem % ada; i++) {
      a[n - i]++;
    }
    if (calc() > K) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  a[now] = l;
  dfs(now + 1, sum - l);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &S, &K);
    dfs(0, S);
  }
  return 0;
}
