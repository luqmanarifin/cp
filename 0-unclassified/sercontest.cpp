#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
  } 
  int num = 0;
  long long nn = n;
  long long now = 0;
  for(int i = 0; i < n; i++) {
    long long di = now - (nn - (num + 1)) * a[i] * num;
    //cout << "di " << di << endl;
    if(di < k) {
      printf("%d\n", i + 1);
      nn--;
    } else {
      num++;
      now += a[i] * (num - 1);
    }
  }
  
  return 0;
}
