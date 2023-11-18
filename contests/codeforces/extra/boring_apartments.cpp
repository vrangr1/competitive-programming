#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, x, n, ans, c;
	cin >> T;
	for (int test = 0; test < T; test++){
	    cin >> x;
	    n = x%10;
	    ans = 0;
	    for (int i = 1; i < n; ++i){
	        ans += 10;
	    }
	    c = 0;
	    while (x!=0){
	        x /= 10;
	        c++;
	    }
	    ans += (((c)*(c+1))/2);
	    cout << ans << endl;
	}
	return 0;
}

