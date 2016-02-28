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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	ios_base::sync_with_stdio(false);
	int i, j, n;
	while(cin >> n) {
		vector<pair<int,int> > op;
		FORS(i, n) {
			int a, b;
			cin >> a >> b;
			op.push_back(mp(a, b));
		}
		stack<int> st;
		queue<int> q;
		priority_queue<int> pq;
		bool iss = 1, isq = 1, isp = 1;
		FORS(i, n) {
			if(op[i].first == 1) {
				st.push(op[i].second);
				q.push(op[i].second);
				pq.push(op[i].second);
			} else {
				if(q.empty()) {
					iss = 0;
					isq = 0;
					isp = 0;
					continue;
				}
				int ss = st.top();
				int qq = q.front();
				int pqq = pq.top();
				st.pop();
				q.pop();
				pq.pop();
				if(ss != op[i].second) iss = 0;
				if(qq != op[i].second) isq = 0;
				if(pqq != op[i].second) isp = 0;
			}
		}
		if(iss + isq + isp > 1) puts("not sure");
		else if(iss + isq + isp == 0) puts("impossible");
		else if(iss) puts("stack");
		else if(isq) puts("queue");
		else if(isp) puts("priority queue");
	}
	
	return 0;
}
