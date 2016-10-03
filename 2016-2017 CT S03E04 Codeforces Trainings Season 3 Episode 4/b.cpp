#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[105][1005];
int big[1005][2];
int all[N];
int tmp[1005];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
        all[i * m + j] = a[i][j];
      }
      sort(a[i], a[i] + m);
    }
    sort(all, all + n * m);
    for (int j = 0; j < m; j++) {
      vector<int> v;
      for (int i = 0; i < n; i++) {
        v.push_back(a[i][j]);
      }
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
      big[j][0] = v[0];
      big[j][1] = v[1];
    }
    for (int i = 0; i < n; i++) {
      int mn = 0, mk = 0;
      for (int j = 0; j < m; j++) {
        int big_all = n * m - (lower_bound(all, all + n * m, a[i][j]) - all);
        int big_own = m - (lower_bound(a[i], a[i] + m, a[i][j]) - a[i]);
        int win_pos = big_all - big_own;
        if (win_pos <= m - 1 - j) {
          mn++;
        }

        if (a[i][j] == big[j][0]) {
          tmp[j] = big[j][1];
        } else {
          tmp[j] = big[j][0];
        }
      }
      int b = 0;
      for (int j = 0; j < m; j++) {
        if (a[i][j] > tmp[b]) {
          b++;
          mk++;
        }
      }
      printf("%d %d\n", mn, mk);
    }
  }

  return 0;
}
