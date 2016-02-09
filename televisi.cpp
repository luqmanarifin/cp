#include <bits/stdc++.h>

using namespace std;

char s[55];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%s %d", s, &n);
    if(s[0] == 'n') n--;
    else n++;
    printf("%d\n", (n + 100) % 100);
  }
  
  return 0;
}
