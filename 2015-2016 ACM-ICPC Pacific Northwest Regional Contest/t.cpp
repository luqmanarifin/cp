#include <bits/stdc++.h>

using namespace std;

int a[3], b[3];

int main() {
  for(int i = 0; i < 3; i++) scanf("%d", a + i);
  for(int i = 0; i < 3; i++) scanf("%d", b + i);
  sort(a, a + 3);
  sort(b, b + 3);
  for(int i = 0; i < 3; i++) if(a[i] != b[i]) {
    puts("NO");
    return 0;
  }
  if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2]) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}