#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> l, r, p;

void remove(int x, int n) {
  int rig = r[x];
  int lef = l[x];
  l[rig] = lef;
  r[lef] = rig;
}

long long solve(vector<int> a) {
  // for (auto it : a) printf("%d ", it); printf("\n");
  int n = a.size();
  p = {0};
  for (auto it : a) p.push_back(it);
  l = r = vector<int>(n + 2);
  for (int i = 0; i <= n + 1; i++) {
    l[i] = i - 1;
    r[i] = i + 1;
  }
  long long ans = 0;
  for (int i = r[0]; i <= n;) {
    if (r[i] <= n && p[i] % 2 == p[r[i]] % 2) {
      ans += (p[r[i]] - p[i]) / 2;
      ans += p[i];
      remove(i, n);
      remove(r[i], n);
      i = l[i];
      if (i == 0) i = r[i];
    } else {
      i = r[i];
    }
  }
  for (int i = r[0]; i <= n; i = r[i]) {
    ans += (p[i] + 1) / 2;
  }
  return ans;
}

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s);
    int cur = 0, b = 0;
    long long ans = 0;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B') {
        b++;
      } else {
        ans += 1LL * (b / 2) * cur;
        if (b % 2 && cur > 0) {
          a.push_back(cur);
        }
        cur++;
        b = 0;
      }
    }
    ans += 1LL * (b / 2) * cur;
    if (b % 2 && cur > 0) {
      a.push_back(cur);
    }
    printf("%lld\n", ans + solve(a));
  }

  return 0;
}
