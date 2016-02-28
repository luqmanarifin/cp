#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  while(n--) {
    int k;
    scanf("%d", &k);
    while(k--) {
      int v;
      scanf("%d", &v);
      a[v] = 1;
    }
  }  
  bool all = 1;
  for(int i = 1; i <= m; i++) if(!a[i]) all = 0;
  puts(all? "YES" : "NO");
  return 0;
}
