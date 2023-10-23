#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli calc(vector<pair<int, int>> &ab, int h, int l){
    lli cost = 0;
    for(int i = l+1; i <= h; ++i){
        cost += (lli)ab[i].second;
    }
    return cost;
}

// void bin_srch(vector<pair<int,int>> &ab, int h, int l, lli &cost){
//     if(h>=l){
//         lli cst;
//         int mid = (h+l)/2;
//         cst = calc(ab, h, mid) + cost;
//         if (cst <= ab[mid].first){
            
//         }
//     }
    
// }

lli max(lli a, lli b){
    if (a>b)
        return a;
    return b;
}

lli find_ans(vector<pair<int,int>> &ab, int h, lli cost){
    lli cst = cost;
    lli ans;
    lli maxi;
    lli tot = calc(ab, h, -1);
    // cout << "total : " << tot << " cost: " << cost << endl;
    ans = cost + tot;
    for(int i = 0; i <= h; ++i){
        tot = tot - ab[i].second;
        cst = cost + tot;
        maxi = max(ab[i].first, cst);
        if (maxi < ans){
            ans = maxi;
        }
    }
    return ans;
}

int main() {
	int T, N, temp, ind, h, l;
	lli x, cost;
	vector<int> a, b;
	vector<pair<int,int>> ab;
	cin >> T;
	
	while(T--){
	    cin >> N;
	    for(int i = 0; i < N; ++i){
	        cin >> temp;
	        a.push_back(temp);
	    }
	    x = 0;
	    for(int i = 0; i < N; ++i){
	        cin >> temp;
	        x += (lli)temp;
	        b.push_back(temp);
	    }
	    for(int i = 0; i < N; ++i){
	        ab.push_back(make_pair(a[i],b[i]));
	    }
	    cost = 0;
	    sort(ab.begin(), ab.end());
	    for(ind = N-1; ind >= 0; --ind){
	        if (ab[ind].first <= x)
	            break;
	        cost += (lli)ab[ind].second;
	    }
	    l = 0;
	    h = ind;
	   // cout << "cost: " << cost << " h: " << h << endl;
	    cost = find_ans(ab, h, cost);
	    // bin_srch(ab, h, l, cost);
	    cout << cost << endl;
	    a.clear();
	    b.clear();
	    ab.clear();
	}
	return 0;
}

