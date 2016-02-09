#include <bits/stdc++.h>

using namespace std;

const long long pol = 1e7 + 5;
const long long mod = 1e9 + 7;

long long num[pol];
int block[420000][32];
int sblock[pol];
int lookup[32];
int N = pol;
int lg = 32;
int size = 420000; // block.size()

int mini(int a,int b){
  return num[b]<num[a]?b:a;
}

void build(int n){
  N=n;
  lg=32-__builtin_clz(N);
  size = (N+lg-1)/lg;
  for(int i=0;i<N;i++){
    if(i%lg==0)
      block[i/lg][0]=i;
    block[i/lg][0]=mini(i,block[i/lg][0]);
  }
  for(int j=1;j<lg;j++)
    for(int i=0;i<size;i++)
      block[i][j]=mini(block[i][j-1],block[i+(i+(1<<(j-1))<size?(1<<(j-1)):0)][j-1]);

  for(int i=0;i<size;i++){
    std::stack<int> st;
    for(int j=i*lg;j<N&&j<i*lg+lg;j++){
      while(!st.empty()&&num[j]<num[st.top()])
        st.pop();
      sblock[j]=1<<(i*lg+lg-j-1);
      if(!st.empty())
        sblock[j]|=sblock[st.top()];
      st.push(j);
    }
  }

  for(int i=1,ans=lg-1;i<(1<<lg);i++){
    if(1<<(lg-ans)<=i)
      ans--;
    lookup[i]=ans;
  }
}

int query(int l,int r){
  int l1=l/lg+1;
  int r1=r/lg-1;
  int ans=l;
  int t;
  if(l1<=r1){
    t=lg-lookup[r1-l1+1]-1;
    ans=mini(ans,mini(block[l1][t],block[r1-(1<<t)+1][t]));
  }
  t=l1*lg-1<r?l1*lg-1:r;
  ans=mini(ans,lookup[sblock[t]&(~(((1<<(l-(l1*lg-lg)))-1)<<(l1*lg-l)))]+l1*lg-lg);
  t=r;
  l=l>r1*lg+lg?l:r1*lg+lg;
  ans=mini(ans,lookup[sblock[t]&(~(((1<<(l-(r1*lg+lg)))-1)<<(r1*lg+(lg<<1)-l)))]+r1*lg+lg);
  return ans;
}

long long sq(long long a, long long mod) {
  return a * a % mod;
}

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
  build(n);
  
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
