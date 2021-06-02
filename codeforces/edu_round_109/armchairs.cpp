#include<bits/stdc++.h>

using namespace std;

inline int mn(int i, int r){
	if (i - r < 0)
		return i;
	return i - r;
}

inline int pl(int i, int r, int n){
	if (i + r >= n)
		return i;
	return i + r;
}


inline int dist(int ind, int n){
	return (ind > n - ind) ? (n - ind) : ind;
}


void exp_effect(vector<int> &arr, vector<int> &ar2, int st, int end, int &tot, int n){
	bool set = false;
	int r = 1;
	int ind = st;
	int res1, res2;
	while (!set){
		if (!arr[mn(ind, r)] && !ar2[mn(ind, r)]){
			// res1 = r;
			tot += r;
			set = true;
			ar2[mn(ind, r)] = 1;
			continue;
		}
		else if(!arr[pl(ind, r, n)] && !ar2[pl(ind, r, n)]){
			tot += r;
			// res1 = r;
			set = true;
			ar2[pl(ind, r, n)] = 1;
			continue;
		}
		++r;
	}

	set = false;
	r = 1;
	ind = end;
	while (!set){
		if (!arr[mn(ind, r)] && !ar2[mn(ind, r)]){
			tot += r;
			// res2 = r;
			set = true;
			ar2[mn(ind, r)] = 1;
			continue;
		}
		else if(!arr[pl(ind, r, n)] && !ar2[pl(ind, r, n)]){
			tot += r;
			// res2 = r;
			set = true;
			ar2[pl(ind, r, n)] = 1;
			continue;
		}
		++r;
	}
	// return res1 + res2;
}

int exp(vector<int> arr, vector<int> ar2, int st, int end, int n){
	bool set = false;
	int r = 1;
	int ind = st;
	int res1, res2;
	while (!set){
		if (!arr[mn(ind, r)] && !ar2[mn(ind, r)]){
			res1 = r;
			set = true;
			ar2[mn(ind, r)] = 1;
			continue;
		}
		else if(!arr[pl(ind, r, n)] && !ar2[pl(ind, r, n)]){
			// tot += r;
			res1 = r;
			set = true;
			ar2[pl(ind, r, n)] = 1;
			continue;
		}
		++r;
	}

	set = false;
	r = 1;
	ind = end;
	while (!set){
		if (!arr[mn(ind, r)] && !ar2[mn(ind, r)]){
			// tot += r;
			res2 = r;
			set = true;
			ar2[mn(ind, r)] = 1;
			continue;
		}
		else if(!arr[pl(ind, r, n)] && !ar2[pl(ind, r, n)]){
			// tot += r;
			res2 = r;
			set = true;
			ar2[pl(ind, r, n)] = 1;
			continue;
		}
		++r;
	}
	return res1 + res2;
}

int main(){
	int n, tot = 0;
	cin >> n;
	vector<int> arr(n), ar2(n, 0), indexes;

	for (int i = 0; i < n; ++i){
		cin >> arr[i];
		if (arr[i] == 1)
			indexes.push_back(i);
	}
	int k = indexes.size();
	if (k < 2){
		cout << k;
		return 0;
	}
	int ind;
	int r = 1, sind = 0, eind = k - 1;
	bool set = false;
	int st = indexes[sind], end = indexes[eind];
	while(st < end){
		if (dist(st, n) < dist(end, n)){
			set = false;
			r = 1;
			ind = st;
			while (!set){
				if (!arr[mn(ind, r)] && !ar2[mn(ind, r)]){
					tot += r;
					set = true;
					ar2[mn(ind, r)] = 1;
					continue;
				}
				else if(!arr[pl(ind, r, n)] && !ar2[pl(ind, r, n)]){
					tot += r;
					set = true;
					ar2[pl(ind, r, n)] = 1;
					continue;
				}
				++r;
			}
			sind++;
			st = indexes[sind];
			continue;
		}
		else if (dist(st, n) > dist(end, n)){
			set = false;
			r = 1;
			ind = end;
			while (!set){
				if (!arr[mn(ind, r)] && !ar2[mn(ind, r)]){
					tot += r;
					set = true;
					ar2[mn(ind, r)] = 1;
					continue;
				}
				else if(!arr[pl(ind, r, n)] && !ar2[pl(ind, r, n)]){
					tot += r;
					set = true;
					ar2[pl(ind, r, n)] = 1;
					continue;
				}
				++r;
			}
			eind--;
			end = indexes[eind];
			continue;
		}
		else{

			int r1 = exp(arr, ar2, st, end, n);
			int r2 = exp(arr, ar2, end, st, n);
			if (r1 < r2){
				exp_effect(arr, ar2, st, end, tot, n);
			}
			else{
				exp_effect(arr, ar2, end, st, tot, n);
			}
			sind++;
			st = indexes[sind];

			eind--;
			end = indexes[eind];
			
		}
	}
    if (st == end){
        set = false;
		r = 1;
		ind = st;
		while (!set){
			if (!arr[mn(ind, r)] && !ar2[mn(ind, r)]){
				tot += r;
				set = true;
				ar2[mn(ind, r)] = 1;
				continue;
			}
			else if(!arr[pl(ind, r, n)] && !ar2[pl(ind, r, n)]){
				tot += r;
				set = true;
				ar2[pl(ind, r, n)] = 1;
				continue;
			}
			++r;
		}
    }
	cout << tot;
	return 0;
}