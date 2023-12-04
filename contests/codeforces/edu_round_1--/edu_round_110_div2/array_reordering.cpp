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
#define pb(a) push_back(a)
typedef long long int ll;
#define maxn 100001
// vector<pair<int, int>> cnt(maxn);
bool comp(const int &a, const int &b){
	if (a%2)
		return false;
	return true;
}


void print(vector<int> arr){
	cout << "arr\n";
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << bline;
}


// int gcd(int a, int b){
// 	if (a > b){
// 		swap(a,b);
// 	}
// 	if (a == 0){
// 		return b;
// 	}

// 	return gcd(a, b % a);

// }



void sieve(vector<bool> &prime){
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
    // cnt[0].first = 0;
    // cnt[0].second = 0;
    // cnt[1].first = 0;
    // cnt[1].second = 0;
    // cnt[2].first = 1;
    // cnt[2].second = 0;
    // for(int i = 3; i < maxn; ++i){
    // 	if (prime[i]){
    // 		cnt[i].first = cnt[i-1].first + 1;
    // 		cnt[i].second = cnt[i/2].first;
    // 		continue;
    // 	}
    // 	cnt[i].first = ct[i-1].first;
    // 	cnt[i].second = ct[i/2].first;
    // }
}

bool check(int a, int b){
// bool check(int a, int b, vector<bool> &primes){
	// if (a % 2 == 0)
	// 	return true;
	// if (a == b && a == 1)
	// 	return false;
	// if (a == b)
	// 	return true;
	// if (a == 1 || b == 1)
	// 	return false;
	// if (primes[a] && primes[b])
	// 	return false;
	// if (primes[a]){
	// 	if (b % a == 0)
	// 		return true;
	// 	return false;
	// }
	// if (primes[b]){
	// 	if (a % b == 0)
	// 		return true;
	// 	return false;
	// }
	// // if (cnt[a])
	if (__gcd(a, b) > 1)
		return true;
	return false;
}


int main(){
	fastIO;
	int T;
	cin >> T;
	// vector<bool> primes(maxn + 1, true);
	// sieve(primes);
	// primes[1] = false;
	while(T--){
		int n;
		cin >> n;
		vector<int> ar2(n);
		forn(i, n)
			cin >> ar2[i];
		// print(arr);
		vector<int> arr;
		forn(i, n){
			if (ar2[i] % 2 == 0)
				arr.pb(ar2[i]);
		}
		forn(i,n){
			if (ar2[i] % 2 == 1)
				arr.pb(ar2[i]);	
		}
		assert(arr.size() == n);
		// sort(arr.begin(), arr.end(), comp);
		// print(arr);
		int k = 0;
		while(k < n && arr[k] % 2 == 0)
			k++;
		int ct = (k * (k - 1))/2 + k * (n - k);
		// forsn(i, k, n - 1){
		// 	if (arr[i] % 2 == 0)
		// 		ct += k;
		// }
		forsn(i, k, n - 1){
			forsn(j, i + 1, n - 1){
				// if (check(arr[i], arr[j], primes))
				if (check(arr[i], arr[j]))
					ct++;
			}
		}
		cout << ct << bline;
	}
	return 0;
}