#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<memory>
#include<map>
#include<queue>
#include <sstream>
#include <set>
using namespace std;
typedef pair<int,int> PII;
void adjust(PII &A){
	if (A.first > A.second)
		swap(A.first, A.second);
}
map<string, int> mat;
vector<PII> E[10100];

int TOT;
int insert(string &str){
	if (mat.find(str) == mat.end())
		mat[str] = ++TOT;
	return mat[str];
}
int equal(int a,int b, int c, int d){
	if (a==b || a==c || a==d
		|| b==c || b ==d
			|| c ==d)
			return 1;
	return 0;
}
vector<PII> conA;
vector<PII> conB;
vector<int> visit;
queue<PII> Q;
int main(){
	int tt;
	int N, M;
	//cin >> tt;
	tt = 1;
	for (int tcas = 1; tcas <= tt; ++tcas){
		cin >> N ;
		mat.clear();
		TOT = 0;
		for (int i = 0; i <= 2 * N; i++)
			E[i].clear();
		for (int i = 0; i < N; i++){
			string inStr;
			cin>>inStr;
			for (int j = 0;j < inStr.length(); j++)
				if (inStr[j] == '+' || inStr[j] == '=')
					inStr[j] = ' ';
			string s1, s2;
			int num;
			istringstream in(inStr);
			in >> s1 >> s2 >> num;
			int a = insert(s1);
			int b = insert(s2);
			E[a].push_back(PII(b, num));
			E[b].push_back(PII(a, num));
		}
		cin >> M;
		for (int i = 0; i < M; i++){
			string inStr;
			cin >> inStr;
			string backStr = inStr;
			for (int j = 0;j < inStr.length(); j++)
				if (inStr[j] == '+' || inStr[j] == '=')
					inStr[j] = ' ';
			string s1, s2;
			istringstream in(inStr);
			in >> s1 >> s2;
			if (mat.find(s1)==mat.end()
				|| mat.find(s2) == mat.end())
				continue;
			int a = mat[s1];
			int b = mat[s2];
			while(!Q.empty())
				Q.pop();
			visit.clear();
			visit.resize(TOT+1);
			for (auto &e : E[b]){
				visit[e.first] = 1;
				Q.push(e);
			}
			while(!Q.empty()){
				PII now = Q.front();
				Q.pop();
				if (now.first == a){
					cout<<backStr<<"="<<now.second<<endl;
					break;
				}
				for (auto &e : E[now.first])
					for (auto &ee : E[e.first])
						if (!visit[ee.first]){
							visit[ee.first] = 1;
							Q.push(PII(ee.first, now.second - e.second + ee.second));
						}
			}
		}


		
	}
}