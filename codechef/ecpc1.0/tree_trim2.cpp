/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

struct node{
	int value;
	vector<struct node *> children;
	struct node *parent;
};
typedef struct node node;


void add_edge(vector<node> &tree, int a, int b){
	(tree[a].children).push_back(&tree[b]);
	tree[b].parent = &tree[a];
}

void trim(vector<node> &tree, int index){
	// int index = 0;
	// int n = (tree[index].children).size();
	// while(true){
	// 	if(n == 0){
	// 		if(tree[index].parent != nullptr){
	// 			index = tree[index].parent->value;
	// 			n = (tree[index].children).size();
	// 			if(n < 3){

	// 			}
	// 			if(n%3 == 0){
	// 				tree[index].children.clear();
	// 			}
	// 			else if(n % 3 == 1){
	// 				tree[index].children.erase(tree[index].children.begin(),tree[index].children.end() - 1);
	// 			}
	// 			else{
	// 				tree[index].children.erase(tree[index].children.begin(),tree[index].children.end() - 2);
	// 			}

	// 		}
	// 	}
	// 	else{

	// 	}
	// }
	int n = tree[index].children.size();
	if(n == 0){
		index = tree[index].parent->value;
		n = tree[index].children.size();
		if(n >= 3){
			if(n%3 == 0){
				tree[index].children.clear();
			}
			else if(n % 3 == 1){
				tree[index].children.erase(tree[index].children.begin(),tree[index].children.end() - 1);
			}
			else{
				tree[index].children.erase(tree[index].children.begin(),tree[index].children.end() - 2);
			}
		}
		return;
	}
	for(int i = 0; i < n; ++i){
		trim(tree, tree[index].children[i]->value);
	}
}


void dfs(vector<node> &tree, int index, int &count){
	count++;
	int n = tree[index].children.size();
	for(int i = 0; i < n; ++i){
		dfs(tree, tree[index].children[i]->value, count);
	}
}

void disp(vector<node> &tree, int index){
	cout << tree[index].value << endl;
	int n = tree[index].children.size();
	for(int i = 0; i < n; ++i){
		disp(tree, tree[index].children[i]->value);
	}

}

int main(){
	int T;
	cin >> T;
	int n, temp;
	while(T--){
		cin >> n;
		vector<node> tree(n);
		for(int i = 0; i < n; ++i){
			tree[i].value = i;
			tree[i].parent = nullptr;
		}
		for(int i = 0; i < n-1; ++i){
			cin >> temp;
			add_edge(tree, temp - 1, i+1);
		}
		disp(tree, 0);
		trim(tree, 0);
		disp(tree, 0);
		int count = 0;
		dfs(tree, 0, count);
		cout << count <<endl;
	}
	
	return 0;
}