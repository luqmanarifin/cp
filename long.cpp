#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char a[N], b[N];

int main() {
  scanf("%s %s", a, b);
  int na = strlen(a);
  int nb = strlen(b);
  int i = 0, j = 0;
  while(i < na && a[i] == '0') i++;
  while(j < nb && b[j] == '0') j++;
  int la = na - i;
  int lb = nb - j;
  if(la > lb) {
    puts(">");
  } else if(la < lb) {
    puts("<");
  } else {
    for(int k = 0; k < la; k++) {
      if(a[i + k] != b[j + k]) {
        puts(a[i + k] < b[j + k]? "<" : ">");
        return 0;
      }
    }
    puts("=");
  }
  return 0;
}
