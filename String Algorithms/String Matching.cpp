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
 
void solve(){
	string s,p; cin >> s >> p;
	s = p + '#' + s;
	int cnt = 0;
	int l = 0, r = 0, n = sz(s);
	vector<int> z(n);
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
		
		if(z[i] == sz(p)){
			cnt++;
		}
	}
	cout << cnt << '\n';
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
