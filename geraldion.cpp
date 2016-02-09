#include <bits/stdc++.h>

using namespace std;

int cuk[(int) 1e6 + 5];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", cuk + i);
  }
  sort(cuk, cuk + n);
  puts(cuk[0] == 1? "-1" : "1");
  return 0;
}
