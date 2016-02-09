#include <bits/stdc++.h>

using namespace std;

int a[6];

int main() {
  for(int i = 0; i < 6; i++) {
    scanf("%d", a + i);
  }
  cout << (a[0] + a[1] + a[2])*(a[0] + a[1] + a[2]) - a[0]*a[0] - a[2]*a[2] - a[4]*a[4] << endl;
  return 0;
}
