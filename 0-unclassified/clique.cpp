#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

pair<int, int> p[N];
#define w first
#define x second

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.w + a.x <= b.w + b.x;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &p[i].x, &p[i].w);
  }
  sort(p, p + n, cmp);
  int last = 0;
  int ans = 1;
  for(int i = 1; i < n; i++) {
    if(p[i].x - p[i].w >= p[last].x + p[last].w) {
      ans++;
      last = i;
    }
  }
  cout << ans << endl;
  return 0;
}