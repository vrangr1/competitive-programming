#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n%2 == 0 || n%3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true;
}
int sm_pmfac(int n){
    if (n % 2 == 0){
        return 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2){
        if (n%i == 0)
            return i;
    }
}
int main() {
	// your code goes here
	int T, n, pmfac;
	cin >> T;
	for (int test = 0; test < T; ++test){
	    cin >> n;
	    if (isprime(n)){
	        for (int i = 0; i < n; ++i){
	            for(int j = 0; j < n - 1; ++j){
	                cout << "1 ";
	            }
	            cout << "1\n";
	        }
	    }
	    else{
	        pmfac = sm_pmfac(n);
	        for (int i = 0; i < n; ++i){
	            
	            for (int j = 0; j < n; ++j){
	                if ( (j >= i) && ((j - i + 1) <=  pmfac - i%pmfac) ){
	                    if (j < n -1 )
	                        cout << "1 ";
	                    else
	                        cout << "1\n";
	                }
	                else if ( (j < i) && (i - j <= i % pmfac) ){
	                    if (j < n -1){
	                        cout << "1 ";
	                    }
	                    else
	                        cout << "1\n";
	                }
	                else{
	                    if (j < n -1)
	                        cout << "0 ";
	                    else
	                        cout << "0\n";
	                }
	            }
	            
	            
	        }
	    }
	}
	return 0;
}

