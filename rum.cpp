#include <bits/stdc++.h>
 
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
#define open freopen("rumah.txt","r",stdin); freopen("out2.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
 
using namespace std;
 
const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;
const int N6 = 1e6 + 5;
 
int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }
 
bool row[N], col[N];
int nrow, ncol;
map<LL, LL> cnt;
vector<pair<LL, LL> > ans;
 
int b[N6], a[N6];
LL w[N6], ten[20];
 
inline int dig(LL num, int sh) {
    return (num/ten[sh]) % 10;
}
 
void radix_sort() {
    queue<pair<LL, LL> > q[10];
    int sz = (int) ans.size(), i, j;
    FOR(i, 0, 18) {
        FORS(j, sz) {
            q[dig(ans[j].first, i)].push(ans[j]);
        }
        int t = 0;
        FORS(j, 10) {
            while(!q[j].empty()) {
                ans[t++] = q[j].front();
                q[j].pop();
            }
        }
    }
    FOR(i, 0, 10) {
        FORS(j, sz) {
            q[dig(ans[j].second, i)].push(ans[j]);
        }
        int t = 0;
        FORM(j, 10) {
            while(!q[j].empty()) {
                ans[t++] = q[j].front();
                q[j].pop();
            }
        }
    }
}
 
inline bool cmp(pair<LL,LL> lef, pair<LL, LL> rig) {
    if(lef.second != rig.second)
        return lef.second > rig.second;
    return lef.first < rig.first;
}
 
int main()
{
    open;
    clock_t t = clock();
    int i, n, m, q;
    ten[0] = 1;
    FOR(i, 1, 19) ten[i] = ten[i-1]*10;
    //FORS(i, 20) pf("%d %lld\n", i, ten[i]);
    sf("%d %d %d", &n, &m, &q);
     
    FORS(i, q) {
        sf("%d %d %lld", &b[i], &a[i], &w[i]);
    }
     
    FORM(i, q) {
        if(b[i] == 1) {
            if(row[a[i]]) continue;
            cnt[w[i]] += m - ncol;
            nrow++;
            row[a[i]] = 1;
        } else {
            if(col[a[i]]) continue;
            cnt[w[i]] += n - nrow;
            ncol++;
            col[a[i]] = 1;
        }  
    }
     
    FORS(i, q) {
        LL now = cnt[w[i]];
        if(now == 0) continue;
        ans.push_back(mp(w[i], now));
        cnt[w[i]] = 0;
    }
    radix_sort();
    int sz = (int) ans.size();
    pf("%d\n", sz);
    FORS(i, sz) {
        pf("%lld %lld\n", ans[i].first, ans[i].second);
    }
    t = clock() - t;
    printf ("It took me %lf ms.\n", ((double)t)*1000/CLOCKS_PER_SEC);
    close;
    return 0;
}