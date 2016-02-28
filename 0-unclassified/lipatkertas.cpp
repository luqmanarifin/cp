#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];
vector<pair<int,int> > up, down;
vector<int> now;

int main(void)
{
	int i,n,x,j;
	scanf("%d", &n);
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