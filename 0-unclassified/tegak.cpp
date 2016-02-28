#include <bits/stdc++.h>

using namespace std;

const int N = 5;

int a[N], b[N];

int main() {
  for(int i = 0; i < 3; i++) {
    scanf("%d %d", a + i, b + i);
  }
  int dya = b[1] - b[0];
  int dxa = a[1] - a[0];
  int dyb = b[2] - b[0];
  int dxb = a[2] - a[0];
  if(dxb * dya == dyb * dxa) {
    puts("-1");
  } else {
    bool ada = 0;
    for(int i = 0; i < 3; i++) {
      for(int j = i + 1; j < 3; j++) {
        if(a[i] == a[j]) {
          ada = 1;
        }
      }
    }
    if(ada) {
      puts("1");
    } else {
      puts("0");
    }
  }
  return 0;
}
