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

typedef long long int ll;

ll moves;

typedef struct node{
	bool token_there;
	int count;
}node;


inline int ret_num(char ch){
	return (int)(ch - '0');
}




void dfs(vector<node> &nodes, vector<vector<int>> &adj, int ind){
	// if (nodes[ind].token_there){
	// 	if (nodes[ind].parent != -1){
	// 		if (nodes[ind].height - 1 > nodes[nodes[ind].parent].fill_depth){
	// 			cout << "ind: " << ind << bline;
	// 			moves = moves + (abs(nodes[ind].height - nodes[nodes[ind].parent].fill_depth) - 1);
	// 			nodes[ind].fill_depth = nodes[nodes[ind].parent].fill_depth + 1;
	// 		}
	// 		else{
	// 			nodes[ind].fill_depth = nodes[nodes[ind].parent].fill_depth + 1;
	// 		}
	// 	}
	// }
	// else{
	// 	if (nodes[ind].parent != -1){
	// 		nodes[ind].fill_depth = nodes[nodes[ind].parent].fill_depth;
	// 	}
	// }

	int n = adj[ind].size();
	int mx = 0;
	bool two = true;
	forn(i, n){
		dfs(nodes, adj, adj[ind][i]);
		// if (mx < nodes[adj[ind][i]].count)
		// 	mx = nodes[adj[ind][i]].count;
		mx = max(nodes[adj[ind][i]].count, mx);
	}
	forn(i, n){
		if (mx == nodes[adj[ind][i]].count)
			two = !two;
	}
	if (!nodes[ind].token_there)
		moves = moves + mx;
	if (n == 0){
		nodes[ind].count = (nodes[ind].token_there? 1:0);
	}
	else{
		if (nodes[ind].token_there){
			nodes[ind].count = mx + 1;
		}
		else{
			if (!two)
				nodes[ind].count = mx;
			else
				nodes[ind].count = mx + 1;	
		}
		
	}

}



int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n;
		string tokens;
		cin >> n;
		cin >> tokens;
		vector<node> nodes(n);
		vector<vector<int>> adj(n);
		forn(i, n){
			if (ret_num(tokens[i]))
				nodes[i].token_there = true;
			else
				nodes[i].token_there = false;
		}
		
		forsn(i, 1, n - 1){
			int p;
			cin >> p;
			--p;
			// nodes[i].parent = p;
			adj[p].push_back(i);
		}
		moves = 0;
		// depth_init(nodes, adj, 0);
		// forn(i, n){
		// 	sort(adj[i].begin(), adj[i].end(), func);
		// }
		dfs(nodes, adj, 0);
		cout << moves << bline;
	}
	return 0;
}