/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, j, n) for (int i = j; i < n; ++i)

typedef long long int ll;


void dfs(vector<vector<int>> &adj, vector<vector<ll>> &dp, int ind, 
	vector<pair<int,int>> &vect, vector<bool> &vis, vector<bool> &eval){
	forn(i, adj[ind].size()){
		if (!vis[adj[ind][i]]){
			vis[adj[ind][i]] = true;
			dfs(adj, dp, adj[ind][i], vect, vis, eval);
		}
	}
	forn(i, adj[ind].size()){
		if (eval[adj[ind][i]])
			dp[ind][0] += max(abs(vect[ind].first - vect[adj[ind][i]].first) + dp[adj[ind][i]][0],
							  abs(vect[ind].first - vect[adj[ind][i]].second) + dp[adj[ind][i]][1]);
	}
	forn(i, adj[ind].size()){
		if (eval[adj[ind][i]])
			dp[ind][1] += max(abs(vect[ind].second - vect[adj[ind][i]].first) + dp[adj[ind][i]][0],
							  abs(vect[ind].second - vect[adj[ind][i]].second) + dp[adj[ind][i]][1]);
	}
	eval[ind] = true;
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<pair<int, int>> vert(n + 1);
		for(int i = 1; i <= n; ++i){
			int l, r;
			cin >> l >> r;
			vert[i] = {l, r};
		}
		vector<vector<int>> adj(n + 1);
		forsn(i, 1, n){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int root = 1;
		vector<bool> visited(n + 1, false), eval(n+1, false);
		vector<vector<ll>> dp(n + 1, vector<ll> (2, 0));
		visited[root] = true;
		dfs(adj, dp, root, vert, visited, eval);
		cout << max(dp[root][0], dp[root][1]) << bline;
	}
	return 0;
}