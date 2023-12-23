#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
     
}
int main() {
	int t, n;
	cin >> t;
	vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	while(t--){
	    cin >> n;
	    int i = 1;
	    while(i <= n){
	        if (primes[i-1]*2 < 4*n){
	            cout << primes[i-1]*2 << " ";
	            
	        }
	        else{
	            int temp = i;
	            int gd;
	            bool check = true;
	            for(int j = 15; j <= 4*n; j += 2){
	                check = true;
	                for(int k = 0; k < temp; ++k){
	                    gd = gcd(primes[k]*2, j);
	                    if(gd == 1 || gd == min(primes[k]*2,j)){
	                        check = false;
	                        break;
	                    }
	                    
	                }
	                if(i <= n && check){
	                    cout << j << " ";
	                    ++i;
	                }
	                else if(check){
	                    break;
	                }
	            }
	        }
	        i++;
	    }
	    cout << endl;
	}
	return 0;
}

