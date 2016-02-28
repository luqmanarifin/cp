#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5;
const int POL = 1e6 + 5;
const int SIZE = 173;

int a[N];
int cnt[POL], val[POL];
int ans;

void add(int v) {
  cnt[v]++;
  if(cnt[v] == 1) ans++;
}

void remove(int v) {
  cnt[v]--;
  if(cnt[v] == 0) ans--;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d",  a + i);
  }
  int q;
  scanf("%d", &q);
  vector<tuple<int, int, int, int>> num;
  for(int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--; r--;
    num.emplace_back(l / SIZE, r, l, i);
  }
  sort(num.begin(), num.end());
  int l = 0, r = 0;
  add(a[0]);
  for(int i = 0; i < q; i++) {
    int ll = get<2>(num[i]);
    int rr = get<1>(num[i]);
    int id = get<3>(num[i]);
    //printf("lala %d %d\n", ll, rr);
    while(r < rr) add(a[++r]);
    while(rr < r) remove(a[r--]);
    while(l < ll) remove(a[l++]);
    while(ll < l) add(a[--l]);
    val[id] = ans;
  }
  for(int i = 0; i < q; i++) printf("%d\n", val[i]);
  return 0;
}