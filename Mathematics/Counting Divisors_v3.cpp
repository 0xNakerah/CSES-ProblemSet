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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
template<class T> using  ordered_multiset= tree<pair<T, T>, null_type, less<pair<T, T>>, rb_tree_tag, tree_order_statistics_node_update>;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e6;
int max_div[N + 7];

void solve(){
	int n, ans = 1; cin >> n;
	while(n != 1){
		int prime = max_div[n], cnt = 0;
		while(n % prime == 0){
			n /= prime;
			cnt++;
		}
		ans *= (cnt + 1);
	}
	cout << ans << '\n';
}
 
signed main(){
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	// setIO("");
	int testcase = 1;
	cin >> testcase;
	
	for(int i = 2; i <= N; i++){
		if(max_div[i]) continue;
		for(int j = i; j <= N; j += i){
			max_div[j] = i;
		}
	}
	
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
}
