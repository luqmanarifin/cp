#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

char s[N], c[N];
long long id[N];
int hidup[N];

void process(vector<long long> & del,vector<pair<long long, char> > &add) {
  int q = 0;
  for (q = 0; ; ++q) {
    hidup[q] = 1;
    scanf(" %c", s+q);
    if (s[q] == 'E') break;
    scanf("%lld", id+q);
    if (s[q] == 'D') {
      long long rem = id[q];
      int found = -1;
      for (int i = 0; i < q; ++i) {
        if (!hidup[i]) continue;
        if (s[i] != 'I') continue;
        if (id[i] == id[q])
          found = i;
        else if (id[i] < id[q])
          --rem;
        else
          --id[i];
      }
      if (found != -1) {
        hidup[q] = 0;
        hidup[found] = 0;
      }
      else {
        // assert(rem > 0);
        long long le = 0, ri = rem + q + rem * 2;
        while (le < ri) {
          long long mid = (le + ri) / 2;
          long long cur = mid;
          for (int i = 0; i < q; ++i) {
            if (!hidup[i]) continue;
            if (s[i] != 'D') continue;
            if (id[i] <= mid)
              --cur;
          }
          if (cur < rem)
            le = mid+1;
          else
            ri = mid;
        }
        // assert(le > 0);
        id[q] = le;
      }
    }
    else if (s[q] == 'I') {
      scanf(" %c", c+q);
      for (int i = 0; i < q; ++i) {
        if (!hidup[i]) continue;
        if (s[i] != 'I') continue;
        if (id[i] >= id[q]) {
          ++id[i];
        }
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    if (!hidup[i]) continue;
    if (s[i] == 'I')
      add.emplace_back(id[i], c[i]);
    else if (s[i] == 'D')
      del.push_back(id[i]);
  }
  sort(add.begin(), add.end());
  sort(del.begin(), del.end());
}

int main() {
  vector<long long> rem1, rem2;
  vector<pair<long long, char> > add1, add2;
  process(rem1, add1);
  process(rem2, add2);
  puts((rem1 == rem2 && add1 == add2) ? "0" : "1");
  return 0;
}
