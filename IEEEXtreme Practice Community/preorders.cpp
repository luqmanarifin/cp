#include <bits/stdc++.h>
using namespace std;

int a[100];
bool print;

int can(int l, int r, int done) {
  //if (print) printf("%d %d %d\n", l, r, done);
  if (l > r) return done;
  assert(l <= a[done+1] && a[done+1] <= r);
  int mid = (a[done+1]);
  done++;
  if (l <= a[done+1] && a[done+1] < mid) {
    done = can(l, mid-1, done);
  }
  if (mid < a[done+1] && a[done+1] <= r) {
    done = can(mid+1, r, done);
  }
  return done;
}

void allBstPreorders(int n) {
  for (int i = 1; i <= n; i++) a[i] = i;
  do {
    //print = (a[1] == 3 && a[2] == 1 && a[3] == 4 && a[4] == 2);
    if (can(1, n, 0) == n) {
      for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%d", a[i]);
      }
      printf("\n");
    }
  } while (next_permutation(a + 1, a + 1 + n));
}
   
int main() {
  int N;
  cin >> N;
  allBstPreorders(N);
  return 0;
}
