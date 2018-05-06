
#include <bits/stdc++.h>

using namespace std;

string s = "What are you doing at the end of the world? Are you busy? Will you save us?";

string beg = "What are you doing while sending \"";
string mid = "\"? Are you busy? Will you send \"";
string last = "\"?";

const long long inf = 2e18;
const int N = 1e5 + 5;

long long len[N];

char solve(int n, long long k) {
  if (len[n] <= k) return '.';
  if (n == 0) return s[k];
  if (k < beg.size()) return beg[k];
  k -= beg.size();
  if (k < len[n - 1]) return solve(n - 1, k);
  k -= len[n - 1];
  if (k < mid.size()) return mid[k];
  k -= mid.size();
  if (k < len[n - 1]) return solve(n - 1, k);
  k -= len[n - 1];
  if (k < last.size()) return last[k];
  return '.';
}

int main() {
  len[0] = s.size();
  for (int i = 1; i < N; i++) {
    len[i] = min(inf, 2 * len[i - 1] + beg.size() + mid.size() + last.size());
    if (i <= 60) printf("%d %lld\n", i, len[i]);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    long long k;
    scanf("%d %I64d", &n, &k);
    printf("%c", solve(n, k - 1));
  }
  return 0;
}
