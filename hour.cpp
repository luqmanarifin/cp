#include <bits/stdc++.h>

using namespace std;

void print(int mask) {
  for(int i = 0; i < 20; i++) {
    if(mask & (1 << i)) printf("1");
    else printf("0");
  }
  printf(" ");
}

int find(int mask) {
  int ret = 0;
  for(int i = 0; i < 20; i++) {
    if(mask & (1 << i)) {
      ret++;
      while(mask & (1 << (i + 1))) {
        i++;
      }
    }
  }
  print(mask); printf("%d\n", ret);
  return ret;
}

int f[20];

int main() {
  for(int i = 0; i < (1 << 20); i++) {
    f[find(i)]++;
  }
  int sum = 0;
  for(int i = 0; i < 20; i++) {
    sum += f[i];
    cout << f[i] << endl;
  }
  assert(sum == (1 << 20));
  return 0;
}
