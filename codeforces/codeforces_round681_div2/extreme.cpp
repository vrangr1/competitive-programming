#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	int T, N, temp, col;
	vector<int> a;
	cin >> T;
	lli cost;
	bool ans;
	while(T--){
	    cin >> N;
	    if (N == 1 || N == 2){
	        cout << "YES\n";
	        continue;
	    }
	    
	    for(int i = 0; i < N; ++i){
	        cin >> temp;
	        a.push_back(temp);
	    }
	    
	    cost = 0;
	    ans = true;
	    if(a[0] <= a[N-1]){
	        int i = N-2;
	        while(i > 0){
	            col = a[i] - cost;
	            if (col < 0){
	                ans = false;
	                break;
	            }
	            if(col > a[i+1]){
	                cost = col - a[i+1] + cost;
	                if (cost > a[0]){
	                    ans = false;
    	                break;
	                }
	                a[i] = a[i+1];
	            }
	            --i;
	        }
	       // col = a[0] - cost;
	       // if (col < 0)
	       //     ans = false;
	       // if (col > a[1])
	       //     ans = false;
	       // else
	       //     ans = false;
	    }
	    else{
	        int i = 1;
	       // cost = 0;
	        while(i < N-1){
	            col = a[i] - cost;
	            if (col < 0){
	                ans = false;
	                break;
	            }
	            if(col > a[i-1]){
	                cost = col - a[i-1] + cost;
	                if (cost > a[N-1]){
	                    ans = false;
    	                break;
	                }
	                a[i] = a[i-1];
	            }
	            ++i;
	        }
	       // if (a[N-1] - cost < a[N-2])
	       //     ans = true;
	       // else
	       //     ans = false;
	    }
	    
	    if (ans)
	        cout << "YES\n";
	    else
	        cout << "NO\n";
	    
	    a.clear();
	}
	return 0;
}

