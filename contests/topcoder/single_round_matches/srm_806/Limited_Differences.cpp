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

class LimitedDifferences{
public:
	vector<int> arrange(int N, int V){
		vector<int> ans;
		if (V > N - 1 || V < 0)
			return ans;
		int i = 1, j = N - 1;
		bool pos = true;
		if (N == 2 && V == 0)
			return ans;
		ans.push_back(N);
		if (N % 2 == 1 && V == N - 2){
			i = 2;
			while (V){
				if (pos){
					ans.push_back(i);
					++i;
				}
				else{
					ans.push_back(j);
					--j;
				}
				pos = !pos;
				V--;
			}
			ans.push_back(1);
			return ans;

		}
		while (V){
			if (pos){
				ans.push_back(i);
				++i;
			}
			else{
				ans.push_back(j);
				--j;
			}
			pos = !pos;
			V--;
		}
		if (i > j)
			return ans;
		if (i != j){
			int diff = 1;
			int st = i, comp = j;
			if (pos){
				diff = -1;
				st = j;
				comp = i;
			}
			int k;
			for(k = st; k != comp; k += diff)
				ans.push_back(k);
			ans.push_back(k);
		}
		return ans;
	}
};


int main(){
	fastIO;
	int n, v;
	LimitedDifferences obj;
	cin >> n >> v;
	vector<int> arr = obj.arrange(n, v);
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << bline;
	return 0;
}