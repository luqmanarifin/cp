#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

int n, e;
vector< pair< int, int > > edge[MAX+5];

int start;
long long dist[MAX+5];

priority_queue < pair < long long, int >, vector< pair < long long, int > >, greater < pair < long long, int > > > pq;

bool visit[MAX+5];
int pre[MAX+5];

void dijkstra ()
{
	cin >> n;
	cin >> e;
	
	{
		int x, y, z;
		for (int i = 1; i <= e; ++i) {
			cin >> x >> y >> z;
			edge[x].push_back(make_pair(y, z));
			edge[y].push_back(make_pair(x, z)); // unweighted
		}
	}
	
	start = 1;
	
	for (int i = 1; i <= n; ++i) dist[i] = 1e18;
	dist[start] = 0;
	
	pq.push(make_pair(dist[start], start));
	
	int proc;
	while (!pq.empty())
	{
		proc = pq.top().second;
		pq.pop();
		
		if (visit[proc]) continue;
		visit[proc] = true;
		
		int siz = edge[proc].size();
		long long temp, adj;
		for (int i = 0; i < siz; ++i) {
			
			adj = edge[proc][i].first;
			temp = edge[proc][i].second + dist[proc];
			
			if (temp < dist[adj]) {
				dist[adj] = temp;
				pre[adj] = proc;
				pq.push(make_pair(dist[adj], adj));
			}
		}
	}
	
	if (pre[n] == 0) cout << -1 << "\n";
	else {
		int cur = n;
		stack< int > output;
		output.push(cur);
		while (cur != 1) {
			
			output.push(pre[cur]);
			cur = pre[cur];
		}
		
		while (!output.empty()) {
			cout << output.top(); output.pop();
			if (!output.empty()) cout << " ";
		}
		cout << "\n";
	}
	
	return;
}

int main ()
{
	dijkstra();
	return 0;
}