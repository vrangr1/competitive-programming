#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, n, ind, dist, first, sec, sz;
	cin >> T;
	vector<int> dist_gang, no_link;
	for(int test = 0; test < T; ++test){
	    cin>>n;
	    cin >> dist;
	    dist_gang.push_back(dist);
	    ind = 0;
	    first = 0;
	    sec = -1;
	    for(int i = 0; i < n - 1; ++i){
	        cin >> dist;
	        dist_gang.push_back(dist);
	        if (dist != dist_gang[0]){
	            if (first == 0){
	                first = 1;
	                cout << "YES\n";
	                sec = i + 1;
	            }
	            cout << "1 " << i + 2 << endl;
	        }
	        else{
	            if(first != 0)
	            no_link.push_back(i+1);
	        }
	    }
	    sz = no_link.size();
	    for(int i = 0; i < sz; ++i){
	        cout << sec + 1 << " " << no_link[i] + 1 << endl;
	    }
	   // cout << "district gangs:\n";
	   // for(int i = 0; i < n; ++i){
	   //     cout << dist_gang[i] << " ";
	   // }
	   // cout << endl;
	   // cout << "Cannot be linked\n";
	   // for (int i = 0; i < sz; ++i){
	   //     cout << no_link[i] << " ";
	   // }
	   // cout << endl;
	    if (first == 0)
	        cout << "NO\n";
	    dist_gang.clear();
	    no_link.clear();
	}
	return 0;
}

