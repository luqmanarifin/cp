#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

char s[N];

int ok(int l, int r) {
  int len = r - l + 1;
  if(len % 2) return len;
  int mid = (l + r) >> 1;
  int lef = ok(l, mid);
  int rig = ok(mid + 1, r);
  int ret = max(lef, rig);
  bool nice = 1;
  for(int i = 0; i < len / 2; i++) {
    if(s[l + i] != s[r - i]) {
      nice = 0;
      break;
    }
  }
  if(nice) return ret;
  return len;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%s", s);
    int n = strlen(s);
    int ret = ok(0, n - 1);
    printf("Case #%d: ", tt);
    for(int i = 0; i < ret; i++) {
      printf("%c", s[i]);
    }
    printf("\n");
  }
  
  return 0;
}
