#include <bits/stdc++.h>

using namespace std;

int main() {
  int mn = 0, pl = 0;
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    (a == 1? pl++ : mn++);
  }
  while(m--) {
    int l, r;
    scanf("%d %d", &l, &r);
    int cnt = r - l + 1;
    if(cnt & 1) {
      puts("0");
    } else {
      if(cnt / 2 <= mn && cnt / 2 <= pl) puts("1");
      else puts("0");
    }
  }
  
  return 0;
}
