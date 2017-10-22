#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> pic;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
int n;
string s;
int cnt[1 << 8];
vector<int> factor;
inline void prefactor(){
  int akar = sqrt(n);
  for(int i = 1; i <= akar; ++i){
    if(n % i == 0){
      factor.push_back(i);
      if(i * i != n) factor.push_back(n / i);
    }
  }
  sort(factor.begin(), factor.end());
  reverse(factor.begin(), factor.end());
}

vector<pic> v;

bool CF(const pic &a, const pic &b){
  if(a.fi == 0) return true;
  if(b.fi == 0) return false;
  int ganjila = a.fi & 1;
  int ganjilb = b.fi & 1;
  if(ganjila != ganjilb){
    return ganjila > ganjilb;
  }
  else{
    return a.fi < b.fi;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin >> n >> s;
  prefactor();
  int cnt1 = 0;
  for(int i = 0;i < s.size(); ++i) {
    cnt[s[i]]++;
  }  
  for(int i = 'A'; i <= 'Z'; ++i) {
    cnt1 += (cnt[i] & 1);
    if(cnt[i]) v.pb(mp(cnt[i], i));
  }
  for(int i = 'a'; i <= 'z'; ++i) {
    cnt1 += (cnt[i] & 1);
    if(cnt[i]) v.pb(mp(cnt[i], i));
  }
  for(int i = '0'; i <= '9'; ++i) {
    cnt1 += (cnt[i] & 1);
    if(cnt[i]) v.pb(mp(cnt[i], i));
  }
  sort(v.begin(), v.end(), CF);
  if(!cnt1){
    string s = "", ss = "";
    for(int i = 0;i < v.size(); ++i){
      for(int j = 0;j < v[i].fi; j += 2){
        s += v[i].se;
        ss += v[i].se;
      }
    }
    reverse(ss.begin(), ss.end());
    s += ss;
    cout << 1 << endl;
    cout << s << endl;
    return 0;
  }
 
  for(int i = 0;i < (int) factor.size() - 1; ++i){
    int u = factor[i];
    if(!(factor[i] & 1)) continue;
    vector<pic> vnow = v;
    vector<string> vs;
    int lastnotone = 0;
    bool bisa = true;
    for(int j = 0;j < (int) vnow.size() && bisa; ++j){
      /* DEBUG */
      //cerr << "J : " << j << ": ";
      //for(int k = 0;k < vnow.size(); ++k) cerr << "(" << vnow[k].fi << "," << vnow[k].se << "),";
      if(vnow[j].fi == 0) continue;
      lastnotone = j;
      while(lastnotone < (int) vnow.size() && vnow[lastnotone].fi <= 1) lastnotone++;
      if(lastnotone == (int) vnow.size()){
        bisa = false;
        continue;
      }
      string tengah = "";
      tengah += vnow[j].se;
      string depan = "";
      vnow[j].fi--;
      int sisa = u - 1;
      while(sisa > 0 && lastnotone < (int) vnow.size()){
        int banyakchar = vnow[lastnotone].fi >> 1;
        if(banyakchar == 0) {
          lastnotone++;
          continue;
        }
        banyakchar = min(sisa, banyakchar << 1);
        vnow[lastnotone].fi -= banyakchar;
        sisa -= banyakchar;
        banyakchar >>= 1;
        while(banyakchar > 0){
          depan += vnow[lastnotone].se;
          banyakchar--;
        }
      }
      if(sisa > 0) bisa = false;
      else{
        sort(vnow.begin(), vnow.end(), CF);
        string belakang = depan;
        reverse(belakang.begin(), belakang.end());
        vs.push_back(depan + tengah + belakang);
      }
    }
    for(int j = 0;j < (int) vnow.size() && bisa; ++j) bisa &= (vnow[j].fi == 0); 
    if(bisa){
      cout << n / u << endl;
      for(int j = 0;j < vs.size(); ++j){
        cout << vs[j] << ((j == vs.size() - 1) ? '\n' : ' ');
      }
      return 0;
    }
  }
  cout << n << endl;
  for(int j = 0; j < s.size(); ++j){
    cout << s[j] << ((j == s.size() - 1) ? '\n' : ' ');
  }
  return 0;
}