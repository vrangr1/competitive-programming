/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define pb(a) push_back(a)
#define pass (void)0
typedef long long int ll;
void print(vector<vector<int>> &arr){
	cout << "2d vector: \n";
	forn(i, arr.size()){
		forn(j, arr[i].size())
			cout << arr[i][j] << " ";
		cout << bline;
	}
}
void print(vector<int> &arr){
	cout << "1d vector: \n";
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << bline;
}


void dfs(vector<vector<int>> &adj, vector<bool> &vis, int ind, int &ct){
	vis[ind] = true;
	ct++;
	forn(i, adj[ind].size()){
		if (!vis[adj[ind][i]])
			dfs(adj, vis, adj[ind][i], ct);
	}
}


int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	int ct = 0;
	forn(i, m){
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
	}
	forsn(i, 1, n){
		vector<bool> vis(n, false);
		dfs(adj, vis, i, ct);
	}
	cout << ct;
	return 0;
}