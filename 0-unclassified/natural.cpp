#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int main() {
  scanf("%s", s);
  int a = 0, b = 0;
  int n = strlen(s);
  for(int i = 0; i < n; i++) {
    if(s[i] == '0') a++;
    else b++;
  }
  if(a > b) swap(a, b);
  if(a > 0 && b > 0) {
    puts("YES");
  } else {
    puts(b % 2 == 0? "NO" : "YES");
  }
  
  return 0;
}
