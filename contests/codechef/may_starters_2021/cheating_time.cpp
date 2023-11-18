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













// Structure to represent an interval
struct Interval
{
    int low, high;
};
  
// Structure to represent a node in Interval Search Tree
struct ITNode
{
    Interval *i;  // 'i' could also be a normal variable
    int max;
    ITNode *left, *right;
    ITNode *parent;
};
  
// A utility function to create a new Interval Search Tree Node
ITNode * newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
    temp->parent = NULL;
    return temp;
};
  
// A utility function to insert a new Interval Search Tree Node
// This is similar to BST Insert.  Here the low value of interval
// is used tomaintain BST property
ITNode *insert(ITNode *root, Interval i, ITNode *prev)
{
    // Base case: Tree is empty, new node becomes root
    if (root == NULL)
        return newNode(i);
  
    // Get low value of interval at root
    int l = root->i->low;
  
    // If root's low value is smaller, then new interval goes to
    // left subtree
    if (i.low < l){
        root->left = insert(root->left, i, root);
    }
  
    // Else, new node goes to right subtree.
    else{
        root->right = insert(root->right, i, root);
    }
  	root->parent = prev;
    // Update the max value of this ancestor if needed
    if (root->max < i.high)
        root->max = i.high;
  
    return root;
}
  
// A utility function to check if given two intervals overlap
bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low < i2.high && i2.low < i1.high)
        return true;
    return false;
}
  
// The main function that searches a given interval i in a given
// Interval Tree.
Interval *overlapSearch(ITNode *root, Interval i)
{
    // Base Case, tree is empty
    if (root == NULL) return NULL;
  
    // If given interval overlaps with root
    if (doOVerlap(*(root->i), i))
        return root->i;
  
    // If left child of root is present and max of left child is
    // greater than or equal to given interval, then i may
    // overlap with an interval is left subtree
    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);
  
    // Else interval can only overlap with right subtree
    return overlapSearch(root->right, i);
}


ITNode* overlapSearch_node(ITNode *root, Interval i){
	// Base Case, tree is empty
    if (root == NULL) return NULL;
  
    // If given interval overlaps with root
    if (doOVerlap(*(root->i), i))
        return root;
  
    // If left child of root is present and max of left child is
    // greater than or equal to given interval, then i may
    // overlap with an interval is left subtree
    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch_node(root->left, i);
  
    // Else interval can only overlap with right subtree
    return overlapSearch_node(root->right, i);
}



void reloadTree(ITNode *root, ITNode *cur){
        if (cur->left != NULL)
            reloadTree(root, cur->left);
        if (cur->right != NULL)
            reloadTree(root, cur->right);
        else
            root = insert(root, cur->i, NULL);
}



bool delete_node(ITNode *root, Interval node){
        ITNode *res = overlapSearch_node(root, node);

        // If no overlap
        if (res == NULL)
            return false;

        
        if (res->left != NULL || res->right != NULL){
        	if (res->left != NULL){
        		if (res->parent->left->i->low == res->i->low &&res->parent->left->i->high == res->i->high)
        			res->parent->left = res->left;
        		else
        			res->parent->right = res->left;
        		reloadTree(root, res->right);
        	}
        	else{
        		if (res->parent->left->i->low == res->i->low && res->parent->left->i->high = res->i->high)
        			res->parent->left = res->right;
        		else
        			res->parent->right = res->right;

        	}
        }
        else{
        	if (res->parent->left->i->low == res->i->low && res->parent->left->i->high == res->i->high)
                res->parent->left = NULL;
            if (res->parent->right->i->low == res->i->low && res->parent->right->i->high == res->i->high)
                res->parent->right = NULL;
            return True
        }

}









void inorder(ITNode *root, ll &tot)
{
    if (root == NULL) return;
  
    inorder(root->left, tot);
  	tot += root->i->high - root->i->low;
    // cout << "[" << root->i->low << ", " << root->i->high << "]"
    //      << " max = " << root->max << endl;
  
    inorder(root->right, tot);
}
 






















int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n, k, f;
		cin >> n >> k >> f;
		// vector<vector<int>> inv(n, vector<int> (2));
		ITNode *root = NULL;
		Interval in;
		Interval *res;
		int t1, t2;
		for (int i = 0; i < n; ++i){
			// cin >> inv[i][0] >> inv[i][1];
			cin >> t1 >> t2;
			if (t1 > t2)
				swap(t1, t2);
			in.low = t1;
			in.high = t2;
			res = overlapSearch(root, in);
			if (res == NULL){
				root = insert(root, in, NULL);
			}
			else{
				in.low = (res->low <= in.low? res->low: in.low);
				in.high = (res->high >= in.high ? res->high: in.high);
				delete_node(root, res->i);

				root = insert(root, in, NULL);
				// res->low = (res->low <= in.low? res->low: in.low);
				// res->high = (res->high >= in.high ? res->high: in.high);
			}
		}
		ll ans = 0;
		inorder(root, ans);
		if (f - ans >= k)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}