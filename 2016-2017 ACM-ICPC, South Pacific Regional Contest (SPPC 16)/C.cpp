#include <bits/stdc++.h>

using namespace std;

#define MAXN 500000

int a[MAXN+5], t[MAXN+5];
bitset<MAXN+5> b, o;

int main()
{
  int n, p;
  string s;
  
  scanf("%d%d", &n, &p);
  cin >> s;
  
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'B') a[i] = 0;
    if (s[i] == 'R') a[i] = 1;
    if (s[i] == 'Y') a[i] = 2;
  }
  
  for (int c = 0; c < 3; ++c) {
    for (int i = 0; i < n; ++i) {
      b[i] = (a[i] == c);
    }
    o = b;
    int col = b.count();
    for (int i = 1; i < n; ++i) {
      int tmp = b[n-1];
      b <<= 1;
      b[0] = tmp;
      b[n] = 0;
      int diff = (o & b).count();
      t[i] += col-diff;
    }
  }
  vector<pair<int,int>> shifts;
  for (int i = 1; i < n; ++i) {
    shifts.push_back(make_pair(t[i], i));
  }
  sort(shifts.begin(), shifts.end());
  int val = shifts[p-1].first;
  int ans = n;
  for (int i = 0; i < shifts.size(); ++i) {
    if (shifts[i].first == val) ans = min(ans, shifts[i].second);
  }
  printf("%d\n", ans);
  return 0;
}