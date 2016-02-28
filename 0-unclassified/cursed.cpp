#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long pre[N];

int main() {
  int n, q;
  long long sum = 0;
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; i++) { 
    long long a;
    scanf("%I64d", &a);
    pre[i] = a + (i? pre[i - 1] : 0);
    sum += a;
  }
  while(q--) {
    long long t;
    scanf("%I64d", &t);
    t %= sum;
    int l = 0, r = n - 1;
    while(l < r) {
      int mid = (l + r) >> 1;
      if(t < pre[mid]) r = mid;
      else l = mid + 1;
    }
    printf("%d\n", l + 1);
  }
  return 0;
}
