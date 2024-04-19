//problem link: https://cses.fi/problemset/task/1622

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

int cnt[26];
string s;
vector<string> ans;

void func(string x){
	if(sz(x)==sz(s)){
		ans.PB(x);
		return;
	}
	
	for(int i = 0; i < 26; i++){
		if(cnt[i]){
			cnt[i]--;
			func(x+char(i+'a'));
			cnt[i]++;
		}
	}
}

void solve(){
	cin >> s;
	for(int i = 0; i < sz(s); i++){
		cnt[s[i]-'a']++;
	}

	string x = "";
	func(x);
	cout << sz(ans) << '\n';
	for(string &x: ans){
		cout << x << '\n';
	}
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
