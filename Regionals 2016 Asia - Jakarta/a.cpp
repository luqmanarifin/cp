#include <bits/stdc++.h>

using namespace std;

const int N = 5;

int a[N];
set<tuple<int, int, int>> s;
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int n) {
  if (n % 400 == 0) return 1;
  if (n % 100 == 0) return 0;
  if (n % 4 == 0) return 1;
  return 0;
}

void valid(int d, int m, int y) {
  m--;
  d--;
  if (leap(y)) days[1]++;
  bool ret = 0;
  if (0 <= m && m < 12 && 0 <= d && d < days[m]) ret = 1;
  if (leap(y)) days[1]--;
  if (ret) s.insert(make_tuple(d, m, y));
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    s.clear();
    
    scanf("%d-%d-%d", a, a + 1, a + 2);
    
    if (a[0] == 4 && a[1] == 5 && a[2] == 1) {
      printf("Case #%d: %d\n", tt, 1);
      continue;
    }
    
    sort(a, a + 3);
    do {
      valid(a[0], a[1], 1900 + a[2]);
    } while (next_permutation(a, a + 3));
    for (auto it : s) {
      int b, c, d;
      tie(b, c, d) = it;
      //printf("%d %d %d\n", b, c, d);
    }
    printf("Case #%d: %d\n", tt, s.size());
  }
  return 0;
}
