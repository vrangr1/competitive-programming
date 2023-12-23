/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
// #define mod 1e9 + 7
typedef long long ll;
#define INF 1000000007 
ll power(ll y)  
{  
    ll x = 2;
    ll res = 1;     // Initialize result  
  
    x = x % INF; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % INF;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % INF;  
    }  
    return res;  
}  


 
ll f[100001]; 
  
ll pow(ll a, ll b, ll MOD) 
{ 
 ll x=1,y=a;  
 while(b > 0) 
 	{ 
 		if(b%2 == 1) 
 	{ 
 		x=(x*y); 
 		if(x>MOD) x%=MOD; 
 	} 
 	y = (y*y); 
 	if(y>MOD) y%=MOD;  
 	b /= 2; 
 	} 
 return x; 
} 
  
/* Modular Multiplicative Inverse 
 Using Euler's Theorem 
 a^(phi(m)) = 1 (mod m) 
 a^(-1) = a^(m-2) (mod m) */ 
ll InverseEuler(ll n, ll MOD) 
{ 
 return pow(n,MOD-2,MOD); 
} 
  
ll ncr(ll n, ll r) 
{ 
  ll MOD = INF;
 return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD; 
}



void subsct(vector<pair<int,int>> &a, int n){
	vector<ll> ans(n);

	for(int i = 0; i < n; ++i){
		if (i <= 2){
			ans[a[i].second] = power(n-1) - 1;
		}
		else{
			// cout << "ncr: " << ncr(i-1, 1) << " " << ncr(i-1, 2) << endl;
			ans[a[i].second] = (  (  ((power(n-i-1) - 1) % INF) * ((ncr(i, 1) + ncr(i, 2) + 1) % INF)  )%INF +    ( ncr(i, 1) + ncr(i, 2))%INF )% INF;
		}
	}
	for(int i = 0; i < n-1; ++i){
		cout << ans[i] << " ";
	}
	cout << ans[n-1] << endl;
}

bool great(const pair<int,int> &a, const pair<int,int> &b){
	return (a.first > b.first);
}

int main(){
	int T;
	cin >> T;
	int N, temp;
	vector<pair<int,int>> a;
	f[0] = 1;
	for(int i = 1 ; i <= 100000 ; i++) 
		f[i] = (f[i-1]*i)%INF;
	while(T--){
		cin >> N;
		a.clear();
		for(int i = 0; i < N; ++i){
			cin >> temp;
			a.push_back(make_pair(temp, i));
		}
		sort(a.begin(), a.end(), great );
		// cout << "a\n";
		// for(int i = 0; i < N; ++i){
		// 	cout << a[i].first << " " << a[i].second << endl;
		// }
		// for(int i = 0; i < N; ++i){
		subsct(a, N);
	}
	
	return 0;
}