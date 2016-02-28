#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 2e9 + 10;

long long a[N];

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  x--;
  long long mini = inf;
  for(int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
    mini = min(mini, a[i]);
  }
  int p = -1;
  for(int i = x; ; i = (i - 1 + n) % n) {
    if(a[i] == mini) {
      p = i;
      break;
    }
  }
  mini++;
  long long cnt = 0;
  if(x != p) {
    for(int i = (p + 1) % n; ; i = (i + 1) % n) {
      cnt += mini;
      a[i] -= mini;
      if(i == x) {
        break;
      }
    }
  }
  for(int i = (x + 1) % n; ; i = (i + 1) % n) {
    cnt += mini - 1;
    a[i] -= mini - 1;
    if(i == p) {
      break;
    }
  }
  //printf("ambil %d\n", p);
  a[p] = cnt;
  for(int i = 0; i < n; i++) {
    printf("%I64d ", a[i]);
  }
  return 0;
}
