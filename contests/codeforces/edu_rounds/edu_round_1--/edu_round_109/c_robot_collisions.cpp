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


bool comp(const vector<int> &a, const vector<int> &b){
	return (a[0] < b[0]);
}


inline int lr(char ch){
	return (ch == 'L'? 0 : 1);
}


void process(vector<vector<int>> arr, stack<pair<int,int>> &l, stack<pair<int,int>> &r, vector<int> &ans, int m){
	int t;
	pair<int,int> p1, p2;
	forn(i, arr.size()){
		if (arr[i][1]){
			r.push({arr[i][0], arr[i][2]});
		}
		else{
			if (r.size()){
				t = (arr[i][0] - r.top().first) / 2;
				ans[arr[i][2]] = t;
				ans[r.top().second] = t;
				r.pop();
				continue;
			}
			l.push({arr[i][0], arr[i][2]});
		}
	}
	while(r.size() > 1){
		p1 = r.top();
		r.pop();
		p2 = r.top();
		r.pop();
		t = m - ((p1.first + p2.first) / 2);
		ans[p1.second] = t;
		ans[p2.second] = t;
	}
	stack<pair<int,int>> n;
	n.swap(l);
	while(!n.empty()){
		l.push(n.top());
		n.pop();
	}
	while(l.size() > 1){
		p1 = l.top();
		l.pop();
		p2 = l.top();
		l.pop();
		t = (p1.first + p2.first)/2;
		ans[p1.second] = t;
		ans[p2.second] = t;
	}
	if (r.size() == 1 && l.size() == 1){
		t = m + ((l.top().first - r.top().first) / 2);
		ans[r.top().second] = t;
		ans[l.top().second] = t;
		r.pop();
		l.pop();
	}
}


void set_m1(stack<pair<int,int>> &stk, vector<int> &arr){
	if (stk.size())
		arr[stk.top().second] = -1;
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;
		vector<int> tot, ans(n, -1);
		vector<vector<int>> even, odd;
		int t;
		forn(i, n){
			cin >> t;
			tot.push_back(t);
		}
		forn(i, n){
			char ch;
			cin >> ch;
			if (tot[i] % 2)
				odd.push_back({tot[i], lr(ch), i});
			else
				even.push_back({tot[i], lr(ch), i});
		}
		sort(odd.begin(), odd.end(), comp);
		sort(even.begin(), even.end(), comp);
		stack<pair<int, int>> el, er, odl, odr;
		process(odd, odl, odr, ans, m);
		process(even, el, er, ans, m);
		// set_m1(odl, ans);
		// set_m1(odr, ans);
		// set_m1(el, ans);
		// set_m1(er, ans);
		forn(i, n){
			cout << ans[i] << " ";
		}
		cout << bline;

	}
	return 0;
}