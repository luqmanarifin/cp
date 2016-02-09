#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

typedef int LL;
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
#define open freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

pair<LL, string> menu[105];
pair<string, int> p[105];

int main(void)
{
	ios_base::sync_with_stdio(false);
	//open;
	int t;
	cin >> t;
	//cin.ignore();
	while(t--) {
		string title, junk;
		int i, m, n, b, rego, ing;
		getline(cin, title); while(title.length() == 0) getline(cin, title);
		cin >> m >> n >> b;
		//cin.ignore();
		FORS(i, m) {
			cin >> p[i].first >> p[i].second;
			cin.ignore();
		}
		sort(p, p + m);
		FORS(i, n) {
			getline(cin, junk); while(junk.length() == 0) getline(cin, junk);
			menu[i].second = junk;
			menu[i].first = 0;
			
			cin >> ing;
			//cin.ignore();
			while(ing--) {
				LL need = 0;
				string bahan;
				cin >> bahan >> need;
				//cin.ignore();
				int lef = 0, rig = m - 1;
				while(lef < rig) {
					int mid = (lef + rig) >> 1;
					if(p[mid].first < bahan) lef = mid + 1;
					else rig = mid;
				}
				menu[i].first += need * p[lef].second;
			}
		}
		sort(menu, menu + n);
		
		transform(title.begin(), title.end(), title.begin(), ::toupper);
		pf("%s\n", title.c_str());
		bool ada = 0;
		FORS(i, n) {
			if(menu[i].first <= b) {
				ada = 1;
				pf("%s\n", menu[i].second.c_str());
			}
		}
		if(!ada) pf("Too expensive!\n");
		nl;
	}
	
	//close;
	return 0;
}