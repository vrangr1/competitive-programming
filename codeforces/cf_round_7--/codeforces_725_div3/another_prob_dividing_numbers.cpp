/***************************************************
* AUTHOR : Anav Prasad
* Nick : graworth
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define pb(a) push_back(a)
#define pass (void)0
typedef long long int ll;
template <typename type> void print(vector<vector<type>> &arr);
template <typename type> void print(vector<type> &arr);
//#define print_var(x) printf("%s=%s\n", #x, STR(x))
//#define print_var(x) cout << #x << ": " << STR(x) << "\n";
#define MAXN 1000000000


inline int power(int a, int b){
	double ans = pow(a, b) + 0.2;
	return (int)ans;
}


vector<pair<int,int>> prime_factors(int n)
{
    vector<pair<int,int>> ans;
    bool chk = false;
    int ct = 0;
    int len = 0;
    while (n % 2 == 0)
    {	
    	if (!chk){
    		ans.push_back({2,0});
    		chk = true;
    		len++;
    	}
    	ans[len-1].second++;
        // cout << 2 << " ";
        n = n/2;
    }
 	
 	for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        chk = false;
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            if (!chk){
            	ans.push_back({i,0});
            	chk = true;
            	len++;
            }
            ans[len-1].second++;
            // cout << i << " ";
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2){
    	ans.push_back({n,1});
        // cout << n << " ";
    }
    return ans;
}


// void sieve()
// {
//     spf[1] = 1;
//     for (int i=2; i<MAXN; i++)
 
//         // marking smallest prime factor for every
//         // number to be itself.
//         spf[i] = i;
 
//     // separately marking spf for every even
//     // number as 2
//     for (int i=4; i<MAXN; i+=2)
//         spf[i] = 2;
 
//     for (int i=3; i*i<MAXN; i++)
//     {
//         // checking if i is prime
//         if (spf[i] == i)
//         {
//             // marking SPF for all numbers divisible by i
//             for (int j=i*i; j<MAXN; j+=i)
 
//                 // marking spf[j] if it is not
//                 // previously marked
//                 if (spf[j]==j)
//                     spf[j] = i;
//         }
//     }
// }
 
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
	cin >> T;
	// sieve();
	while(T--){
		int a, b, k;
		cin >> a >> b >> k;
		string yes = "YES", no = "NO";
		if (a == b){
			if (k == 0)
				cout << yes << bline;
			else
				cout << no << bline;
			continue;
		}
		int gcd = __gcd(a, b);
		if (gcd == 1){
			if (k == 2)
				cout << yes << bline;
			else if ((a == 1 || b == 1) && k == 1){
				cout << yes << bline;
			}
			else
				cout << no << bline;
			continue;
		}
		vector<pair<int,int>> gr = prime_factors(gcd);
		ll ctg = 0;
		forn(i, gr.size()){
			ctg += gr[i].second;
		}
		a /= gcd;
		b /= gcd;
		if (k == 1 && a != 1 && b!= 1){
			cout << no << bline;
			continue;
		}
		else if (k == 1){
			cout << yes << bline;
			continue;
		}
		vector<pair<int,int>> ar, br;
		if (a == 1 || b == 1){
			if (a < b)
				swap(a, b);
			ar = prime_factors(a);
			int ct = 0;
			forn(i, ar.size()){
				// double cur = log(a)/log(ar[i]);
				ct += (ll)(ar[i].second);
			}
			if (ct + 2 * ctg >= k)
				cout << yes << bline;
			else
				cout << no << bline;
			continue;
		}
		ar = prime_factors(a);
		br = prime_factors(b);
		ll cta = 0, ctb = 0;
		forn(i, ar.size()){
			// double cur = log(a)/log(ar[i]);
			cta += (ll)(ar[i].second);
		}
		if (cta + 2 * ctg >= k){
			cout << yes << bline;
			continue;
		}
		forn(i, br.size()){
			// double cur = log(b)/lob(br[i]);
			ctb += (ll)(br[i].second);
		}
		if (cta + ctb + 2 * ctg >= k)
			cout << yes << bline;
		else
			cout << no << bline;
	}
	return 0;
}


template <typename type> void print(vector<vector<type>> &arr){
	cout << "2d vector: \n";
	forn(i, arr.size()){
		forn(j, arr[i].size())
			cout << arr[i][j] << " ";
		cout << bline;
	}
}


template <typename type> void print(vector<type> &arr){
	cout << "1d vector: \n";
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << bline;
}