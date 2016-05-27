#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n, k;

void print() {
  for(int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
      a[i] = i;
    }
    if(k == 0) {
      print();
      continue;
    }
    if(n % (2 * k)) {
      puts("-1");
      continue;
    }
    for(int i = 1; i <= n; i++) {
      int at = (i - 1) / k;
      if(at % 2 == 0) {
        swap(a[i], a[i + k]);
      }
    }
    print();
  }
  
  return 0;
}