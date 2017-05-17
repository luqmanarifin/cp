#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;

LL sum, a[100100], n;
multiset<LL> st, st2;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum += a[i];
		st.insert(a[i]);
	}
	LL x = 0, y;
	multiset<LL>::iterator it;
	for(int i=0;i<n;i++){
		x += a[i];
		it = st.find(a[i]);
		st.erase(it);
		if(x==sum-x){
			cout<<"YES"<<endl;
			return 0;
		}
		if(x>sum-x){
			y = x-(sum-x);
			if(y%2==0 && st2.find(y/2)!=st2.end()){
				cout<<"YES"<<endl;
				return 0;
			}
		}
		if(x<sum-x){
			y = sum-x-x;
			if(y%2==0 && st.find(y/2)!=st.end()){
				cout<<"YES"<<endl;
				return 0;
			}
		}
		st2.insert(a[i]);
	}
	cout<<"NO"<<endl;
}