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