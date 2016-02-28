#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second

const int N = 1e5 + 5;
const int inf = 1e9;

pair<int, int> p[N];
int cnt[205];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &p[i].x);
  }
  int tot = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &p[i].y);
    tot += p[i].y;
  }
  sort(p, p + n);
  int ans = inf;
  for(int i = 0; i < n; i++) {
    int j = i;
    int cur = p[i].y;
    while(j + 1 < n && p[j + 1].x == p[j].x) {
      cur += p[j + 1].y;
      j++;
    }
    
    int leg = j - i;
    for(int d = 200; d >= 1; d--) {
      int del = min(leg, cnt[d]);
      leg -= del;
      cur += del * d;
    }
    //printf("len %d %d\n", p[i].x, cur);
    ans = min(ans, tot - cur);
    for(int k = i; k <= j; k++) {
      cnt[p[k].y]++;
    }
    i = j;
  }
  cout << ans << endl;
  return 0;
}
