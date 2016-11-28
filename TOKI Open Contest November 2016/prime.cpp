#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

bool is[N];

int main() {
  is[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      for (long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  vector<int> p, ok;
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    if (is[v]) {
      ok.push_back(v);
    } else {
      p.push_back(v);
    }
  }
  sort(ok.begin(), ok.end());
  sort(p.begin(), p.end());
  int ans = 0;
  for (int i = 0; i < ok.size(); i++) {
    if (k >= ok[i]) {
      ans++;
      k -= ok[i];
    } else {
      break;
    }
    if (k == 0) break;
  }
  for (int i = 0; i < p.size() && i < 1; i++) {
    if (k >= p[i]) {
      ans++;
    }
  }
  if (ans == n) {
    puts("One Punch!");
  } else {
    printf("%d\n", ans);
  }
  return 0;
}
