#include <bits/stdc++.h>

using namespace std;

bool is(long long a) {
  long long b = (long long) sqrt(a);
  if(b * b == a) return 1;
  b++;
  if(b * b == a) return 1;
  return 0;
} 

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    bool ada = 0;
    for(int i = 1; i < n; i++) {
      if(is(1LL * n * n - 1LL * i * i)) {
        puts("YES");
        ada = 1;
        break;
      }
    }
    if(!ada) puts("NO");
  }
  
  return 0;
}
