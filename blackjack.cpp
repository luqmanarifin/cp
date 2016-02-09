#include <bits/stdc++.h>

using namespace std;

int cnt[15];

int main() {
  for(int i = 1; i <= 11; i++) {
    cnt[i] += 4;
  }
  for(int i = 0; i < 3; i++) {
    cnt[10] += 4;
  }
  cnt[10]--;
  int n;
  scanf("%d", &n);
  cout << (n - 10 >= 0? cnt[n - 10] : 0) << endl;
  
  return 0;
}
