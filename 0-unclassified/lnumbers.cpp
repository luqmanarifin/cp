#include <bits/stdc++.h>

using namespace std;

int len(int num, int base) {
  int ret = 0;
  while(num) {
    ret++;
    num /= base;
  }
  return (ret? ret : 1);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int l = 2, r = n + 1;
    while(l < r) {
      int mid = (l + r) >> 1;
      if(len(n, mid) > k) l = mid + 1;
      else r = mid;
    }
    if(len(n, l) == k) puts("YES");
    else puts("NO");
  }
  
  return 0;
}
