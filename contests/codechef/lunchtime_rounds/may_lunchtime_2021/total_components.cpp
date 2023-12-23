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

#define maxn 10000001

vector<bool> prime(maxn, 1);
vector<pair<int, int>> ct(maxn);

 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve(){
	// bool prime[n + 1];
    // memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p < maxn; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i < maxn; i += p)
                prime[i] = false;
        }
    }
    ct[0].first = 0;
    ct[0].second = 0;
    ct[1].first = 0;
    ct[1].second = 0;
    ct[2].first = 1;
    ct[2].second = 0;
    for(int i = 3; i < maxn; ++i){
    	if (prime[i]){
    		ct[i].first = ct[i-1].first + 1;
    		ct[i].second = ct[i/2].first;
    		continue;
    	}
    	ct[i].first = ct[i-1].first;
    	ct[i].second = ct[i/2].first;
    }

}
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
// vector<int> getFactorization(int x)
// {
//     vector<int> ret;
//     while (x != 1)
//     {
//         ret.push_back(spf[x]);
//         x = x / spf[x];
//     }
//     return ret;
// }



int main(){
	fastIO;
	int T;
	sieve();
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if (ct[n].second > 0)
		cout << ct[n].first - ct[n].second + 1 << bline;
		else
			cout << ct[n].first << bline;
	}
	return 0;
}