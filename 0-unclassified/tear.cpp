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

using namespace std;

const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n, a;
char s[N];

bool isValid(int now) {
	if(now + 6 >= n) return false;
	if(s[now] == 'd'
	&&	s[now+1] == 'e'
	&& s[now+2] == 's'
	&& s[now+3] == 'm'
	&& s[now+4] == 'o'
	&& s[now+5] == 'n'
	&& s[now+6] == 'd') return true;
	return false;
}

bool valid(char c) {
	switch (c) {
		case 'd' :
			return (isValid(a) || isValid(a - 6));
			break;
		case 'e' :
			return isValid(a - 1);
			break;
		case 's' :
			return isValid(a - 2);
			break;
		case 'm' :
			return isValid(a - 3);
			break;
		case 'o' :
			return isValid(a - 4);
			break;
		case 'n' :
			return isValid(a - 5);
			break;
	}
}

int main(void)
{
	sf("%s", s);
	n = strlen(s);
	int i, m; sf("%d", &m);
	FORS(i, n) if(isValid(i)) {
		puts("I love you, Desmond!");
		puts("0");
		return 0;
	}
	FOR(i, 1, m) {
		int c;
		sf("%d %c", &a, &c);
		a--;
		s[a] = c;
		if(valid(c)) {
			puts("I love you, Desmond!");
			cout << i << endl;
			return 0;
		}
	}
	puts("Goodbye, my love!");
	return 0;
}
