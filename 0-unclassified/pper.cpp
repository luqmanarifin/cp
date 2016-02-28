#include <bits/stdc++.h>

/**
 * biar terluka
 * biar tersiksa
 * aku cuma bisa
 * mencintaimu..
 *
 * Bandung, 7 Februari 2014
 */

using namespace std;

int n;
long long m;
bool done[55];

int main() {
  scanf("%d %I64d", &n, &m);
  m--;
  int start = 1;
  for(int i = n - 2; i >= 0; i--, start++) {
    int bit = 0;
    for(int j = i; j >= 0; j--) {
      if(m & (1LL << j)) bit++;
      else break;
    }
    start += bit;
    //printf("bit %d\n", bit);
    printf("%d ", start);
    done[start] = 1;
    i -= bit;
  }
  for(int i = n; i >= 1; i--) {
    if(!done[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}