//problem link: https://cses.fi/problemset/task/1624

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

string grid[8];
bool vis[8][8];
int ans;

bool valid(int i, int j){
	return i>=0&&i<8&&j>=0&&j<8;
}

void count(int r){
	if(r==8){
		ans++;
		return;
	}
	
	for(int c = 0; c < 8; c++){
		if(grid[r][c]=='*')continue;
		bool ok = true;
		for(int i = 0; i < r; i++){
			if(vis[i][c])ok=false;
		}
		for(int i = 1; i < 8; i++){
			if(valid(r+i,c+i)&&vis[r+i][c+i])ok=false;
			if(valid(r-i,c-i)&&vis[r-i][c-i])ok=false;
			if(valid(r+i,c-i)&&vis[r+i][c-i])ok=false;
			if(valid(r-i,c+i)&&vis[r-i][c+i])ok=false;
		}
		if(ok){
			vis[r][c]=true;
			count(r+1);
			vis[r][c]=false;
		}
	}
}

void solve(){
	for(int i = 0; i < 8; i++){
		cin >> grid[i];
	}
	count(0);
	cout << ans << '\n';
}

int main(){
	// ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	// setIO("");
	int testcase = 1;
	// cin >> testcase;
	for(int i = 1; i <= testcase; i++){
		// cout << "Case " << i << ": ";
		solve();
	}
} 	 		   			  	
