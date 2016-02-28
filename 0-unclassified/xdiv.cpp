#include <bits/stdc++.h>

using namespace std;

int cnt[10];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  int c124 = cnt[4];
  c124 = min(c124, cnt[2]);
  c124 = min(c124, cnt[1]);
  cnt[2] -= c124;
  cnt[1] -= c124;
  
  int c126 = min(cnt[1], min(cnt[2], cnt[6]));
  cnt[1] -= c126;
  cnt[6] -= c126;
  
  int c136 = min(cnt[1], min(cnt[3], cnt[6]));
  if((c124 + c126 + c136) * 3 != n) {
    puts("-1");
    return 0;
  }
  for(int i = 0; i < c124; i++) {
    puts("1 2 4");
  }
  for(int i = 0; i < c126; i++) {
    puts("1 2 6");
  }
  for(int i = 0; i < c136; i++) {
    puts("1 3 6");
  }
  
  return 0;
}
