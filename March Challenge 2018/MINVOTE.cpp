 
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
 
int bit[N], a[N];
long long s[N];
 
void add_bit(int i, int v) {
  for (; i < N; i |= i + 1) bit[i] += v;
}
 
void add(int l, int r) {
  add_bit(l, 1);
  add_bit(r + 1, -1);
}
 
int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}
 
long long find(int l, int r) {
  return l <= r? s[r] - s[l - 1] : 0;
}
 
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) bit[i] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", a + i), s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
      int l = 1, r = i - 1;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (find(mid + 1, i - 1) <= a[i]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      if (l == r) add(l, i - 1); //, printf("kiri %d %d\n", l, i);
      
      l = i + 1, r = n;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (find(i + 1, mid - 1) <= a[i]) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      if (l == r) add(i + 1, l); //, printf("kanan %d %d\n", i, l);
    }
    
    for (int i = 1; i <= n; i++) printf("%d ", find(i)); printf("\n");
  }
 
  return 0;
}
