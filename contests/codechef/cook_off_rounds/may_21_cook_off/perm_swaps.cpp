/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < (int)n; i++)

typedef long long int ll;


void dfs(vector<int> &perm, vector<bool> &vis, int ind, vector<int> &cycle){
	vis[ind] = true;
	cycle.push_back(perm[ind]);
	ind = perm[ind];
	if (!vis[ind])
		dfs(perm, vis, ind, cycle);
}


void print(vector<int> &arr){
	cout << "print: ";
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << bline;
}


void print(vector<vector<int>> &loc){
	cout << "pcycle: " << bline;
	forn(i, loc.size()){
		cout << "i: " << i << bline;
		forn(j, loc[i].size()){
			cout << "j: " << loc[i][j] << bline;
		}
	}
}


void print(vector<pair<int, int>> &loc){
	cout << "loc: " << bline;
	forn(i, loc.size()){
		cout << "i: " << i << bline << loc[i].first << ", " << loc[i].second << bline;
	}
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int temp;
		vector<int> arr(n), perm(n);
		forn(i, n)
			cin >> arr[i];
		forn(i, n){
			cin >> temp;
			perm[i] = temp - 1;
		}
		int q;
		cin >> q;
		vector<vector<int>> pcycle(n);
		vector<bool> visited(n, false);
		for (int i = 0; i < n; ++i){
			if (!visited[i]){
				dfs(perm, visited, i, pcycle[i]);
			}
		}
		vector<pair<int, int>> loc(n);
		forn(i, n){
			forn(j, pcycle[i].size()){
				int x = pcycle[i][j];
				loc[x] = {i, j};
			}
		}
		// print(pcycle);
		// print(loc);
		int ct = 0, len;
		while(q--){
			int type;
			cin >> type;
			switch(type){
				case 1:
					ct++;
					break;
				case 2:
					int x, y;
					cin >> x >> y;
					x--;
					y--;
					// cout << "x: " << x << bline << "y: " << y << bline;
					// cout << "ct: " << ct << bline;
					int orx, ory;
					orx = loc[x].second;
					// cout << "orx b4 trans: " << orx << bline;
					len = pcycle[loc[x].first].size();
					// cout << "len: " << len << bline;
					orx = (((orx - ct) % len) + len) % len;
					orx = pcycle[loc[x].first][orx];
					// cout << "orx: " << orx << bline;
					ory = loc[y].second;
					// cout << "ory b4 trans: " << ory << bline;
					len = pcycle[loc[y].first].size();
					// cout << "len: " << len << bline;
					ory = (((ory - ct) % len) + len) % len;
					// cout << "ory: " << ory << bline;
					ory = pcycle[loc[y].first][ory];
					// print(arr);
					swap(arr[orx], arr[ory]);
					// print(arr);
					break;
				case 3:
					int ind;
					cin >> ind;
					ind--;
					int orind;
					orind = loc[ind].second;
					len = pcycle[loc[ind].first].size();
					orind = (((orind - ct) % len) + len) % len;
					orind = pcycle[loc[ind].first][orind];
					cout << arr[orind] << bline;
					break;
			}
		}

	}

	return 0;
}