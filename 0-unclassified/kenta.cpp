#include <bits/stdc++.h>
using namespace std;

// ini komen wew
long long temp, result;


long long dnc(long long a, long long b, long long mod)
{
    if(b == 0) return 1;
    temp = dnc(a,b/2, mod);
    result = temp*temp%mod;
    if (b %2 == 1)
        result = temp*a%mod;
        
    return result;
}

// banyak bilangan dari 1..n yang relatif prima dengan n
long long tau(long long n) {
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        if(__gcd(i, (int)n) == 1) {
            ans++;
        }
    }
    return ans;
}

int main()
{
    long long A, B ,C, N;
    cin >> A >> B >> C >> N;
    
    long long awal = dnc(B,C, tau(N));
    long long akhir = dnc(A, awal, N);
    
    cout << (akhir%N) +1 << endl;

    return 0;
}