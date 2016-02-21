#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int a[N];

int main() {
  int n, k;
  scanf("%d %d %s", &n, &k, s);
  int pol = 0;
  for(int i = 0; i < n; i++) {
    a[i] = s[i] - 'a';
    pol += max(a[i], 25 - a[i]);
  }
  if(pol < k) {
    puts("-1");
    return 0;
  }
  for(int i = 0; i < n; i++) {
    int del = min(k, max(a[i], 25 - a[i]));
    k -= del;
    if(a[i] + del < 26) {
      printf("%c", a[i] + del + 'a');
    } else {
      printf("%c", a[i] - del + 'a');
    }
  }
  return 0;
}