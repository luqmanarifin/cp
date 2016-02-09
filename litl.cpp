#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

int a[N];
int s[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    s[i] = a[i];
  }
  sort(s, s + n);
  int dif = 0;
  for(int i = 0; i < n; i++) {
    dif += s[i] != a[i];
  }
  puts(dif <= 2? "YES" : "NO");
  return 0;
}