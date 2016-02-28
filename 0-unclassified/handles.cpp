#include <bits/stdc++.h>

using namespace std;

map<string, string> trans, back;
vector<string> start;
set<string> ada;

int main() {
	int q;
	cin >> q;
	while(q--) {
		string lama, baru;
		cin >> lama >> baru;
		if(ada.find(lama) == ada.end()) {
			ada.insert(baru);
			start.emplace_back(lama);
			trans[lama] = baru;
			back[baru] = lama;
		} else {
			ada.erase(lama);
			ada.insert(baru);
			trans[back[lama]] = baru;
			back[baru] = back[lama];
		}
	}
	cout << start.size() << endl;
	for(auto it : start) printf("%s %s\n", it.c_str(), trans[it].c_str());
	
	return 0;
}