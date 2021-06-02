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


int fst, fend;


typedef struct nodes{
	vector<int> chars;
}nodes;



inline int ret_num(char ch){
	return (int)(ch - 'A');
}


bool check(nodes &m, nodes &t){
	bool ans = true;
	forn(i, 26){
		if (t.chars[i] < m.chars[i])
			return false;
	}
	return true;
}


void reset_node(nodes &node){
	forn(i, 26)
		node.chars[i] = 0;
}


bool check_zero(nodes &node){
	forn(i, 26)
		if (node.chars[i] != 0)
			return false;
	return true;
}


void print(nodes &node){
	cout << "node: \n";
	forn(i, 26)
		cout << node.chars[i] << " ";
	cout << bline;
}


int main(){
	fastIO;
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	fst = 0;
	fend = 0;
	int mn = n + 1;
	nodes tnode, snode;
	forn(i, 26){
		tnode.chars.push_back(0);
		snode.chars.push_back(0);
	}
	vector<bool> which(26, false);
	forn(i, m){
		tnode.chars[ret_num(t[i])]++;
		which[ret_num(t[i])] = true;
	}
	int last = 0;
	forn(i, n){
		if (!which[ret_num(s[i])] && check_zero(snode)){
			last = i + 1;
			continue;
		}
		if (!check(tnode, snode)){
			snode.chars[ret_num(s[i])]++;
			continue;
		}
		if (i - last < mn){
			mn = i - last;
			fst = last;
			fend = i - 1;
		}
		if (!which[ret_num(s[i])]){
			reset_node(snode);
			last = i + 1;
			continue;
		}
		if (s[last] == s[i]){
			// while (snode.chars[ret_num(s[last])] > mnode.chars[ret_num(s[last])]){
			// 	last++;
			// 	snode.chars[ret_num(s[last - 1])]--;
			// 	// snode.chars[ret_num(s[i])]++;
			// 	// continue;
			// }
			last++;
			continue;
		}
		while (snode.chars[ret_num(s[last])] > tnode.chars[ret_num(s[last])]){
			last++;
			snode.chars[ret_num(s[last - 1])]--;
			// snode.chars[ret_num(s[i])]++;
			// continue;
		}
		snode.chars[ret_num(s[i])]++;
	}
	// print(tnode);
	// print(snode);

	if (check(tnode, snode)){
		// cout <<"here?\n";
		// cout << "last: " << last << bline;
		while (snode.chars[ret_num(s[last])] > tnode.chars[ret_num(s[last])]){
			last++;
			snode.chars[ret_num(s[last - 1])]--;
			// snode.chars[ret_num(s[i])]++;
			// continue;
		}
		if (mn >= n - last){
			mn = n - last;
			fst = last;
			fend = n - 1;
		}
	}
	
	assert(mn != n + 1);
	// cout <<"fst: " << fst << ", fend: " << fend << bline;
	cout << s.substr(fst, fend + 1);
	return 0;
}	