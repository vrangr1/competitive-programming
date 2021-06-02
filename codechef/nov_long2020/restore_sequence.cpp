/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"

typedef long long int lli;

typedef struct tree{
	int value;
	int index;
	vector<struct tree*> children;
	struct tree *parent;
} tree;

bool is_leaf(tree node);

void prime_generator(vector<bool> &pno, vector<int> &pns);

int prime_call(vector<bool> &pno, int ind);

void assign_values(tree *node, vector<int> &pns, int *pind, pair<int,int> &glob);

void disp_tree(vector<tree> &node, int n){
	for(int i = 0; i < n; ++i){
		cout << "index: " << node[i].index << bline;
		cout << "value: " << node[i].value << bline;
		cout << "children_count: " << node[i].children.size() << bline;
		if(node[i].parent != nullptr)
		cout << "parent_ind " << node[i].parent->index << bline << bline;
		else
			cout << "no parent\n\n";
	}
}

int main(){
	int T;
	cin >> T;
	int n, temp, p_ind, n2;
	vector<int> ans, tree_ct, pns;
	vector<bool> pno(1e5);
	prime_generator(pno, pns);
	pno.clear();
	cout << "pns: " << pns.size() << bline;
	// for(int i = 0; i < 100; ++i){
	// 	cout << prime_call(pno, i+1) << " ";
	// }
	while(T--){
		cin >> n;
		ans.clear();
		p_ind = 0;
		vector<tree> node(n);
		for(int i = 0; i < n; ++i){
			node[i].index = i;
			node[i].children.clear();
			node[i].parent = nullptr;
			node[i].value = -1;
		}
		tree_ct.clear();
		for(int i = 0; i < n; ++i){
			cin >> temp;
			if(temp -1 != i){
				node[i].parent = &node[temp-1];
				node[temp-1].children.push_back(&node[i]);
			}
			else{
				node[i].parent = nullptr;
				tree_ct.push_back(i);
			}
		}
		
		// for(int i = 0; i < n; ++i){
		// 	if (node[i].parent == nullptr){
				
		// 	}
		// }
		n2 = tree_ct.size();
		

		// disp_tree(node, n);
		// cout << "n2: " << n2 << bline;
		// for(int i = 0; i < n2; ++i){
		// 	cout << tree_ct[i] << " ";
		// }
		// cout << bline;
		pair<int,int> glob;
		glob = make_pair(-1,-1);
		for(int i = 0; i < n2; ++i){
			assign_values(&node[tree_ct[i]], pns, &p_ind, glob);
		}
		for(int i = 0; i < n; ++i){
			cout << node[i].value << " ";
		}
		cout << bline;
	}
	return 0;
}



bool is_leaf(tree *node){
	int n = node->children.size();
	if (n == 0)
		return true;
	return false;
}

void prime_generator(vector<bool> &pno, vector<int> &pns){
	int n = pno.size();
	// memset(pno, true, n);
	for(int i = 0; i < n; ++i)
		pno[i] = true;
	pno[0] = false;
	pno[1] = false;
	for(int i = 2; i*i <= n; ++i)
		if (pno[i])
			for (int j = i*2; j <= n; j+= i)
				pno[j] = false;
	for(int i = 2; i < n; ++i){
		if(pno[i])
			pns.push_back(i);
	}
}

int prime_call(vector<bool> &pno, int ind){
	int ct = 0;
	int n = pno.size();
	for(int i = 2; i < n; i++){
		if (pno[i])
			ct++;
		if (ct == ind)
			return i;
	}
	return -1;
}

void assign_values(tree *node, vector<int> &pns, int *pind, pair<int,int> &glob){
	// tree *node;
	// int count = 0;
	if(node->value != -1)
		return;
	if (node->children.size() == 0){
		if(glob.second > node->index){
			node->value = glob.first;
		}
		else{
			glob->first = pns[*pind];
			(node->parent == nullptr) ? (glob.second = node->index) : (glob.second = node->parent->index);
			node->value = pns[*pind];
			*pind = *pind + 1;
		}
		return;
	}
	int n = node->children.size();
	int val = 1;
	for (int i = 0; i < n; ++i){
		assign_values(node->children[i], pns, pind);
		val *= node->children[i]->value;
	}
	node->value = val;
	
}	
