#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

bool is[N];
int p[N];
int rub[N];

bool palin(int a) {
  vector<int> num;
  while(a > 0) {
    num.push_back(a % 10);
    a /= 10;
  }
  for(int i = 0; i < num.size(); ++i) {
    if(num[i] != num[num.size() - 1 - i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  for(int i = 1; i < N; i++) {
    p[i] = p[i - 1] + (!is[i] && i != 1? 1 : 0);
    rub[i] = rub[i - 1] + palin(i);
    if(!is[i] && i != 1) {
      //printf("%d\n", i);
      for(long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
    //printf("%.15f\n", 1. * p[i] / rub[i]);
  }
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = N - 1; i >= 1; i--) {
    if(1LL * p[i] * q <= 1LL * n * rub[i]) {
      printf("%d\n", i);
      return 0;
    }
  }
  assert(false);
  return 0;
}
