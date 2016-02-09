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

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

string data[2][3];
int len[2][3];

#define OUT { puts("NO"); return 0; }

int main(void)
{
	ios_base::sync_with_stdio(false);
	data[0][0] = "lios";
	data[0][1] = "etr";
	data[0][2] = "initis";
	data[1][0] = "liala";
	data[1][1] = "etra";
	data[1][2] = "inites";
	string s;
	int i, j, now = -1, stat, cur = 0, start;
	FORS(i, 2) FORS(j, 3) len[i][j] = data[i][j].length();
	
	cin >> s;
	FORS(i, 2) FORS(j, 3)
		if(s.length() >= len[i][j])
			if(data[i][j] == s.substr(s.length()-len[i][j], len[i][j])) {
				stat = i;
				start = now = j;
			}
			
	if(now == -1) OUT
	
	while(cin >> s) {
		int n = s.length();
		if(s.length() >= len[stat][now+1] && now < 2 && s.substr(s.length()-len[stat][now+1], len[stat][now+1]) == data[stat][now+1])
			now++;
		else {
			if(now == 1) OUT
			else if(s.length() >= len[stat][now] && s.substr(s.length()-len[stat][now], len[stat][now]) != data[stat][now])
				OUT
			else if(s.length() < len[stat][now])
				OUT
		}
		cur++;
	}
	if(!now && cur) OUT
	if(start == 2 && cur) OUT
	puts("YES");
	return 0;
}
