
#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>
#include<map>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<sstream>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PHI 2.0*acos(0.0)
#define FOR(i,j) for (int (i) = 0;(i) < (j);(i)++)
#define FORU(i,j,k) for (int (i) = (j);(i) <= (k);(i)++)
#define FORD(i,j,k) for (int (i) = (j);(i) >= (k);(i)--)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

inline void out(int a){
	printf("%d\n",a);
}
inline void out(int a,int b){
	printf("%d %d\n",a,b);
}
inline void outf(double a){
	printf("%3.lf\n",a);
}
inline void outf(double a,double b){
	printf("%3.lf %3.lf\n",a,b);
}
inline void base(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
}

int main(){
	base();
	int n;cin>>n;
	if(n==1){
		cout << "NO" << endl;
		return 0;
	}
	map<ll,vi> pos;
	vector<ll> data;
	ll tot = 0;
	FOR(i,n){
		ll a;cin>>a;
		data.pb(a);
		pos[a].pb(i);
		tot+=a;
	}
	if(tot%2==1)cout << "NO" << endl;
	else{
		tot/=2;
		ll now = 0;
		FOR(i,n){
			ll target = tot-now;
			if(pos.count(target)){
				int lo = (int)(lower_bound(pos[target].begin(),pos[target].end(),i)-pos[target].begin());
				if(lo < pos[target].size()){
					cout << "YES" << endl;
					return 0;
				}
			}
			now+=data[i];
		}
		now = 0;
		FORD(i,n-1,0){
			ll target= tot-now;
			if(pos.count(target)){
				int lo = pos[target][0];
				if(lo < i){
					cout << "YES" << endl;
					return 0;
				}
			}
			now+=data[i];
		}
		cout << "NO" << endl;
		return 0;
	}
	return 0;
}
