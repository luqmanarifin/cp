#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 1e5;
LL ar[N + 5];

LL n, a, d;
int m;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> a >> d;
  for(int i = 0; i < m; ++i) cin >> ar[i];
  LL poi_n = 0;
  LL buka = 0;
  LL bisa = min((d / a) + 1, n);
  for(int i = 0;i < m;){
    LL batas = ar[i];
    if(poi_n != n) {
      LL poi_n_before = poi_n;
      LL last_poi_n_now = min((ar[i] - 1) / a, n);
      LL sisa = last_poi_n_now - poi_n;
      LL banyak = sisa / bisa;
      buka += banyak;
      poi_n += banyak * bisa;
      if(poi_n != last_poi_n_now && poi_n_before != poi_n){
        poi_n++;
        batas = poi_n * a;
      }
      else if(bisa == 1 && poi_n * a + d >= ar[i] && poi_n_before != poi_n){
        batas = poi_n * a;
        buka--;
      }
    }
    //printf("MASUK %d %lld %lld\n", i, batas, poi_n);
    buka++;
    while(i < m && ar[i] <= batas + d){
      i++;
    }
    poi_n = min(n, (batas + d) / a);
  }
  //printf("DEBUG %lld %lld %lld\n", bisa, buka, poi_n);
  if(poi_n != n){
    buka += (n - poi_n + bisa - 1) / bisa;
  }
  
  cout << buka << endl;
  return 0;
}
