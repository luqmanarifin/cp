#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ip;

int n, idx, maks, banyak, jumlah[10010];
string sa, sb;
vector <int> adj[10010];
queue <ip> q;
map <string, int> ma;
map <int, string> balik;

int main() {
	cin >> n;
	idx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> sa >> sb;
		if (ma[sa] == 0) {
			ma[sa] = ++idx;
			balik[idx] = sa;
		}
		if (ma[sb] == 0) {
			ma[sb] = ++idx;
			balik[idx] = sb;
		}
		adj[ma[sb]].push_back(ma[sa]);
		adj[ma[sa]].push_back(ma[sb]);
	}
	cout << idx << "\n";
	for (int i = 1; i <= idx; i++) {
		q.push({i, 0});
		maks = 0;
		banyak = 0;
		memset(jumlah, 0, sizeof(jumlah));
    //printf("source %d\n", i);
		while (!q.empty()) {
			ip now = q.front();
			q.pop();
			
			int titik = now.first;
			int jarak = now.second;
      //printf("%d %d\n", titik, jarak);
			
			if (jarak == 2) {
				if (jumlah[titik] == -1) continue;
				jumlah[titik]++;
				if (jumlah[titik] > maks) {
					maks = jumlah[titik];
					banyak = 1;
				} else if (jumlah[titik] == maks) {
					banyak++;
				}
				continue;
			} else {
				jumlah[titik] = -1;
			}
			for (int nxt : adj[titik]) {
				if (jumlah[nxt] == -1) continue;
				q.push({nxt, jarak+1});
			}
		}
		cout << balik[i] << " " << banyak << "\n";
	}
}