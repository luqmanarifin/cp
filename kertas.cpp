#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

#define LL long long
#define DB double
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORD(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define OUT { puts("INVALID"); return 0; }
#define L first
#define R second

const int N = 100010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int a[N];
vector<pair<int,int> > up, down;
vector<int> now;

int main(void)
{
	char gg[10];
	gets(gg);
	int i,n,x,j;
	sf("%d", &n);
	FOR(i,1,n) {
		sf("%d", &x);
		a[x] = i;
	}
	FOR(i,1,n) {
		int l = min(a[i], a[i-1]);
		int r = max(a[i], a[i-1]);
		if(i%2 && i > 1)
			up.push_back( mp(l,r) );
		else if(i%2 == 0)
			down.push_back( mp(l,r) );
	}
	if(up.size()) sort(up.begin(), up.end());
	if(down.size()) sort(down.begin(), down.end());
	
	if(up.size())
	FORS(i, up.size()) {
		while(now.size())
			if(now.back() < up[i].L)
				now.pop_back();
			else break;
			
		if(now.size())
			if(up[i].L < now.back() && now.back() < up[i].R)
				OUT
		now.push_back(up[i].R);
	}
	
	if(now.size()) now.clear();
	if(down.size())
	FORS(i, down.size()) {
		while(now.size())
			if(now.back() < down[i].L)
				now.pop_back();
			else break;

		if(now.size())
			if(down[i].L < now.back() && now.back() < down[i].R)
				OUT
		now.push_back(down[i].R);
	}
	
	// A cekung ke atas
	// B cekung ke bawah 
	bool cek = 0;	
	FOR(i,2,n) {
		if((a[i] > a[i-1] && a[i-1] > a[i-2]) || (a[i] < a[i-1] && a[i-1] < a[i-2]))
			cek ^= 1;
		putchar(cek? 'B' : 'A');
	}
	nl;
	return 0;
}