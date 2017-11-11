/* Author	: Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

/* MACROS SAMPAH */
#define jehian using
#define mau namespace
#define libur std
#define cepet {ios_base::sync_with_stdio(0);cin.tie(NULL);}

jehian mau libur;
/* MACROS FOR TYPE */
typedef long l;
typedef long double ld;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

/* MACROS FOR PRINT */
#define nl printf("\n");
#define sp printf(" ");

/* MACROS FOR FUNCTION */
#define pb push_back
#define mp make_pair
#define eb emplace_back

/* MACROS FOR ATTRIBUTE */
#define fi first
#define se second

/* MACROS FOR SCAN */
#define scc(x) scanf("%c", &x)
#define scd(x) scanf("%Lf", &x)
#define scf(x) scanf("%f", &x)
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scld(x) scanf("%Lf", &x)
#define scui(x) sci(x)
#define scul(x) scl(x)
#define scull(x) scll(x)

#define RESET(x) memset((x), 0, sizeof(x))
#define SET(x,y) memset((x), (y), sizeof(x))

vll dp[256];
string a;
int main(){
	cin >> a;
	for (ll i = 'a'; i <= 'z'; ++i){
		dp[i].pb(-1);
	}
	for (ll i = 0; i < a.size(); ++i){
		dp[a[i]].pb(i);
	}
	for (ll i = 'a'; i <= 'z'; ++i){
		dp[i].pb(a.size());
	}
	ll MIN = 1e9;
	for (ll i = 'a'; i <= 'z'; ++i){
		ll MAX_LOKAL = -1;
		for (ll j = 0; j < dp[i].size() - 1; ++j){
			MAX_LOKAL = max(MAX_LOKAL, dp[i][j+1]-dp[i][j]);
		}
		MIN = min(MIN,MAX_LOKAL);
	}
	cout << MIN << endl;
	return 0;
}