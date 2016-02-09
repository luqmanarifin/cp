#include <bits/stdc++.h>
 
/**
 * TOKI Open Contest Agustus 2014
 * Problem :
 * Luqman Arifin (kadalbonek)
 */
 
typedef long long LL;
typedef double DB;
 
#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")
 
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
 
using namespace std;
 
const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;
 
int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }
 
int sum[N], next[N];
 
int main(void)
{
    //open;
    int i, j, n, q;
    char s[N];
    sf("%d %d", &n, &q);
    sf("%s", &s[1]);
    FOR(i, 1, n) {
        sum[i] = sum[i-1];
        if(s[i] == 'b') sum[i]++;
    }
    if(s[n] == 'a') next[n] = n+1;
    else next[n] = n;
    FORD(i, n-1, 1) {
        if(s[i] == 'b') next[i] = i;
        else next[i] = next[i+1];
    }
	 //FOR(i, 1, n) pf("%d ", next[i]); nl;
    while(q--) {
        int l, r;
        sf("%d %d", &l, &r);
        int len = r - l + 1;
        if(len == 1) {
            puts("TIDAK");
            continue;
        }
        if(s[l] == 'a') {
            if(len == 2 && s[r] == 'a') puts("TIDAK");
            else puts("YA");
        } else {
            int bjum = sum[r] - sum[l-1];
            //pf("b ada : %d\n", bjum);
            if(bjum > 2) puts("YA");
            else if(bjum < 2) puts("TIDAK");
            else {
                int mid = (l + r) >> 1;
                //pf("%d %d\n", next[l+1], mid);
                if(next[l+1] <= mid) puts("YA");
                else puts("TIDAK");
            }
        }
    }
    //close;
    return 0;
}