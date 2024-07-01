// problem link: https://cses.fi/problemset/task/1628/

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
#define int long long
 
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
 
void solve(){
	int n, x, ans = 0; cin >> n >> x;
	int a[n/2], b[n - n/2];
	for(int i = 0; i < n/2; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n-n/2; i++){
		cin >> b[i];
	}
	
	vector<int> aa, bb;
	for(int mask = 0; mask < (1<<(n/2)); mask++){
		int s = 0;
		for(int i = 0; i < n/2; i++){
			if((mask>>i) & 1){
				s += a[i];
			}
		}
		aa.PB(s);
	}
	
	for(int mask = 0; mask < (1<<(n-n/2)); mask++){
		int s = 0;
		for(int i = 0; i < n-n/2; i++){
			if((mask>>i) & 1){
				s += b[i];
			}
		}
		bb.PB(s);
	}
	
	sort(all(bb));
	for(int i = 0; i < sz(aa); i++){
		auto l = lower_bound(all(bb), x-aa[i]) - bb.begin();
		auto r = upper_bound(all(bb), x-aa[i]) - bb.begin();
		ans += r-l;
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
