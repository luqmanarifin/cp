#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n;

void print() {
  for(int i = 0; i < n; i++) {
    if(i) printf("->");
    if(i == n - 3) printf("(");
    printf("%d", a[i]);
    if(i == n - 2) printf(")");
  }
  printf("\n");
}

void khusus(int nol) {
  for(int i = 0; i < n; i++) {
    if(i) printf("->");
    if(i == nol) printf("(");
    if(i == nol + 1) printf("(");
    printf("%d", a[i]);
    if(i == n - 2) printf("))");
  }
  printf("\n");
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  if(n == 1) {
    if(a[0] == 0) {
      puts("YES");
      puts("0");
    } else {
      puts("NO");
    }
    return 0;
  }
  
  if(n == 2) {
    if(a[0] == 1 && a[1] == 0) {
      puts("YES");
      puts("1->0");
    } else {
      puts("NO");
    }
    return 0;
  }
  
  if(a[n - 1] == 1) {
    puts("NO");
  } else {
    if(a[n - 3] == 0 && a[n - 2] == 0 && a[n - 1] == 0) {
      puts("YES");
      print();
    } else if(a[n - 3] == 0 && a[n - 2] == 1 && a[n - 1] == 0) {
      puts("YES");
      print();
    } else if(a[n - 3] == 1 && a[n - 2] == 1 && a[n - 1] == 0) {
      puts("YES");
      print();
    } else {
      int nol = -1;
      for(int i = n - 4; i >= 0; i--) {
        if(a[i] == 0) {
          nol = i;
          break;
        }
      }
      if(nol == -1) {
        puts("NO");
        return 0;
      }
      //assert(a[n - 3] == 1 && a[n - 2] == 0 && a[n - 1] == 0);
      puts("YES");
      khusus(nol);
    }
  }
  
  return 0;
}
