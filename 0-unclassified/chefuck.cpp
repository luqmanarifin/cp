#include <bits/stdc++.h>

using namespace std;

const long long pol = 1e7 + 5;
const long long mod = 1e9 + 7;

long long num[pol];
int block[420000][32];
int sblock[pol];
int lookup[16800000];
int N;
int lg;
int size; // size

inline int mini(int a,int b){
  return num[b]<num[a]?b:a;
}

void range_minimum_query(int n){
  N=n;
  lg=32-__builtin_clz(N);
  size=(N+lg-1)/lg;
  
  for(int i=0;i<N;i++){
    int& kam = block[i/lg][0];
    if(i%lg==0)
      kam=i;
    kam=mini(i,kam);
  }
  for(int j = 1; j < lg; j++) {
    int tmp = (1 << (j - 1));
    for(int i = 0; i < size; i++) {
      int& kam = block[i][j];
      kam = block[i][j - 1];
      if(i + tmp < size && num[block[i + tmp][j - 1]] < num[kam]) {
        kam = block[i + tmp][j - 1];
      }
    }
  }
  
  std::vector<int> st;
  for(int i=0;i<size;i++){
    st.clear();
    for(int j=i*lg;j<N&&j<i*lg+lg;j++){
      while(!st.empty()&&num[j]<num[st.back()])
        st.pop_back();
      sblock[j]=1<<(i*lg+lg-j-1);
      if(!st.empty())
        sblock[j]|=sblock[st.back()];
      st.push_back(j);
    }
  }
  
  for(int i=1,ans=lg-1;i<(1<<lg);i++){
    if(1<<(lg-ans)<=i)
      ans--;
    lookup[i]=ans;
  }
}

int l1, r1, ans, t, llg, rrg;

inline int query(int l,int r){
  l1=l/lg+1;
  r1=r/lg-1;
  ans=l;
  if(l1<=r1){
    t=lg-lookup[r1-l1+1]-1;
    ans=mini(ans,mini(block[l1][t],block[r1-(1<<t)+1][t]));
  }
  llg = l1*lg;
  t=llg-1<r?llg-1:r;
  ans=mini(ans,lookup[sblock[t]&(~(((1<<(l-(llg-lg)))-1)<<(llg-l)))]+llg-lg);
  t=r;
  rrg = r1 * lg;
  l=l>rrg+lg?l:rrg+lg;
  ans=mini(ans,lookup[sblock[t]&(~(((1<<(l-(rrg+lg)))-1)<<(rrg+(lg<<1)-l)))]+rrg+lg);
  return ans;
}

#define sq(a, mod) (a * a % mod)

int main() {
  long long n, k, q;
  long long a, b, c, d, e, f, r, s, t, m, seed;
  long long l1, la, lc, lm, d1, da, dc, dm;
  scanf("%lld %lld %lld", &n, &k, &q);
  scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
    &a, &b, &c, &d, &e, &f, &r, &s, &t, &m, &num[0]);
  scanf("%lld %lld %lld %lld %lld %lld %lld %lld",
    &l1, &la, &lc, &lm, &d1, &da, &dc, &dm);
  
  long long cok = t % s;
  for(int x = 2; x <= n; x++) {
    cok = cok * t % s;
    if(cok <= r) {
      num[x - 1] = (a * sq(num[x - 2], m) + b * num[x - 2] + c) % m;
    } else {
      num[x - 1] = (d * sq(num[x - 2], m) + e * num[x - 2] + f) % m;
    }
  }
  
  // build 0.5 sekon
  range_minimum_query(n);
  
  long long sum = 0, product = 1;
  while(q--) {
    l1 = (la * l1 + lc) % lm;
    d1 = (da * d1 + dc) % dm;
    int l = l1 + 1;
    int r = min(l + k - 1 + d1, n);
    l--; r--;
    // rmq code here
    long long mini = num[query(l, r)];
    
    sum += mini;
    product *= mini;
    product %= mod;
  }
  
  printf("%lld %lld\n", sum, product);
  return 0;
}
