#include <bits/stdc++.h>

/**
 * Competitive Programming Final CP Mahasiswa
 * Problem : C | Amar dan Kina
 * Gajah Wangi (ITB)
 **/

typedef long long LL;
typedef double db;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")
#define FOR(i, a, b) for(i = a; i <= b; i++)
#define FORD(i, a, b) for(i = a; i >= b; i--)
#define FORS(i, n) for(i = 0; i < n; i++)
#define FORM(i, n) for(i = n - 1; i >= 0; i--)
#define reset(i, n) memset(i, n, sizeof(i))
#define open freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

map<int,int> cnt;
int num[int(1e6 + 5)];

int main() {
  int t, i, j;
  sf("%d", &t);
  while(t--) {
    int n, k;
    cnt.clear();
    reset(num, 0);
    sf("%d %d", &n, &k);
    FORS(i, n) {
      sf("%d", num + i);
    }
    FORS(i, k) cnt[num[i]]++;
    int now = 0;
    
    vector<int> awal;
    FORS(i, k) awal.push_back(num[i]);
    sort(awal.begin(), awal.end());
    FORS(i, k) {
      if(i && awal[i] == awal[i-1]) continue;
      if(awal[i] == cnt[awal[i]]) now++;
    }
    
    LL ans = now;
    FOR(i, k, n-1) {
      int bef = --cnt[num[i-k]];
      if(bef == num[i-k]) now++;
      else if(bef + 1 == num[i-k]) now--;
      
      bef = ++cnt[num[i]];
      if(bef == num[i]) now++;
      else if(bef - 1 == num[i]) now--;
      
      ans += now;
    }
    pf("%lld\n", ans);
  }
    
  return 0;
}