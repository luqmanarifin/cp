// TREE?!
// www.spoj.com/problems/PT07Y
// attempt 1, feb 3 2018

#include <bits/stdc++.h>
using namespace std;

int v, e;
vector< int > hub[20010];
bool vist[10010];
bool tree = true;

int v1, v2;

void tree_check (int node, int prev_node);

int main ()
{
	cin >> v >> e;
	if (v != e + 1) tree = false;
	for (int i = 1; i <= e; i++) {
		cin >> v1 >> v2;
		hub[v1].push_back(v2);
		hub[v2].push_back(v1);
	}
	
	if (tree) tree_check (1, 1);
	
	if (tree) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}

void tree_check (int node, int prev_node)
{
	if (vist[node]) {
		tree = false;
		return;
	}
	vist[node] = true;
	
	if (!hub[node].empty()) {
		for (int i = 0; i < (int)hub[node].size(); i++) {
			if (hub[node][i] != prev_node) {
				tree_check (hub[node][i], node);
			}
		}
	}
}