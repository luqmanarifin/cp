#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];
int cnt[N];
int last[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    for(int j = 0; j < i; j++) {
      cnt[abs(a[i] - a[j])]++;
    }
  }
  int max_pair = (k + 1) * k / 2;
  for(int d = n - k; d < N; d++) {
    int sz = 0;
    for(int i = 0; i < N; i += d) {
      sz += cnt[i];
      if(sz > max_pair) break;
    }
    if(sz > max_pair) continue;
    int t = 0;
    for(int i = 0; i < n; i++) {
      if(last[a[i] % d] == d) t++;
      last[a[i] % d] = d;
    }
    if(t <= k) {
      cout << d << endl;
      return 0;
    }
  }
  
  return 0;
}
