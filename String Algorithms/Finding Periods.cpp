//problem link: https://cses.fi/problemset/task/1733/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define F first
#define S second
#define PB push_back

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

vector<int> z_func(string &s){
	int n = sz(s);
	vector<int> z(n);
	int l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i < r){
			z[i] = min(r-i, z[i-l]);
		}
		while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
			z[i]++;
		}
		if(i+z[i] > r){
			l = i;
			r = i+z[i];
		}
	}
	return z;
}

void solve(){
	string s; cin >> s;
	vector<int> z = z_func(s);
	for(int i = 1; i < sz(s); i++){
		if(i + z[i] == sz(s)){
			cout << i << ' ';
		}
	}
	cout << sz(s) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	// setIO("");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
} 	 		   			  	
