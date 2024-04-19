//problem link: https://cses.fi/problemset/task/1623

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

ll n,s,ans=LLONG_MAX;
ll a[27];

void func(int i, ll x){
	if(i==n){
		ans = min(ans, abs((s-x)-x));
		return;
	}
	func(i+1, x+a[i]);
	func(i+1, x);
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s += a[i];
	}
	func(0, 0);
	cout << ans << '\n';
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
