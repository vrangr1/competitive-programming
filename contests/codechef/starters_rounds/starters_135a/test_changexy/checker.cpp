/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Wed May 22 20:28:11 IST 2024
****************************************************/
#include <iostream>
#include <vector>
#include <string.h>
#include <ctype.h>
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
#include <stack>
#include <list>
#include <forward_list>
#include <bit>
#include <bitset>
#include <array>
#include <sstream>
#include <assert.h>
#define debug(...) 42
#ifdef LOCAL
    #undef debug
    #include <algo/debug.hpp>
    const bool DEBUG = true;
#else
    [[maybe_unused]] const bool DEBUG = false;
#endif

using namespace std;

typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t i128;
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define CHECK check()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(v) ((int)(v).size())
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, debug, forn)(__VA_ARGS__)
#define forn(i, n) for (__typeof(n) i = 0; i < n; i++)
#define forsn(i, st, end, d) for(__typeof(end) i = st; (d>0?i<=end:i>=end); i+=((__typeof(end))d))
#define mt make_tuple
#define space " "
#define yes "Yes\n"
#define no "No\n"
#define pass ((void)0)
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void check();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	CHECK;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
	return 0;
}

vector<string> get_output(){
    string s;
    cin >> s;
    assert(s=="OUTPUT_BEGINS");
    vector<string> out;
    cin >> s;
    while(s!="OUTPUT_ENDS"){
        out.push_back(s);
        cin >> s;
    }
    return out;
}

bool check_if_equal(vector<string> &test_output, vector<string> &correct_output){
    if (sz(test_output) != sz(correct_output)) return false;
    rep(i,sz(test_output))
        if (test_output[i] != correct_output[i]) return false;
    return true;
}

const string output_start = "OUTPUT_BEGINS", output_end = "OUTPUT_ENDS";

void check(){
    stringstream ss;
    string s;
    auto transfer = [&]() -> bool {
        cin >> s;
        if (s == output_start || s == output_end) return false;
        ss << s << endl;
        return true;
    };
    auto trash_input = [&s,&ss]() -> void {
        ss >> s;
    };
    auto process_input = [&]() -> void {
        assert(!transfer());
        while(transfer())
            trash_input();
    };
    process_input();
    auto process_output = [&](vector<string> &output) -> void {
        assert(!transfer());
        while(transfer()){
            ss >> s;
            output.push_back(s);
        }
    };
    vector<string> test_output, correct_output;
    process_output(test_output);
    process_output(correct_output);
    auto match_outputs = [&]() -> bool {
        return check_if_equal(test_output, correct_output);
    };
    if (match_outputs()) cout << yes;
    else cout << no;
}