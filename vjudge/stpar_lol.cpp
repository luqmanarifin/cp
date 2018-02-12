#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
	int n;
	while(cin >> n){
		bool tf = true;
		queue<int> q;
		vector<int> v;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			q.push(a[i]);
		}
		int pos = 1;
		while(!q.empty() || !v.empty() || pos <= n){
			int f = q.front();
			if(f == pos){
				pos ++;
				q.pop();
			}
			else if(!v.empty() && v.back() == pos){
				v.pop_back();
				//temp.pop();
				pos++;
			}
			else{
				v.pb(f);
				q.pop();
			}
			for(int i = v.size() - 2; i >= 0; i--)
				if(v[i + 1] > v[i])	{tf = false; break;}
			if(!tf)	break;
			//cout << pos;
		}
		if(tf)	cout << "Yes\n";
		else	cout << "No\n";
	}	
}