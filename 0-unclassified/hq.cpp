#include<iostream>
using namespace std;

int main() {
	string s; cin >> s;
	cout << (s.find_first_of("HQ9") != string::npos ? "YES" : "NO") << endl;
}