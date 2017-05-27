#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int magic = 1600;

#define bit unsigned long long

int n;

struct nim {
  nim() {
    a = new bit[magic];
    memset(a, 0, sizeof(a));
  }
  nim operator=(const nim& other) {
    nim ret;
    for (int i = 0; i < magic; i++) a[i] = other.a[i];
    return ret;
  }
  void update(int from, int to) {
    int l = n - to;
    int r = n - from;
    for (int i = 0; i < magic; i++) {
      if (l / 64 == r / 64) {
        l %= 64;
        r %= 64;
        a[i] ^= ((1ULL<<(r+1))-1) ^ ((1ULL<<l)-1);
      } else {
        int at = l % 64;
        a[i] ^= (-1ULL ^ ((1LL<<at)-1));
        l = (i + 1) * 64;
      }
    }
  }
  bool operator<(const nim& other) const {
    for (int i = magic - 1; i >= 0; i--) {
      if (a[i] < other.a[i]) {
        return 1;
      }
      if (a[i] > other.a[i]) {
        return 0;
      }
    }
    return 0;
  }
  bit* a;
};

int main() {
  int q;
  scanf("%d %d", &n, &q);
  nim ans;
  nim now;
  for (int qq = 0; qq < q; qq++) {
    int l, r;
    scanf("%d %d", &l, &r);
    now.update(l, r);
    if (ans < now) {
      //printf("better %d\n", qq);
      for (int i = 0; i < magic; i++) {
        ans.a[i] = now.a[i];
      }
    }
    /*
    for (int i = n - 1; i >= 0; i--) {
      int num = i / 64;
      int at = i % 64;
      if (now.a[num] & (1LL << at)) {
        printf("1");
      } else {
        printf("0");
      }
    }
    printf("\n");
    */
  }
  for (int i = n - 1; i >= 0; i--) {
    int num = i / 64;
    int at = i % 64;
    if (ans.a[num] & (1LL << at)) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");
  return 0;
}
