#if 0
    me=`basename $0 .cpp`
    g++ -std=c++20 $me.cpp -o $me
    if test -f $me; then
	    ./$me > $me.out
    	rm $me
        echo "\noutput begins now:"
        cat $me.out
        rm $me.out
    fi
    exit
#endif

/***************************************************
* AUTHOR : Anav Prasad
* Nick : vrangr
****************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <unordered_set>
#include <set>
#include <stdlib.h>
#include <map>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <bit>
#include <bitset>
#include <assert.h>
#define debug false

using namespace std;

#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
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
#define print_iter(x) cout << "*" << #x << ": " << *x << endl;
#define print_arr(arr) cout << #arr << ": ";print(arr);
#define print_pair(pr) cout << #pr << ": ";print(pr);
#define space " "
#define yes "YES\n"
#define no "NO\n"

typedef long long int ll;
typedef unsigned long long int ull;
template <typename type> void print(const vector<vector<type> > &arr);
template <typename type> void print(const vector<type> &arr);
template <typename type> void off_print(const vector<type> &arr);
template <typename t1, typename t2> void print(const vector<pair<t1,t2> > &arr);
template <typename t1, typename t2> void print(const vector<vector<pair<t1,t2> > > &arr);
template <typename t1, typename t2> void print(const pair<t1, t2> &p);

void solve();

int main(){
	fastIO;
	TEST;
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

template <typename type> void off_print(const vector<type> &arr){
	forn(i, arr.size())
		cout << arr[i] << " ";
	cout << endl;
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

#define white 0
#define black 1
const char wh = 'W', bl = 'B';
inline int get_hash(int x, int y, int n){
    return x + y*n;
}

void set_xy(int &x, int &y, int n, int hh){
    x = hh%n;
    y = hh/n;
}

inline bool is_valid(int x, int y, int n, int m){
    return x >= 0 && x < n && y < m && y >= 0;
}

void set_char(int x, int y, char toset, vector<string> &answer, vector<vector<int>> &rct, vector<vector<int>> &cct){
    answer[x][y] = toset;
    if (toset == wh){
        rct[x][white]++;
        cct[y][white]++;
    }
    else{
        rct[x][black]++;
        cct[y][black]++;
    }
}

void process_node(int hh, int n, vector<string> &answer, vector<vector<int>> &rct, vector<vector<int>> &cct){
    int x, y;
    char toset;
    set_xy(x,y,n,hh);
    if(rct[x][white] == rct[x][black] && cct[y][white] == cct[y][black])
        toset = wh;
    else if(rct[x][white] == rct[x][black])
        toset = (cct[y][white] < cct[y][black]? wh : bl);
    else if (cct[y][white] == cct[y][black])
        toset = (rct[x][white] < rct[x][black]? wh : bl);
    else{
        if (abs(rct[x][white] - rct[x][black]) == abs(cct[y][white] - cct[y][black]))
            toset = wh;
        else if (abs(rct[x][white] - rct[x][black]) < abs(cct[y][white] - cct[y][black]))
            toset = (cct[y][white] < cct[y][black]? wh : bl);
        else
            toset = (rct[x][white] < rct[x][black]? wh : bl);
    }
    set_char(x, y, toset, answer, rct, cct);
}

void add_adjacent(int ghh, unordered_set<int> &dominos, unordered_map<int, bool> &visited, int n, int m, deque<int> &q){
    int x, y;
    set_xy(x, y, n, ghh);
    int hh = get_hash(x-1,y,n);
    if (is_valid(x-1, y, n, m) && dominos.find(hh) != dominos.end() && !visited[hh])
        q.push_back(hh);
    hh = get_hash(x+1,y,n);
    if (is_valid(x+1, y, n, m) && dominos.find(hh) != dominos.end() && !visited[hh])
        q.push_back(hh);
    hh = get_hash(x,y-1,n);
    if (is_valid(x, y-1, n, m) && dominos.find(hh) != dominos.end() && !visited[hh])
        q.push_back(hh);
    hh = get_hash(x,y+1,n);
    if (is_valid(x, y+1, n, m) && dominos.find(hh) != dominos.end() && !visited[hh])
        q.push_back(hh);
}

void process_adjacent(int ghh, vector<string> &answer, vector<string> &board, vector<vector<int>> &rct, vector<vector<int>> &cct, unordered_set<int> &dominos, unordered_map<int, bool> &visited, int n, int m, deque<int> &q){
    int x, y;
    set_xy(x, y, n, ghh);
    char toset = (answer[x][y] == wh? bl : wh);
    int hh;
    switch(board[x][y]){
        case 'L':
            assert(is_valid(x,y+1,n,m));
            hh = get_hash(x, y+1, n);
            assert(dominos.find(hh) != dominos.end());
            set_char(x,y+1, toset, answer, rct, cct);
            visited[hh] = true;
            add_adjacent(hh, dominos, visited, n, m, q);
            break;
        case 'R':
            assert(is_valid(x,y-1,n,m));
            hh = get_hash(x, y-1, n);
            assert(dominos.find(hh) != dominos.end());
            set_char(x,y-1, toset, answer, rct, cct);
            visited[hh] = true;
            add_adjacent(hh, dominos, visited, n, m, q);
            break;
        case 'U':
            assert(is_valid(x+1,y,n,m));
            hh = get_hash(x+1, y, n);
            assert(dominos.find(hh) != dominos.end());
            set_char(x+1,y, toset, answer, rct, cct);
            visited[hh] = true;
            add_adjacent(hh, dominos, visited, n, m, q);
            break;
        case 'D':
            assert(is_valid(x-1,y,n,m));
            hh = get_hash(x-1, y, n);
            assert(dominos.find(hh) != dominos.end());
            set_char(x-1,y, toset, answer, rct, cct);
            visited[hh] = true;
            add_adjacent(hh, dominos, visited, n, m, q);
            break;
    }
}

void solve1(){
    int n, m; cin >> n >> m;
    vector<string> board(n);
    unordered_set<int> dominos;
    vector<int> dlist;
    unordered_map<int, bool> visited;
    deque<int> q;
    vector<vector<int>> rct(n, {0,0}), cct(m,{0,0});
    vector<int> rcellct(n,0), ccellct(m,0);
    int hh,x,y;
    forn(i, n){
        cin >> board[i];
        forn(j, m){
            if(board[i][j] != '.'){
                hh = get_hash(i, j, n);
                dominos.insert(hh);
                visited[hh] = false;
                dlist.push_back(hh);
                rcellct[i]++;
                ccellct[j]++;
            }
        }
    }
    forn(i,n)
        if (rcellct[i]%2)
            return void(cout << "-1\n");
    forn(j,m)
        if (ccellct[j]%2)
            return void(cout << "-1\n");
    vector<string> answer(n, string(m,'.'));
    forn(i, dlist.size()){
        hh = dlist[i];
        if (visited[hh]) continue;
        q.push_back(hh);
        while(!q.empty()){
            hh = q.front();
            q.pop_front();
            if (visited[hh]) continue;
            visited[hh] = true;
            process_node(hh, n, answer, rct, cct);
            add_adjacent(hh, dominos, visited, n, m, q);
            process_adjacent(hh, answer, board, rct, cct, dominos, visited, n, m, q);
            #if debug
                cout << "processing done\n";
                int x, y;
                set_xy(x, y, n, hh);
                print_var(x);
                print_var(y);
                print_var(board[x][y]);
                print_var(answer[x][y]);
                print_arr(rct[x]);
                print_arr(cct[y]);
                if (x==0 && y == 2){
                    print_var(x);
                    print_var(y+1);
                    print_var(board[x][y+1]);
                    print_var(answer[x][y+1]);
                    print_arr(cct[y+1]);
                }
                cout << endl;
            #endif
        }
    }
    forn(i, n)
        if (rct[i][white] != rct[i][black]){
            #if debug
                cout << "problem!!";
                print_var(i);
                print_var(rct[i][white]);
                print_var(rct[i][black]);
                print_arr(answer);
                print_arr(rct);
                cout << endl;
            #endif
            return void(cout << "-1\n");
        }
    forn(j, m)
        if (cct[j][white] != cct[j][black]){
            #if debug
                cout << "problem!!";
                print_var(j);
                print_var(cct[j][white]);
                print_var(cct[j][black]);
                print_arr(cct);
                print_arr(answer);
                cout << endl;
            #endif
            return void(cout << "-1\n");
        }
    forn(i, n)
        cout << answer[i] << "\n";
}

void solve(){
    int n, m; cin >> n >> m;
    vector<string> board(n);
    forn(i, n) cin >> board[i];
    vector<string> answer(n, string(m, '.'));
    int wcount = 0, bcount = 0;
    forn(i, n){
        wcount = 0;
        bcount = 0;
        forn(j, m){
            if (answer[i][j] == 'W')
                wcount++;
            else if (answer[i][j] == 'B')
                bcount++;
        }
        forn(j, m){
            if (board[i][j] != 'U') continue;
            if (wcount <= bcount){
                answer[i][j] = 'W';
                wcount++;
                answer[i+1][j] = 'B';
                continue;
            }
            answer[i][j] = 'B';
            bcount++;
            answer[i+1][j] = 'W';
        }
        if (wcount != bcount) return void(cout << "-1\n");
    }
    forn(j, m){
        wcount = 0;
        bcount = 0;
        forn(i, n){
            if (answer[i][j] == 'W')
                wcount++;
            else if (answer[i][j] == 'B')
                bcount++;
        }
        forn(i, n){
            if (board[i][j] != 'L') continue;
            if (wcount <= bcount){
                answer[i][j] = 'W';
                wcount++;
                answer[i][j+1] = 'B';
                continue;
            }
            answer[i][j] = 'B';
            bcount++;
            answer[i][j+1] = 'W';
        }
        if (wcount != bcount) return void(cout << "-1\n");
    }
    forn(i, n) cout << answer[i] << endl;
}