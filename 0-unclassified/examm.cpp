#include <bits/stdc++.h>

using namespace std;

int a[5005];

int main() {
  int n;
  scanf("%d", &n);
  if(n == 1) {
    puts("1");
    puts("1");
  } else if(n == 2) {
    puts("1");
    puts("1");
  } else if(n == 3) {
    puts("2");
    puts("1 3");
  } else {
    int id = 0;
    for(int i = 1; i < n; i += 2) {
      a[i] = ++id;
    }
    for(int i = 0; i < n; i += 2) {
      a[i] = ++id;
    }
    cout << n << endl;
    for(int i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }
    
  }
  
  return 0;
}
