
#include <bits/stdc++.h>

#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const int N = 11e6;

bool is[N];
int sm[N];

int main() {
  open;
  is[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      for (long long j = i; j < N; j += i) {
        is[j] = 1;
        if (sm[j] == 0) sm[j] = i;
      }
    }
  }
  
  int n;
  scanf("%d", &n);
  vector<int> a;
  set<int> s;
  while (n > 1) {
    a.push_back(sm[n]);
    s.insert(sm[n]);
    n /= sm[n];
  }
  if (a.size() == s.size() && a.size() == 3) {
    puts("YES");
  } else {
    puts("NO");
  }
  close;
  return 0;
}
