#include<bits/stdc++.h>
#define ll long long
#define read(x) scanf("%d",&x);
#define readll(x) cin>>x;
#define FOR(x,a,b) for(int x=a;x<b;x++)
#define MP make_pair
#define PB push_back
#define pii pair<int,int>
#define readN(N,X) for(int i=0;i<N;i++) cin>>X[i];
#define pff pair<double,double>
using namespace std;

long long fastpow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y) % MOD;
        }
        y = (y*y) % MOD;
        b /= 2;
    }
    return x;
}

long long InverseEuler(int n, int MOD)
{
    return fastpow(n,MOD-2,MOD);
}
 
long long f[300000];
bool init;
long long C(int n, int r, int MOD)
{
    if (!init){
        init=1;
        f[0]=1;
        for (int i=1; i<300000;i++)
            f[i]= (f[i-1]*i) % MOD;
        
    }
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}


int N;
int a[300005];
int a2[300005];
int main(){
   std::ios::sync_with_stdio(false); 
   cin>>N;
   readN(N,a);
   long long tot=0;
   long long tot2=0;
   long long bon2=0;
   for (int i=0;i<N;i++){
    tot += a[i];
    if (a[i] == 2000) {
            tot2 += 2000;
            bon2 += 200;
            a2[i] = 2000;
        } else if (bon2 >= 1000){
            //cout<<"cut "<<i<<endl;
            a2[i] = 0;
            long long pr = max(0LL, 1000 - bon2);
            tot2 += pr;
            bon2 -= (1000 - pr);
        } else {
            tot2 += 1000;
            bon2 += 100;
            a2[i] = 1000;
        }
   }

   long long best = tot;
   long long best2 = tot2;
    
   long long sisa = 0;
   long long sisa2 = 0;
   long long bonus = tot/10;
   for (int i=N-1;i>=0;i--){
        sisa += a[i];
        bonus -= (a[i]/10);
        tot -= a[i];
        long long pay = tot + max(0LL, sisa - bonus); 
        best = min(best, pay);

        sisa2 += a2[i];
        bon2 -= (a2[i]/10);
        tot2 -= a2[i];
        long long pay2 = tot2 + max(0LL, sisa2 - bon2);
        best2 = min(best2, pay2);
   }


   cout<<min(best,best2)<<endl;
}