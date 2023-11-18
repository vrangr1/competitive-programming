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


bool check(int st1, int end1, int st2, int end2){
	if ( (st2 > st1 && st2 < end1) || () )
}


bool overlap(map<int, int> &mp, int st, int end){
	// map<int,int>::iterator itr = mp.begin();
	for (auto itr : mp){

	}
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n, k, f;
		cin >> n >> k >> f;
		map<int, int> mp;
		for (int i = 0; i < n; ++i){
			int a, b;
			cin >> a >> b;
			if (a > b)
				swap(a, b);
			if (overlap(mp, a, b)){

			}
		}
	}
	return 0;
}