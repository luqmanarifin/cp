#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5;
const int POL = (1 << 21) + 24;

bitset<N> is;
int ans[POL];

void init() {
  for(int i = 2; i < N; i++) {
    for(long long j = 1LL * i * i; j < N; j += i) {
      is[j] = 1;
    }
  }
}

bool palin(int a) {
  int len = (__builtin_clz(a) ^ 31) + 1;
  for(int i = 0; i < len; i++) {
    int j = len - 1 - i;
    if(((a & (1 << i)) >> i) != ((a & (1 << j)) >> j)) {
      return 0;
    }
  }
  return 1;
}

void print(int a) {
  int n = __builtin_clz(a) ^ 31;
  for(int i = n; i >= 0; i--) {
    printf("%d", (a & (1 << i)? 1 : 0));
  }
  printf("\n");
}

int main() {
  init();
  //puts("done init");
  for(int i = 0; i < POL; ) {
    int now = max(2, i);
    while(is[now] || !palin(now)) now++;
    //printf("%d now %d\n", i, now);
    for(; i <= min(POL, now); i++) {
      ans[i] = now;
    }
  }
  //for(int i = 0; i < 10; i++) printf("%d : %d\n", i, ans[i]);
  ios_base::sync_with_stdio(false);
  string buf;
  while(cin >> buf) {
    int n = 0;
    for(int i = 0; i < buf.length(); i++) {
      n = n * 2 + buf[i] - '0';
    }
    print(ans[n]);
  }
  return 0;
}
