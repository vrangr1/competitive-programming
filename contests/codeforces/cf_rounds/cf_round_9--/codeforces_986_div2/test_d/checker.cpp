/***************************************************
* Author  : Anav Prasad
* Nick    : vrangr
* Created : Mon Nov 11 08:45:53 IST 2024
****************************************************/
#include <bits/stdc++.h>

#define debug(...) (void)42
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
#define yes "YES\n"
#define no "NO\n"
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void check();

// IMPORT SNIPPETS HERE

// END OF SNIPPETS

int main(){
	fastIO;
	CHECK;
    #ifdef LOCAL
        cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
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
    int n;
    vector<vector<int>> ps(3);
    [[maybe_unused]] auto read_input = [&]() -> void {
        // Use ss instead of cin to regularly take inputs into variables defined before this function
        ss >> n >> n;
        rep(i,3) {
            ps[i].resize(n);
            rep(j,n) ss >> ps[i][j];
        }
    };
    [[maybe_unused]] auto trash_stream = [&s,&ss]() -> void {
        // Comment the following line if inputs need to be stored
        // ss >> s;
    };
    auto process_input = [&]() -> void {
        assert(!transfer());
        while(transfer())
            trash_stream();
        read_input();
    };
    process_input();
    [[maybe_unused]] auto read_output = [&](vector<string> &output) -> void {
        // Read input in from ss as if reading from cin stream
        // Process however needed and append to output what the converted output that needs to be 1-1 compared with converted correct output
        ss >> s;
        if (s == "NO") {
            output.push_back(s);
            return;
        }
        assert(s == "YES");
        int cur = 1;
        int k; ss >> k;
        bool valid = true;
        while(k--) {
            char p;
            int nxt;
            ss >> p >> nxt;
            if (!valid) continue;
            if (cur > nxt) {
                valid = false;
                continue;
            }
            switch(p) {
                case 'q':
                    if (ps[0][cur-1] < ps[0][nxt-1]) {
                        valid = false;
                    } else {
                        cur = nxt;
                    }
                    break;
                case 'k':
                    if (ps[1][cur-1] < ps[1][nxt-1]) {
                        valid = false;
                    } else {
                        cur = nxt;
                    }
                    break;
                default:
                    assert(p == 'j');
                    if (ps[2][cur-1] < ps[2][nxt-1]) {
                        valid = false;
                    } else {
                        cur = nxt;
                    }
            }
        }
        if (cur != n) valid = false;
        if (!valid) output.push_back("WA");
        else output.push_back("YES");
    };
    auto process_output = [&](vector<string> &output) -> void {
        assert(!transfer());
        while(transfer())
            trash_stream();
        read_output(output);
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