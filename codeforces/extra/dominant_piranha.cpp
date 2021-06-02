#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, ch, mx, p, n, ind, ind2, br;
	cin >> T;
	for (int test = 0; test < T; test++){
	    cin >> n;
	    cin >> p;
	    mx = p;
	    ch = 0;
	    ind = 1;
	    ind2 = 1;
	    br = 0;
	    for (int i = 0; i < n - 1; ++i){
	        cin >> p;
	        if (p > mx){
	            ch = 1;
	            mx = p;
	            ind = i + 2;
	            ind2 = ind;
	            br = 0;
	        }
	        else if(p < mx){
	            ch = 1;
	            br = 1;
	        }
	        else{
	            if (br == 1)
	                continue;
	            ind2 = i + 2;
	        }
	    }
	    if (ch == 1 && ind2!= n){
	        cout << ind2;
	    }
	    else if(ch == 1){
	        cout << ind;
	    }
	    else
	        cout << "-1";
	    if (test != T-1)
	        cout << endl;
	}
	return 0;
}

