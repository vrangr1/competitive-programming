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


bool wh_edge2(int ind, int n, bool dir = true){
	if (dir)
	return (ind <= (n - ind - 1));
	return (ind < (n - ind - 1));
}


bool wh_edge(int ind, int n, bool &both){
	if (ind != (n - ind - 1))
		return (ind < (n - ind - 1));
	both = true;
	return true;
}


int calc_dist(int ind, int m, bool fr){
	if (fr){
		return ind + 1;
	}
	return m - ind;
}


int solve(int n, int m, int st, int end, vector<int> q, bool dir){
	// vector<int> q(m);
	// cout << "st: " << st << ", end: " << end << bline;
	if (m == 1){
		if (n == 1)
			return 1;
		return -1;
		// int qr;
		// cin >> qr;
		// cout << 1 << bline;
		// continue;
	}
	bool fr = false, bk = false;
	vector<pair<int, bool>> loc(n, {-1, true});
	for (int i = st; i <= end; ++i){
		// cin >> q[i];
		int cur = q[i] - 1;
		if (loc[cur].first == -1){
			loc[cur].second = wh_edge2(i, m, dir);
			loc[cur].first = calc_dist(i, m, loc[cur].second);
		}
		else{
			bool ed = wh_edge2(i, m, dir);
			int dt = calc_dist(i, m, ed);
			if (dt < loc[cur].first){
				loc[cur].first = dt;
				loc[cur].second = ed;
			}
		}
	}
	int fd = 0, ed = 0;
	bool mid = false;
	bool pos = true;
	for (int i = 0; i < n; ++i){
		if (loc[i].first == -1)
			return -1;
		if (loc[i].second){
			if (fd < loc[i].first){
				fd = loc[i].first;
			}
			fr = true;
		}
		else{
			if (ed < loc[i].first)
				ed = loc[i].first;
			bk = true;
		}
	}
	if (fd != 0 && ed != 0)
		cout << "PROBLEM!!!!";
	return fd + ed;
}



void whittle(int &fd, int &ed, vector<int> q, int m, int n){
	vector<bool> there(n, false);
	if (fd >= ed){
		for (int i = fd - 1; i >= 0; --i){
			there[q[i] - 1] = true;
		}
		while(ed > 0 && there[q[m - ed] - 1]){
			ed--;
		}
		return;
	}
	for (int i = m - ed; i < m; ++i){
		there[q[i] - 1] = true;
	}
	while(fd > 0 && there[q[fd - 1] - 1])
		fd--;
}



int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;
		vector<int> q(m);
		if (m == 1){
			int qr;
			cin >> qr;
			cout << 1 << bline;
			continue;
		}
		bool fr = false, bk = false;
		vector<pair<int, bool>> loc(n, {-1, true});
		forn(i, m)
			cin >> q[i];
		int ans = solve(n, m, 0, (m % 2? m/2: m/2 - 1), q, true);
		if (ans == -1)
			ans = solve(n, m, (m % 2? m/2: m/2 + 1), m - 1, q, false);
		else{
			int temp = solve(n, m, (m % 2? m/2: m/2 + 1), m - 1, q, false);
			if (temp < ans)
				ans = temp;
		}
		// bool both = false;
		vector<bool> both(n, false);
		for (int i = 0; i < m; ++i){
			// cin >> q[i];
			// both = false;
			int cur = q[i] - 1;
			if (loc[cur].first == -1){
				bool rp;
				loc[cur].second = wh_edge(i, m, rp);
				loc[cur].first = calc_dist(i, m, loc[cur].second);
			}
			else{
				bool tp = false;
				bool ed = wh_edge(i, m, tp);
				int dt = calc_dist(i, m, ed);
				if (dt < loc[cur].first){
					loc[cur].first = dt;
					loc[cur].second = ed;
				}
				else if (dt == loc[cur].first)
					both[cur] = true;
			}
		}
		int fd = 0, ed = 0;
		bool mid = false;
		for (int i = 0; i < n; ++i){
			if (m % 2 == 1 && loc[i].first == m / 2){
				mid = true;
			}
			else{
				if (!both[i]){
					if (loc[i].second){
						if (fd < loc[i].first){
							fd = loc[i].first;
						}
						fr = true;
					}
					else{
						if (ed < loc[i].first)
							ed = loc[i].first;
						bk = true;
					}
				}
			}
		}
		forn(i, n){
			if (m % 2 == 1 && loc[i].first == m / 2){
				mid = true;
			}
			else{
				if (both[i]){
					if (loc[i].first >= fd && loc[i].first >= ed){
						if (fd >= ed){
							fd = loc[i].first;
							fr = true;
						}
						else{
							ed = loc[i].first;
							bk = true;
						}
					}
				}
			}
		}
		if (mid){
			if (fr){
				fd = m / 2 + 1;
			}
			else if (bk)
				ed = m /2 + 1;
			else{
				cout << "PROBLEM111!!\n";
			}
		}
		
		whittle(fd, ed, q, m, n);
		// cout << "for 1: " << loc[0].first << ",direction: " << loc[0].second << bline;
		// cout << "for 2: " << loc[1].first << ",direction: " << loc[1].second << bline;
		// cout << "for 3: " << loc[2].first << ",direction: " << loc[2].second << bline;
		// cout << "for 3: " << loc[3].first << ",direction: " << loc[3].second << bline;
		// cout << "fd: " << fd << ", ed: " << ed << bline;
		if (ans != -1 && ans < fd + ed){
			cout << ans << bline;
			continue;
		}
		cout << fd + ed << bline;
	}
	return 0;
}