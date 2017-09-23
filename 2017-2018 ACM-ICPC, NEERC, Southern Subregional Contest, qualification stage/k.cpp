#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<string,string> pss;
typedef long long LL;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double pi = acos(-1);
const int INT = 1e9;
const int N = 300;
pss arr[N + 5];
pii ar[N + 5];
bool B[N + 5];
bool visit[N + 5];
int n, a, b, k, f;

vector<string> ve;
int adj[N + 5];
vector<int> isi;
int main(){
	scanf("%d%d%d%d%d", &n, &a, &b, &k, &f);
	for(int i = 0;i < n; ++i){
		cin >> arr[i].fi >> arr[i].se;
		ve.push_back(arr[i].fi);
		ve.push_back(arr[i].se);
	}
	sort(ve.begin(), ve.end());
	ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
	for(int i = 0;i < n; ++i){
		ar[i].fi = lower_bound(ve.begin(), ve.end(), arr[i].fi) - ve.begin();
		ar[i].se = lower_bound(ve.begin(), ve.end(), arr[i].se) - ve.begin();
	}
	for(int i = 1;i < n; ++i){
		if(ar[i].fi == ar[i-1].se) B[i] = true;
	}
	for(int i = 0;i < n; ++i){
		if(!visit[i]){
			adj[i] = B[i] ? b : a;
			for(int j = i + 1; j < n; ++j){
				if(ar[i] == ar[j] || (ar[i].fi == ar[j].se && ar[i].se == ar[j].fi)) {
					visit[j] = true;
					adj[i] += B[j] ? b : a;
				}
			}
			isi.push_back(adj[i]);
		}
	}
	sort(isi.begin(), isi.end());
	reverse(isi.begin(), isi.end());
	int tot = 0;
	for(int i = 0, j = 0;i < (int) isi.size(); ++i, ++j){
		if(j < k){
			tot += min(isi[i], f);
		}
		else{
			tot += isi[i];
		}
	}

	printf("%d\n", tot);
	return 0;
}