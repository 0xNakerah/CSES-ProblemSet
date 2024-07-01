// problem link: https://cses.fi/problemset/task/1632/
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
	int n, k, ans = 0; cin >> n >> k;
	multiset<int> st;
	for(int i = 0; i < k; i++){
		st.insert(0);
	}
	pair<int,int> a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i].S >> a[i].F;
	}
	sort(a, a+n);
	for(int i = 0; i < n; i++){
		auto it = st.upper_bound(a[i].S);
		if(it == st.begin()){
			continue;
		}
		st.erase(--it);
		st.insert(a[i].F);
		ans++;
	}
	cout << ans << '\n';
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
