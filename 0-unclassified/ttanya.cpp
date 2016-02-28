#include <bits/stdc++.h>

using namespace std;

const int N = 1205;
const int init = 1001;

int ans[N], idx;
int goal, n;

bool find(int l, int r) {
  if(l > r) return 0;
  int mid = (l + r) >> 1, ret;
  printf("ask");
  for(int i = 0; i < n; i++) {
    if(i == idx) printf(" %d", mid);
    else printf(" %d", ans[i]);
  }
  printf("\n");
  fflush(stdout);
  scanf("%d", &ret);
  if(ret == goal) {
    if(!find(mid + 1, r)) ans[idx] = mid;
    return 1;
  } else {
    return find(l, mid - 1);
  }
}

int main() {
  printf("init\n");
  fflush(stdout);
  scanf("%d", &n);
  for(int i = 0; i < N; i++) {
    ans[i] = init;
  }
  for(int i = 0; i < n; i++) {
    idx = i;
    goal = n - i - 1;
    find(1, 1000);
  }
  printf("answer");
  for(int i = 0; i < n; i++) {
    printf(" %d", ans[i]);
  }
  printf("\n");
  fflush(stdout);
  return 0;
}