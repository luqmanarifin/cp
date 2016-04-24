#include <bits/stdc++.h>

using namespace std;

int a[256];

int main() {
  for(int i = 0; i < 256; i++) {
    a[i] = i;
  }
  srand(time(NULL));
  for(int i = 0; i < 128; i++) {
    int r1 = rand() % 128;
    int r2 = rand() % 128;
    swap(a[i], a[r1]);
    swap(a[i + 128], a[r2 + 128]);
  }
  for(int i = 0; i < 256; i++) printf("%d,", a[i]);
  
  return 0;
}