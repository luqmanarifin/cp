#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = b; i >= a; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n-i; i >= 0; --i)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int maxn = 3e5 + 5;
pair<int,int> p[maxn], now;
int d[maxn], v[maxn];
LL ans = 0;

int main(void)
{
    int n, x, y, lim, last, i, k;
    sf("%d %d", &n, &lim);
    FOR(i,1,n) {
        sf("%d %d", &x, &y);
        if(x > y) swap(x,y);
        d[x]++; d[y]++;
        v[x]++; v[y]++;
        p[i] = mp(x, y);
    }
    sort(p+1, p+1+n);
    sort(v+1, v+1+n);
    FOR(i,1,n) {
        k = lower_bound(v+1, v+1+n, lim-v[i]) - v;
        ans += n - k + (k > i);
    }
    ans /= 2; now = p[1]; last = 1;
    FOR(i,2,n+1)
        if(p[i] != now) {
            int cur = d[now.first] + d[now.second];
            if(cur >= lim && cur < lim + i - last) ans--;
            now = p[i]; last = i;
        }
    
    cout << ans << endl;
    
    return 0;
}