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
	int height;
	bool token_there;
	int fill_depth;
	int parent;
	int depth;
}node;


inline int ret_num(char ch){
	return (int)(ch - '0');
}



bool func(const pair<int, int> &a, const pair<int, int> &b){
	return a.second > b.second;
}


void depth_init(vector<node> &nodes, vector<vector<pair<int, int>>> &adj, int ind){
	if (nodes[ind].parent != -1){
		nodes[ind].height = nodes[nodes[ind].parent].height + 1;
	}
	int n = adj[ind].size();
	int d = 0;
	forn(i, n){
		depth_init(nodes, adj, adj[ind][i].first);
		adj[ind][i].second = nodes[adj[ind][i].first].depth;
		d = max(d, nodes[adj[ind][i].first].depth);
	}
	if (n == 0){
		if (nodes[ind].token_there)
			nodes[ind].depth = 1;
		else
			nodes[ind].depth = 0;
	}
	else{
		if (nodes[ind].token_there){
			nodes[ind].depth = d + 1;
		}
		else
			nodes[ind].depth = d;
	}

}


void dfs(vector<node> &nodes, vector<vector<pair<int,int>>> &adj, int ind){
	if (nodes[ind].token_there){
		if (nodes[ind].parent != -1){
			if (nodes[ind].height - 1 > nodes[nodes[ind].parent].fill_depth){
				// cout << "ind: " << ind << bline;
				moves = moves + (abs(nodes[ind].height - nodes[nodes[ind].parent].fill_depth) - 1);
				nodes[ind].fill_depth = nodes[nodes[ind].parent].fill_depth + 1;
			}
			else{
				nodes[ind].fill_depth = nodes[nodes[ind].parent].fill_depth + 1;
			}
		}
	}
	else{
		if (nodes[ind].parent != -1){
			nodes[ind].fill_depth = nodes[nodes[ind].parent].fill_depth;
		}
	}

	int n = adj[ind].size();
	forn(i, n){
		nodes[adj[ind][i].first].height = nodes[ind].height + 1;
		dfs(nodes, adj, adj[ind][i].first);
		nodes[ind].fill_depth = min(nodes[ind].height, nodes[adj[ind][i].first].fill_depth);
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
		vector<vector<pair<int,int>>> adj(n);
		forn(i, n){
			if (ret_num(tokens[i]))
				nodes[i].token_there = true;
			else
				nodes[i].token_there = false;
		}
		nodes[0].parent = -1;
		if (nodes[0].token_there)
			nodes[0].fill_depth = 1;
		else
			nodes[0].fill_depth = 0;
		nodes[0].height = 1;
		forsn(i, 1, n - 1){
			int p;
			cin >> p;
			--p;
			nodes[i].parent = p;
			adj[p].push_back({i,-1});
		}
		moves = 0;
		depth_init(nodes, adj, 0);
		forn(i, n){
			sort(adj[i].begin(), adj[i].end(), func);
		}
		dfs(nodes, adj, 0);
		cout << moves << bline;
	}
	return 0;
}