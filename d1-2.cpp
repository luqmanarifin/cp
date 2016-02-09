// file: d1-2.cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, p[N];
char s[N];

int main() {
  scanf("%d", &n);
  scanf("%s", s);
  n--;
  int front, back;
  front = back = 1;
  for(int i = 0; i<n; i++) {
    if(s[i] == 'A') {
      if(i&1) {
        p[back] = i+2;
        back = i+2;
      }
      else {
        p[i+2] = front;
        front = i+2;
      }
    }
    else {
      if(i&1) {
        p[i+2] = front;
        front = i+2;
      }
      else {
        p[back] = i+2;
        back = i+2;
      }
    }
  }
  int now = front;
  for(int i = 0; i<=n; i++) {
    printf("%d ", now);
    now = p[now];
  }
  printf("\n");
  return 0;
}
