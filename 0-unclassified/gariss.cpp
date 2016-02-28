#include <bits/stdc++.h>

using namespace std;

void generate(int sum) {
  while(sum) {
    int now = min(9, sum);
    printf("%d", now);
    sum -= now;
  }
}

int main() {
  long long n;
  cin >> n;
  for(int i = 1; i <= 162; i++) {
    for(int j = 1; j <= 162; j++) {
      if(i * j == n) {
        generate(i);
        printf(" ");
        generate(j);
        printf("\n");
        return 0;
      }
    }
  }
  puts("-1 -1");
  return 0;
}
