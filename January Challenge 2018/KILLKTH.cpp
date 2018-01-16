#include <bits/stdc++.h>

using namespace std;

inline long long add(long long a, long long b, long long mod) {
  return (a + b) % mod;
}

inline long long mul(long long a, long long b, long long mod) {
  if (b == 0) return 0;
  long long temp = mul(a, b / 2, mod);
  temp = add(temp, temp, mod);
  if (b & 1) {
    temp = add(temp, a, mod);
  }
  return temp;
}

// suffix array
const int N = 2e5 + 5;
string s;
int sa[N], pos[N], lcp[N], tmp[N], gap, n;

bool cmp_sa(int a, int b) {
  if(pos[a] - pos[b])
    return pos[a] < pos[b];
  a += gap; b += gap;
  return (a < n && b < n) ? pos[a] < pos[b] : a > b;
}

void build_sa() {
  n = s.size();
  for(int i = 0; i<n; i++)
    sa[i] = i, pos[i] = s[i];
  for(gap = 1;; gap <<= 1) {
    sort(sa, sa + n, cmp_sa);
    for(int i = 1; i<n; i++) tmp[i] = tmp[i-1] + cmp_sa(sa[i-1], sa[i]);
    for(int i = 0; i<n; i++) pos[sa[i]] = tmp[i];
    if(tmp[n-1] == n-1) break;
  }
}

int main() {
  cin >> s;
  build_sa();
  

  return 0;
}
