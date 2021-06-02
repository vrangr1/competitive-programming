/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, j, n) for (int i = j; j < n; ++i)

typedef long long int ll;


inline int loc(int i, int j, int n){
	return (i * n + j)
}


inline int mirror(int &i, int &j, int n){
	int temp = i;
	i = j;
	j = i;
}


class TransposeColors{
public:
	vector<int> move(int N){
		vector<int> ans;
		int i = N - 1, j = 0;
		if (N == 1)
			return ans;
		int ex = N * N;
		vector<vector<bool>> chk(N, vector<bool> (N, false));
		forn(i, N)
			chk[i][i] = true;
		vector<int> ind(N, 0);
		int i = 0, j = 0;
		while(i < N && j < N){
			if (chk[i][j] && i < N - 1){
				i++;
				continue;
			}
			else if(chk[i][j] && )
		}
		ans.push_back()
	}
};


int main(){
	//fastIO;
	int T;
	cin >> T;

	return 0;
}