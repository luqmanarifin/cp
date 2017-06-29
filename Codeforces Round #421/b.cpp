#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];
long long sup[N], cup[N];
long long sdo[N], cdo[N];
long long at[N];

void add_up(int l, int r, int val) {
  sup[l] += val;
  cup[l]++;
  sup[r] -= val + r - l;
  cup[r]--;
}

void add_down(int l, int r, int val) {
  sdo[l] += val;
  cdo[l]++;
  sdo[r] -= val - r + l;
  cdo[r]--; 
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    if (i < a[i]) {
      int b = 0;
      int c = a[i] - i;
      int d = n - i;
      add_down(b, c, a[i] - i);
      add_up(c, d, 0);
      add_down(d, n, a[i]);
    } else {
      int b = 0;
      int c = n - i;
      int d = n + a[i] - i;
      //printf("%d: %d\n", i, i - a[i]);
      add_up(b, c, i - a[i]);
      add_down(c, d, a[i]);
      add_up(d, n, 0);
    }
  }
  long long nowsum = 0;
  long long nowcnt = 0;
  for (int i = 0; i < n; i++) {
    nowsum += sup[i] + nowcnt;
    at[i] += nowsum;
    nowcnt += cup[i];
  }
  nowsum = 0;
  nowcnt = 0;
  for (int i = 0; i < n; i++) {
    nowsum += sdo[i] - nowcnt;
    at[i] += nowsum;
    nowcnt += cdo[i];
  }
  long long ans = 1e18;
  int p = -1;
  for (int i = 0; i < n; i++) {
    //printf("%lld ", at[i]);
    if (at[i] < ans) {  
      ans = at[i];
      p = i;
    }
  }
  //printf("\n");
  printf("%lld %d\n", ans, p);
  return 0;
}
