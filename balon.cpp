#include <bits/stdc++.h>

using namespace std;

char s[105];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    int n = strlen(s);
    int a = 0;
    for(int i = 0; i < n; i++) if(s[i] == 'a') a++;
    printf("%d\n", min(a, n - a));
  }
  return 0;
}
