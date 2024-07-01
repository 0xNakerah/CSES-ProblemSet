// problem link: https://cses.fi/problemset/task/1073/
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
// #define int long long
 
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
 
void solve(){
	int n, x; cin >> n;
	multiset<int> st;
	for(int i = 0; i < n; i++){
		cin >> x;
		auto it = st.upper_bound(x);
		if(it == st.end()){
			st.insert(x);
		}else{
			st.erase(it);
			st.insert(x);
		}
	}
	cout << sz(st) << '\n';
}
 
signed main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	// setIO("");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
}
