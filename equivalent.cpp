#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
 
char a[N], b[N];

bool equal(int l, int r, int ll, int rr) {
  int len = r - l + 1;
  for(int i = 0; i < len; i++) {
    if(a[l + i] != b[ll + i]) {
      return 0;
    }
  }
  //printf("%d %d %d %d\n", l, r, ll, rr);
  return 1;
}

bool solve(int l, int r, int ll, int rr) {
  int len = r - l + 1;
  if(len % 2) {
    return equal(l, r, ll, rr);
  }
  if(equal(l, r, ll, rr)) {
    return 1;
  }
  //printf("%d %d %d %d\n", l, r, ll, rr);
  int md = (l + r) >> 1;
  int mid = (ll + rr) >> 1;
  if(solve(l, md, ll, mid) && solve(md + 1, r, mid + 1, rr)) {
    return 1;
  }
  if(solve(l, md, mid + 1, rr) && solve(md + 1, r, ll, mid)) {
    return 1;
  }
  return 0;
}

int main() {
  scanf("%s %s", a, b);
  int n = strlen(a);
  puts(solve(0, n - 1, 0, n - 1)? "YES" : "NO");
  return 0;
}
