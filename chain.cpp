#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    int n = strlen(s);
    int a = 0, b = 0;
    for(int i = 0; i < n; i++) {
      if(i & 1) {
        if(s[i] == '-') a++;
        else b++;
      } else {
        if(s[i] == '+') a++;
        else b++;
      }
    }
    printf("%d\n", min(a, b));
  }
  
  return 0;
}