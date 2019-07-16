#include <bits/stdc++.h>

using namespace std;

const int N = 305;

char s[N][N];
int p[N], n, m, k;
int ans[N * N];

vector<int> solve(int now) {
  int size = n * m;
  vector<int> num;
  while (size > 0) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      while (p[j] < n && s[p[j]][j] == (now + 'A')) {
        cnt++;
        size--;
        p[j]++;
      }
    }
    num.push_back(cnt);
    now ^= 1;
  }
  sort(num.begin(), num.end());
  return num;
}

void entry(vector<int> a) {
  int sum = 0;
  for (int i = 0; i < a.size(); i++) {
    for (int j = sum; j < sum + a[i]; j++) {
      ans[j] = min(ans[j], (int) a.size() - i);
    }
    sum += a[i];
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < N * N; i++) ans[i] = N * N;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    memset(p, 0, sizeof(p));
    auto a = solve(0);
    memset(p, 0, sizeof(p));
    auto b = solve(1);

    // for (auto it : a) printf("%d ", it); printf("\n");
    // for (auto it : b) printf("%d ", it); printf("\n");

    entry(a);
    entry(b);
    printf("Case #%d:", tt);
    while (k--) {
      int v;
      scanf("%d", &v);
      printf(" %d", ans[v]);
    }
    printf("\n");
  }

  return 0;
}