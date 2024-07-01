// problem link: https://cses.fi/problemset/task/1625/

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
 
const int N = 7, LEN = 48;
int r[4] = {-1, 0, 1, 0};
int c[4] = {0, 1, 0, -1};
int ss[LEN];
bool not_valid[9][9];
string s;
 
int fun(int i, int j, int idx){
	if( not_valid[i][j-1] && not_valid[i][j+1] && !not_valid[i-1][j] && !not_valid[i+1][j] ){
		return 0;
	}
	if( not_valid[i-1][j] && not_valid[i+1][j] && !not_valid[i][j+1] && !not_valid[i][j-1] ){
		return 0;
	}
	if(i == 7 && j == 1){
		return (idx == LEN);
	}
	if(idx == LEN){
		return 0;
	}
	
	int ret = 0, ptr = ss[idx];
	not_valid[i][j] = true;
	
	if(ptr < 4){
		if(!not_valid[i + r[ptr]][j + c[ptr]]){
			ret += fun(i + r[ptr], j + c[ptr], idx + 1);
		}
	}else{
		for(int k = 0; k < 4; k++){
			if(!not_valid[i + r[k]][j + c[k]]){
				ret += fun(i + r[k], j + c[k], idx + 1);
			}
		}
	}
	
	not_valid[i][j] = false;
	return ret;
}
 
void solve(){
	cin >> s;
	for(int i = 0; i < 9; i++){
		not_valid[0][i] = not_valid[8][i] = not_valid[i][0] = not_valid[i][8] = true;
	}
	
	for(int i = 0; i < LEN; i++){
		if(s[i] == 'U'){
			ss[i] = 0;
		}else if(s[i] == 'R'){
			ss[i] = 1;
		}else if(s[i] == 'D'){
			ss[i] = 2;
		}else if(s[i] == 'L'){
			ss[i] = 3;
		}else{
			ss[i] = 4;
		}
	}
	
	int ans = fun(1, 1, 0);
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
