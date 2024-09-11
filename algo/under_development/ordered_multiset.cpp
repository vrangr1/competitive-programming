/*
Details for snippet generator program:
title       : Ordered Multi-Set via GNU PBDS
prefix      : import_omset
description : Ordered Set via GNU PBDS
*/
#ifndef ORDERED_SET_SNIPPET
#define ORDERED_SET_SNIPPET
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// template <typename type>
// using ordered_set = tree<type,null_type,std::less<type>,rb_tree_tag,tree_order_statistics_node_update>;

template<typename Key, typename Mapped, typename Cmp_Fn = std::less<Key>,
	   typename Tag = rb_tree_tag,
	   template<typename Node_CItr, typename Node_Itr,
		    typename Cmp_Fn_, typename _Alloc_>
	   class Node_Update = null_node_update,
	   typename _Alloc = std::allocator<char> >
class ordered_multiset : public tree<Key, Mapped, Cmp_Fn, Tag, Node_Update, _Alloc> {
public:
	void minsert(Key x) {
		this->insert(x);
	}

	bool mexist(Key x) {
		if (this->upper_bound(x) == this->end()) {
			return false;
		}
		return *(this->upper_bound(x)) == x;
	}

	void merase(Key x) {
		if (this->mexist(x)) this->erase(this->upper_bound(x));
	}

	int first_idx(Key x) {
		if (!this->mexist(x)) return -1;
		return this->order_of_key(x);
	}

	Key mvalue(int idx) {
		return *(this->find_by_order(idx));
	}

	int last_idx(Key x) {
		if (!this->mexist(x)) return -1;
		if (this->mvalue(int(this->size())-1) == x)
			return int(this->size()-1);
		return this->first_idx(*(this->lower_bound(x))-1);
	}

	int count(Key x) {
		if (!this->mexist(x))
			return 0;
		return last_idx(x) - first_idx(x) + 1;
	}
};

template<typename type>
using ordered_mset = ordered_multiset<type, null_type, std::less_equal<type>, rb_tree_tag, tree_order_statistics_node_update>;

// template <typename type>
// using ordered_mset = ordered_multiset<type, null_type, std::less<type>, rb_tree_tag, tree_order_statistics_node_update>;

// int Count(ordered_set &s,int x){ //this function returns the number of occurrences of the value (x).

//      if(!Exist(s,x)){
//         return 0;
//      }
//      return LastIdx(s,x)-FirstIdx(s,x)+1;

// }


// void Clear(ordered_set &s){ //this function clears all the elements from the set.

//      s.clear();

// }


// int Size(ordered_set &s){ //this function returns the size of the set.

//      return (int)(s.size());

// }



// int main(){


//      /*

//      *Please read the above functions and their descriptions.

//      *If you want to change your multi ordered set data type,you should change almost everything in the above functions.

//      */



//      return 0;

// }

#endif

int main() {
    // ordered_mset<int> omset;
    // omset.insert(1);
    // omset.insert(2);
    // return 0;
}