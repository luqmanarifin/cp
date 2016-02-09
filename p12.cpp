#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int l[N], r[N], n;

void count(int* arr) {
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    arr[a]++;
  }
}

int main() {
  scanf("%d", &n);
  count(l);
  count(r);
  int good = 0;
  for(int i = 1; i <= 1000; i++) {
    good += min(l[i], r[i]);
  }
  cout << n - good << endl;
  return 0;
}
