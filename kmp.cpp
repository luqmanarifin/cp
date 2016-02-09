#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for(int i = 1; i < n; i++) {
    int j = a[i - 1];
    while(j && s[i] != s[j]) j = a[j - 1];
    //printf("%d %d\n", i, j);
    if(s[i] == s[j]) {
      a[i] = j + 1;
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
