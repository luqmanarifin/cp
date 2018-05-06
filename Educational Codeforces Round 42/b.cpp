
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];

int main() {
  int n, a, b;
  scanf("%d %d %d %s", &n, &a, &b, s);
  if (a > b) swap(a, b);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') continue;
    int j = i;
    while (j + 1 < n && s[j + 1] == s[j]) j++;
    int len = j - i + 1;
    int sm = len / 2;
    int bg = len - sm;
    
    int del_a = min(sm, a);
    a -= del_a;
    ans += del_a;
    
    int del_b = min(bg, b);
    b -= del_b;
    ans += del_b;
    
    if (a > b) swap(a, b);
    
    i = j;
  }
  cout << ans << endl;
  return 0;
}
