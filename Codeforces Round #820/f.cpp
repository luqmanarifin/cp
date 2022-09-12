#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int D = 9;

char s[N];
int sum[N];
vector<int> id[D];

int find(int l, int r) {
  int cnt = (sum[r] - sum[l - 1]) % D;
  if (cnt < 0) cnt += D;
  return cnt;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < D; i++) id[i].clear();

    scanf("%s", s + 1);
    int w, m;
    scanf("%d %d", &w, &m);
    int n = strlen(s + 1);

    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + (s[i] - '0');
      sum[i] %= D;
    }
    vector<int> st;
    for (int i = 1; i + w - 1 <= n; i++) {
      int v = find(i, i + w - 1);
      if (id[v].empty()) {
        st.push_back(i);
      }
      id[v].push_back(i);
    }

    while (m--) {
      int l, r, k;
      scanf("%d %d %d", &l, &r, &k);
      int mid = find(l, r);
      int p = -1, q = -1;
      for (auto it : st) {
        int x = (k - find(it, it + w - 1) * mid) % D;
        if (x < 0) x += D;
        for (auto jt : id[x]) {
          if (it == jt) continue;
          p = it;
          q = jt;
          goto HERE;
        }
      }
      HERE:;
      printf("%d %d\n", p, q);
    }
  }

  return 0;
}
