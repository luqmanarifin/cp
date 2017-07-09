#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

bool first = true;
int nn[MAXN+5];
string fns[MAXN+5], fn[MAXN+5];
set<string> sid;
map<string,int> id;
vector<string> dep_s[MAXN+5];
vector<string> ans;
int dep[MAXN+5];
vector<int> rdep[MAXN+5];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> fns[i];
		sid.insert(fns[i]);
		scanf("%d", &nn[i]);
		for (int j = 0; j < nn[i]; ++j) {
			string s;
			cin >> s;
			dep_s[i].push_back(s);
			sid.insert(s);
		}
	}

	/* convert string to integer, lexicographically smallest first */
	int cnt = 0;
	for (typeof(sid.begin()) it = sid.begin(); it != sid.end(); ++it) {
		string s = *it;
		id[s] = cnt++;
	}

	/* convert data using new ids */
	for (int i = 0; i < n; ++i) {
		int fid = id[fns[i]];
		fn[fid] = fns[i];
		dep[fid] = nn[i];
		for (int j = 0; j < nn[i]; ++j) {
			int nid = id[dep_s[i][j]];
			rdep[nid].push_back(fid);
		}
	}

	/* process toposort */
	int ok = 0;
	while (ok != cnt) {
		for (int i = 0; i < cnt; ++i) {
			if (dep[i] == 0) {
				if (!first) cout << " -> ";
				first = false;
				cout << fn[i];
				ok++;
				dep[i]--;
				for (int j = 0; j < rdep[i].size(); ++j) {
					dep[rdep[i][j]]--;
				}
				break;
			}
		}
	}
	cout << endl;
	return 0;
}
