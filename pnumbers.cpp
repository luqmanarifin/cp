#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];
int ans, t;
int num[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for(int i = 1; i <= n; ) {
    int l = i, r = i;
    while(r + 1 <= n && a[r + 1] % a[i] == 0) r++;
    while(l - 1 >= 1 && a[l - 1] % a[i] == 0) l--;
    i = r + 1;
    r -= l;
    if(r > ans) ans = r, t = 0;
    if(r == ans) num[t++] = l;
  }
  printf("%d %d\n", t, ans);
  sort(num, num + t);
  for(int i = 0; i < t; i++) {
    printf("%d ", num[i]);
  }
  
  return 0;
}
