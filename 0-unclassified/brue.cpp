#include <bits/stdc++.h>

using namespace std;

long long digit(long long num) {
  long long ret = 0;
  while(num) {
    ret += num % 10;
    num /= 10;
  }
  if(ret < 10) return ret;
  return digit(ret);
}

int main() {
  int a = 1;
  for(int d = 1; d <= 50; d++) {
    int now = a;
    printf("%d : ", d);
    for(int i = 0; i < 35; i++) {
      printf("%I64d ", digit(now) - 1);
      now += d;
    }
    printf("\n");
  }
  return 0;
}
