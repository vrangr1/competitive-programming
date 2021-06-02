/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;


int pr_check(lli k){
	int ans = 0;
	while(k){
		++ans;
		k = k >> 1;
	}
	return ans;
}

struct node{
	int value;
	int index;
	vector<struct node*> children;
	struct node *parent;
};

typedef struct node node;

bool dfs(vector<node> &tree, int index, int pr){
	bool ans = true;
	if(tree[index].value > pr){
		ans = false;
		return ans;
	}
	int n = tree[index].children.size();
	for(int i = 0; i < n; ++i){
		ans = dfs(tree, tree[index].children[i]->index, pr);
		if (ans){
			return true;
		}
	}
	return ans;
}


bool check_path(vector<node> &tree, vector<int> &i2, int pr){
	bool ch = true, lesser = true, ans = false;
	int ind, n = i2.size();
	
	for(int i = 0; i < n; ++i){
		ind = i2[i];
		lesser = true;
		ch = true;
		while(tree[ind].parent != nullptr){
			ind = tree[ind].parent->index;
			if(tree[ind].value > pr){
				ch = false;
				break;
			}
			// else if (tree[ind].value == pr){
			// 	lesser = false;
			// }
		}
		if(!ch){
			ans = false;
			continue;
		}
		ind = i2[i];
		ans = dfs(tree, ind, pr);
		if (ans){
			return true;
		}
	}
	return false;

}



int main(){
	int T;
	cin >> T;
	int n, u, v, temp, pr, n2;
	vector<int> index;
	bool check;
	lli k;
	while(T--){
		cin >> n >> k;
		pr = pr_check(k);
		// cout << "pr " << pr << endl;
		vector<node> tree(n);
		index.clear();
		for(int i = 0; i < n; ++i){
			tree[i].index = i;
			tree[i].parent = nullptr;
		}
		for(int i = 0 ; i < n -1 ; ++i){
			cin >> u >> v;
			tree[u - 1].children.push_back(&tree[v-1]);
			tree[v-1].parent = &tree[u-1];
		}
		check = false;
		for(int i = 0; i < n; ++i){
			cin >> temp;
			tree[i].value = temp;
			if(temp == pr){
				check = true;
				index.push_back(i);
			}
		}

		if(!check){
			cout << "NO\n";
			continue;
		}
		n2 = index.size();
		// cout << "n2 " << n2 << endl;
		// for(int i = 0; i < n2; ++i){
		// 	cout << index[i] << " ";
		// }
		// cout << endl;
		check = check_path(tree, index, pr);
		if (check){
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
	
	return 0;
}