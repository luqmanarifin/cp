#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int a[30];

int main() {
  int mini = inf, p;
  int s = inf;
  for(int i = 0; i < 26; i++) {
    scanf("%d", a + i);
    if(a[i] && a[i] < mini) {
      mini = a[i];
      p = i;
      s = min(s, i);
    }
  }
  if(p == s) {
    int del = min(2, a[p]);
    for(int i = 0; i < del; i++) printf("%c", p + 'a');
    int rem = a[p] - del;
    for(int i = p + 1; i < 26; i++) {
      for(int j = 0; j < a[i]; j++) {
        printf("%c", i + 'a');
        if(rem) {
          printf("%c", p + 'a');
          rem--;
        }
      }
    }
    while(rem) {
      printf("%c", p + 'a');
      rem--;
    }
  } else {
    printf("%c", p + 'a');
    for(int i = 0; i < 26; i++) {
      for(int j = 0; j < a[i] - (i == p); j++) {
        printf("%c", i + 'a');
      }
    }
  }
  return 0;
}