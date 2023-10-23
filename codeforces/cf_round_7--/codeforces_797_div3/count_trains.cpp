/***************************************************
* AUTHOR : Anav Prasad
* Nick : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <assert.h>
// TODO: Check if all the header files are included

using namespace std;

#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)
#define forr(i, n) for (int i = n - 1; i >= 0; --i)
#define forsr(i, st_val, n) for (int i = st_val; i >= n; --i)
#define pb1(a) push_back(a)
#define pb2(a,b) push_back({a, b})
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define pb(...) GET_MACRO(__VA_ARGS__, pb1, pb2)(__VA_ARGS__)
#define pass (void)0
#define print_var(x) cout << #x << ": " << x << "\n";
#define space " "
typedef long long int ll;
typedef unsigned long long int ull;
template <typename type> void print(const vector<vector<type> > &arr);
template <typename type> void print(const vector<type> &arr);
template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr);
template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);
class car;
class train;


class cars{
public:
    trains *train;
    cars *nextcar, *prevcar;
    int maxspeed, curspeed, index;
    cars(int index, int maxspeed){
        this->train = nullptr;
        this->nextcar = nullptr;
        this->prevcar = nullptr;
        this->maxspeed = maxspeed;
        this->curspeed = -1;
        this->index = index;
    }
};

class trains{
public:
    cars *headcar;
    trains *nexttrain;
    int curspeed;
    trains(){
        this->headcar = nullptr;
        this->nexttrain = nullptr;
        this->curspeed = -1;
    }
};

int main(){
	fastIO;
	int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<int> maxspeeds(n);
        forn(i, n) cin >> maxspeeds[i];
        vector<cars*> hashcars(n);
        forn(i, n) hashcars[i] = new cars(i, maxspeeds[i]);
        trains *headtrain = new trains(), *train;
        train = headtrain;
        train->headcar = hashcars[0];
        int curspeed = maxspeeds[0];
        cars *curcar = train->headcar;
        curcar->curspeed = curspeed;
        ll ans = 1;
        forsn(i, 1, n-1){
            if (curspeed <= maxspeeds[i]){
                curcar->nextcar = hashcars[i];
                curcar->nextcar->prevcar = curcar;
                curcar = curcar->nextcar;
                curcar->curspeed = curspeed;
                train->curspeed = curspeed;
                curcar->train = train;
                continue;
            }
            train->nexttrain = new trains();
            ans++;
            curcar = hashcars[i];
            curcar->prevcar = nullptr;
            train = train->nexttrain;
            train->headcar = curcar;
            curspeed = curcar->maxspeed;
            curcar->curspeed = curcar->maxspeed;
            curcar->train = train;
            train->curspeed = curspeed;
        }
        int k, d;
        cars *prevcar;
        forn(i,m){
            cin >> k >> d;
            curcar = hashcars[k-1];
            if (curcar->maxspeed - d >= curcar->curspeed){
                cout << ans << " ";
                curcar->maxspeed = curcar->maxspeed - d;
                continue;
            }
            if (curcar->prevcar == nullptr){
                curcar->curspeed = curcar->maxspeed - d;
                curcar->maxspeed = curcar->maxspeed - d;
                train = curcar->train;
                curspeed = curcar->curspeed;
                curcar = curcar->nextcar;
                while(curcar != nullptr){
                    if (curcar->maxspeed < curspeed){
                        
                    }
                }
            }
        }
        cout << endl;
    }
	return 0;
}


template <typename type> void print(const vector<vector<type> > &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << "[";
		forn(j, arr[i].size() - 1)
			cout << arr[i][j] << ", ";
		cout << arr[i][arr[i].size() - 1] << "]";
		if (i != arr.size() - 1)
			cout << "," << endl;
	}
	cout << "], 2D Vector\n";
}


template <typename type> void print(const vector<type> &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << arr[i];
		if (i != arr.size() - 1)
			cout << ", ";
	}
	cout << "], 1D Vector\n";
}


template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr){
	int n = arr.size();
	cout << "\n[";
	forn(i, n - 1){
		cout << "{" << arr[i].first << "," << arr[i].second << "}, ";
	}
	cout << "{" << arr[n - 1].first << "," << arr[n - 1].second << "}], 1D Vector of Pairs\n";
}


template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr){
	cout << "\n[";
	forn(i, arr.size()){
		cout << "[";
		forn(j, arr[i].size()){
			cout << "{" << arr[i][j].first << "," << arr[i][j].second << "}";
			if (j != arr[i].size() - 1)
				cout << ", ";
		}
		cout << "]";
		if (i != arr.size() - 1)
			cout << "," << endl;
	}
	cout << "], 2D Vector of Pairs\n";
}


template <typename t1, typename t2> void print(const pair<t1, t2> &p){
	cout << "\n{" << p.first << "," << p.second << "}, Pair\n";
}
