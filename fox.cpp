#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>

using namespace std;

#define LL long long
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
#define db double

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

struct data {
	int num;
	int init;
};

bool byNum (const data &left, const data &right) {
	return left.num > right.num;
}

bool descend(const int &left, const int &right) {
	return left > right;
}

data total[105];
pair<int,int> pile[105];
int sisa[105], card[105];

int main(void)
{
	int temp, n, i, j;
	sf("%d", &n);
	FORS(i,n) {
		sf("%d", &card[i]);
		sisa[i] = 0;
		FORS(j,card[i]/2) {
			sf("%d", &temp);
			pile[i].first += temp;
		}
		if(card[i]%2) {
			sf("%d", &temp);
			sisa[i] = temp;
		}
		FORS(j,card[i]/2) {
			sf("%d", &temp);
			pile[i].second += temp;
		}
		total[i].num = pile[i].first + sisa[i] + pile[i].second;
		total[i].init = i;
	}
	sort(total, total+n, byNum);
	sort(sisa, sisa+n, descend);
	LL a = 0, b = 0;
	FORS(i,n) {
		a += pile[total[i].init].first;
		b += pile[total[i].init].second;
	}
	FORS(i,n) {
		if(i%2)
			b += sisa[i];
		else
			a += sisa[i];
		if(!sisa[i]) break;
	}
	cout << a << " " << b << endl;
	
	return 0;
}