#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

vector<int> a, num, push;

void build(int p, int l, int r) {
  push[p] = -1;
  if(l == r) {
    num[p] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
}

void relax(int p, int l, int r) {
  if(push[p] != -1) {
    if(l == r) {
      num[p] = push[p];
    } else {
      push[p + p] = push[p];
      push[p + p + 1] = push[p];
    }
    //printf("push %d %d\n", l, r);
    push[p] = -1;
  }
}

void update(int p, int l, int r, int ll, int rr, int val) {
  relax(p, l, r);
  if(r < ll || rr < l) return;
  //printf("%d %d %d %d\n", l, r, ll, rr);
  if(ll <= l && r <= rr) {
    push[p] = val;
    relax(p, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  update(p + p, l, mid, ll, rr, val);
  update(p + p + 1, mid + 1, r, ll, rr, val);
}

int get(int p, int l, int r, int at) {
  //printf("%d %d\n",l , r);
  relax(p, l, r);
  if(l == r) {
    //printf("di %d %d\n", l, num[p]);
    return num[p];
  }
  int mid = (l + r) >> 1;
  if(at <= mid) {
    return get(p + p, l, mid, at);
  } else {
    return get(p + p + 1, mid + 1, r, at);
  }
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  a.resize(n);
  num.assign(n << 2, -1);
  push.assign(n << 2, -1);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  build(1, 0, n - 1);
  for(int i = 0; i < n; i++) {
    get(1, 0, n - 1, i);
  }
  printf("\n");
  while(q--) {
    int i, val, l, r;
    scanf("%d %d %d %d", &l, &r, &val, &i);
    update(1, 0, n - 1, l, r, val);
    printf("%d\n", get(1, 0, n - 1, i));
  }
  return 0;
}
