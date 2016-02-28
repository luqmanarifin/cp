#include <bits/stdc++.h>

using namespace std;

long long mod[] = {(long long)1e9 + 7, (long long)1e9 + 13, (long long)1e9 + 2013};
long long prime[] = {2, 7, 61};
const int N = 1e6 + 5;

char s[N];
long long ini[N][3];
long long power[N][3];
vector<pair<long long, int>> dua[3];

// -1 if not present
int get(long long num, int j) {
  int id = lower_bound(dua[j].begin(), dua[j].end(), make_pair(num, -1)) - dua[j].begin();
  return (dua[j][id].first == num? dua[j][id].second : -1);
}

int main() {
  for(int j = 0; j < 3; j++) {
    power[0][j] = 1;
    dua[j].emplace_back(power[0][j], 0);
  }
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < 3; j++) {
      power[i][j] = power[i - 1][j] * prime[j];
      power[i][j] %= mod[j];
      dua[j].emplace_back(power[i][j], i);
    }
  }
  for(int j = 0; j < 3; j++) {
    sort(dua[j].begin(), dua[j].end());
  }
  
  int n;
  scanf("%d %s", &n, s + 1);
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 3; j++) {
      ini[i][j] = ini[i - 1][j] * prime[j] + (s[i] == 'b');
      ini[i][j] %= mod[j];
    }
  }
  
  int q;
  scanf("%d", &q);
  while(q--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(b - a + 1 != d - c + 1) {
      puts("DIFFERENT");
      continue;
    }
    bool same = 1;
    vector<pair<long long, long long>> res;
    for(int j = 0; j < 3; j++) {
      long long lef = ini[b][j] - ini[a - 1][j] * power[b - a + 1][j];
      long long rig = ini[d][j] - ini[c - 1][j] * power[d - c + 1][j];
      lef %= mod[j]; if(lef < 0) lef += mod[j];
      rig %= mod[j]; if(rig < 0) rig += mod[j];
      if(lef != rig) same = 0;
      //cerr << lef << ' ' << rig << endl;
      res.emplace_back(lef, rig);
    }
    if(same) {
      puts("SIMILAR");
      continue;
    }
    bool similar = 0;
    for(int it = 0; it < 2; it++) {
      same = 1;
      int bef = 0;
      for(int j = 0; j < 3; j++) {
        long long dif = res[j].first - res[j].second;
        int now = get(dif < 0? dif + mod[j] : dif, j);
        if(now == -1) {
          same = 0;
        }
        if(j && now != bef) {
          same = 0;
        }
        swap(res[j].first, res[j].second);
        bef = now;
      }
      if(same && bef <= b - a) similar = 1;
    }
    puts(similar? "SIMILAR" : "DIFFERENT");
  }
  
  return 0;
}
