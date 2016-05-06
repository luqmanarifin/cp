#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

map<int, int> cnt;
int b[N], c[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  int m;
  scanf("%d", &m);
  for(int i = 1; i <= m; i++) {
    scanf("%d", b + i);
  }
  for(int i = 1; i <= m; i++) {
    scanf("%d", c + i);
  }
  pair<int, int> best = {-1, -1};
  int p = -1;
  for(int i = 1; i <= m; i++) {
    pair<int, int> cur = {cnt[b[i]], cnt[c[i]]};
    if(cur > best) {
      best = cur;
      p = i;
    }
  }
  cout << p << endl;
  return 0;
}