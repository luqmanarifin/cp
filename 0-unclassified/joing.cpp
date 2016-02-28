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
#define open freopen("join.in","r",stdin); freopen("join.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int to[50005], len[50005];
map<string, int> last, maxlen;

void print(int pos) {
	if(pos == 0) return;
	print(to[pos]);
	pf("%d ", pos);
}

int main(void)
{
	open;
	int n, i, j;
	char junk[200];
	sf("%d", &n);
	gets(junk);
	FOR(i, 1, n) {
		len[i] = 1;
		string tc, word, author;
		gets(junk);
		tc = (string) junk;
		
		stringstream ss(tc);
		ss >> junk;
		author = (string) junk;
		author = author.substr(0, author.length()-1);
		string handle = author.substr(1, author.length()-1);
		
		while(ss >> junk) {
			word = (string) junk;
			if(word[0] == '@' && word.length() > 1) {
				string mention = word.substr(1, word.length()-1);
				if(word == author) {
					if(maxlen[mention] > len[i]) {
						len[i] = maxlen[mention];
						to[i] = to[last[mention]];
					}
					continue;
				}				
				if(maxlen[mention] + 1 > len[i]) {
					len[i] = maxlen[mention] + 1;
					to[i] = last[mention];
					if(len[i] > maxlen[handle]) {
						last[handle] = i;
						maxlen[handle] = len[i];
					}
				}
			}
		}
		if(maxlen[handle] == 0) {
			len[i] = 1;
			last[handle] = i;
			maxlen[handle] = 1;
		}
	}
	int ans = -1, pos;
	FOR(i, 1, n) {
		if(len[i] > ans) {
			pos = i;
			ans = len[i];
		}
	}
	cout << ans << endl;
	print(pos); nl;
	close;
	return 0;
}
