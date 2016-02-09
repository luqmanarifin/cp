#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int n;
int cnt[N];
int ll, rr;

bool is_palindrome() {
  for(int i = 0; i < n; i++) {
    if(a[i] != a[n - 1 - i]) {
      return 0;
    }
  }
  return 1;
}

bool is_sufficient() {
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  int odd = 0;
  for(int i = 0; i < N; i++) {
    if(cnt[i] & 1) odd++;
  }
  return (n % 2? odd == 1 : odd == 0);
}

bool can_shuffle_left(int p) {
  memset(cnt, 0, sizeof(cnt));
  for(int i = ll; i <= p; i++) {
    cnt[a[i]]++;
  }
  for(int i = p + 1; i <= rr; i++) {
    int f = n - 1 - i;
    if(f <= p) {
      if(cnt[a[i]] == 0) return 0;
      cnt[a[i]]--;
    } else {
      if(a[i] != a[f]) return 0;
    }
  }
  return 1;
}

bool can_shuffle_right(int p) {
  memset(cnt, 0, sizeof(cnt));
  for(int i = p; i <= rr; i++) {
    cnt[a[i]]++;
  }
  for(int i = ll; i < p; i++) {
    int f = n - 1 - i;
    if(p <= f) {
      if(cnt[a[i]] == 0) return 0;
      cnt[a[i]]--;
    } else {
      if(a[i] != a[f]) return 0;
    }
  }
  return 1;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  if(is_palindrome()) {
    cout << 1LL * n * (n + 1) / 2 << endl;
    return 0;
  }
  if(!is_sufficient()) {
    cout << 0 << endl;
    return 0;
  }
  while(a[ll] == a[n - 1 - ll]) {
    ll++;
  }
  rr = n - 1 - ll;
  
  int l = ll, r = rr;
  while(l < r) {
    int mid = (l + r) >> 1;
    if(!can_shuffle_left(mid)) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  int bin_lef = l;
  
  l = ll, r = rr;
  while(l < r) {
    int mid = (l + r + 1) >> 1;
    if(!can_shuffle_right(mid)) {
      r = mid - 1;
    } else {
      l = mid;
    }
  }
  int bin_rig = l;
  
  //printf("%d %d %d %d\n", ll, rr, bin_lef, bin_rig);
  
  long long ans = -1LL * (ll + 1) * (ll + 1);
  ans += 1LL * (ll + 1) * (n - bin_lef);
  ans += 1LL * (ll + 1) * (bin_rig + 1);
  cout << ans << endl;
  return 0;
}
