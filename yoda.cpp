#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  vector<int> aa, bb;
  while(a) {
    aa.push_back(a % 10);
    a /= 10;
  }
  while(b) {
    bb.push_back(b % 10);
    b /= 10;
  }
  bool ha[aa.size()], hb[bb.size()];
  memset(ha, 0, sizeof(ha));
  memset(hb, 0, sizeof(hb));
  int cnta = 0, cntb = 0;
  for(int i = 0; i < min(aa.size(), bb.size()); i++) {
    if(aa[i] < bb[i]) ha[i] = 1, cnta++;
    if(aa[i] > bb[i]) hb[i] = 1, cntb++;
  }
  if(cnta == aa.size()) {
    puts("YODA");
  } else {
    int ans = 0;
    for(int i = (int) aa.size() - 1; i >= 0; i--) {
      if(ha[i]) continue;
      ans = ans * 10 + aa[i];
    }
    printf("%d\n", ans);
  }
  
  if(cntb == bb.size()) {
    puts("YODA");
  } else {
    int ans = 0;
    for(int i = (int) bb.size() - 1; i >= 0; i--) {
      if(hb[i]) continue;
      ans = ans * 10 + bb[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
