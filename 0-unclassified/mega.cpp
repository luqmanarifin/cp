#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for((i) = (a); (i) <= (b); ++(i))
#define FORD(i,a,b) for((i) = (a); (i) >= (b); --(i))
#define FORS(i,n) for((i) = 0; (i) < (n); ++(i))
#define FORM(i,n) for((i) = (n)-1; (i) >= 0; --(i))
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define wong first
#define rad second

bool by(const pair<int,int> &lef, const pair<int,int> &rig) {
	return lef.rad < rig.rad;
}

pair<int,int> pos[1005];
int ans;
int k;

int main(void)
{
	int i, n, s, a, b, sum = 0;
	sf("%d %d", &n, &s);
	k = 1000000 - s; 
	FORS(i,n) {
		sf("%d %d %d",&a,&b, &pos[i].wong);
		pos[i].rad = a*a + b*b;
	}
	//FORS(i,n) pf("%d ",pos[i].rad); nl;
	sort(pos, pos+n, by);
	FORS(i,n) {
		sum += pos[i].wong;
		if(sum >= k) {ans = pos[i].rad; break; }
	}
	if(ans == 0) puts("-1");
	else pf("%.8f\n",sqrt(ans));
	//FORS(i,n) pf("%d ",pos[i].rad);
	
	return 0;
}