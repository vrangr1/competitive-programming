// /***************************************************
// * Author  : Anav Prasad
// * Handle  : vrangr
// * Created : Wed Sep  4 20:50:01 IST 2024
// ****************************************************/
// #include <bits/stdc++.h>

// #define debug(...) (void)42
// #ifdef LOCAL
//     #undef debug
//     #include <algo/debug.hpp>
//     const bool DEBUG = true;
// #else
//     [[maybe_unused]] const bool DEBUG = false;
// #endif

// using namespace std;

// typedef unsigned int uint;
// typedef long long int ll;
// typedef unsigned long long int ull;
// typedef long double ld;
// typedef __int128_t i128;
// #define endl "\n"
// #define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
// #define TEST int T;cin>>T;while(T--)solve();
// #define TEST1 solve();
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define sz(v) ((int)(v).size())
// #define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
// #define rep(...) GET_MACRO(__VA_ARGS__, forsn, debug, forn)(__VA_ARGS__)
// #define forn(i, n) for (__typeof(n) i = 0; i < n; i++)
// #define forsn(i, st, end, d) for(__typeof(end) i = st; (d>0?i<=end:i>=end); i+=((__typeof(end))d))
// template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
// void solve();

// int main() {
// 	fastIO;
// 	TEST;
// #ifdef LOCAL
//     cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
// #endif
// 	return 0;
// }

// void solve1() {
//     int n, k; cin >> n >> k;
//     string a, b; cin >> a >> b;
//     if (a == b) return void(cout << "0\n");
//     vector<pair<int,char>> ops;
//     auto ans = [&]() -> void {
//         assert(sz(ops) <= 2*n);
//         cout << sz(ops) << endl;
//         for (auto [i, c] : ops) {
//             cout << i+1 << " " << c << endl;
//         }
//     };
//     rep(i,n) {
//         if (i+k-1 >= n) break;
//         if (a[i] == b[i]) continue;
//         ops.emplace_back(i,b[i]);
//         rep(j,i,i+k-1,1)
//             a[j] = b[i];
//     }
//     if (a == b) {
//         ans();
//         return;
//     }
//     rep(i,n-1,k-1,-1) {
//         if (a[i] == b[i]) continue;
//         ops.emplace_back(i-k+1,b[i]);
//         rep(j,i,i-k+1,-1)
//             a[j] = b[i];
//     }
//     if (a == b) {
//         ans();
//         return;
//     }
//     cout << "-1\n";
// }

// void solve2() {
//     int n, k; cin >> n >> k;
//     string a, b; cin >> a >> b;
//     if (a == b) return void(cout << "0\n");
//     vector<int> order(n-k+1);
//     iota(all(order),0);
//     auto do_op = [&](string &s, int i, char ch) -> void {
//         assert(i <= n-k);
//         assert(i >= 0);
//         rep(j,i,i+k-1,1)
//             s[j] = ch;
//     };
//     bool pt = false;
//     auto ans = [&](vector<pair<int,char>> &ops) -> void {
//         pt = true;
//         assert(sz(ops) <= 2*n);
//         cout << sz(ops) << endl;
//         for (auto [i, c] : ops) {
//             cout << i+1 << " " << c << endl;
//         }
//     };
//     auto rec = [&](auto &&self, int ind, string &s, vector<pair<int,char>> ops) -> bool {
//         if (s == b) {
//             if (!pt) ans(ops);
//             return true;
//         }
//         if (ind >= sz(order)) return false;
//         int i = order[ind];
//         rep(ch,'a','z',1) {
//             debug(endl,ch);
//             char og = s[i];
//             ops.emplace_back(i,ch);
//             do_op(s,i,ch);
//             debug(s);
//             if (self(self,ind+1,s,ops)) {
//                 assert(pt);
//                 return true;
//             }
//             ops.pop_back();
//             do_op(s,i,og);
//         }
//         return false;
//     };
//     do {
//         string s = a;
//         debug(order);
//         vector<pair<int,char>> ops;
//         if (rec(rec,0,s,ops)) break;
//     } while(next_permutation(all(order)));
//     if (!pt) cout << "-1\n";
// }

// void solve() {
//     int n , k;
//     cin >> n >> k;
//     string a , b;
//     cin >> a >> b;
//     vector<int>freq(26,0);
//     for(int i = 0 ; i < k ; i++){
//         freq[b[i]-'a']++;
//     }
//     if(a == b){
//         cout<<0<<endl;
//         return;
//     }
//     int i = 0;
//     int j = k-1;
//     int idx = -1;
//     [[maybe_unused]] bool flag = false;
//     while(j < n){
//         if(freq[b[i]-'a'] == k){
//             idx = i;
//             flag = true;
//             break;
//         }
//         freq[b[i]-'a']--;
//         i++;
//         j++;
//         if(j >= n) break;
//         freq[b[j]-'a']++;
//     }
//     if(idx == -1){
//         cout<<-1<<endl;
//         return;
//     }
//     int cnt = 0;
//     i = n-1;
//     while(i-k+2 >= 1){
//         cnt++;
//         i--;
//     }
//     cout<<cnt+(idx+1)<<endl;
//     i = n-1;
//     while(i-k+2 >= 1){
//         cout<<(i-k+2)<<" "<<b[i]<<endl;
//         i--;
//     }
//     int iq  = 0;
//     while(iq <= idx){
//         cout<<(iq+1)<<" "<<b[iq]<<endl;
//         iq++;
//     }
// }


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    
    if (s == t){
        cout << 0 << "\n";
        return;
    }
    
    vector <int> ps(n);
    for (int i = 1; i < n; i++){
        ps[i] = ps[i - 1] + (t[i] != t[i - 1]);
    }
    
    int x = k;
    for (int i = 0; i < n; i++){
        int j = i + k - 1;
        if (j >= n) continue;
        if (ps[j] == ps[i]){
            vector <pair<int, int>> vec;
            for (int k = 0; k < i; k++){
                vec.push_back({k, t[k]});
            }
            
            for (int k = n - 1; k > j; k--){
                vec.push_back({k - x + 1, t[k]});
            }
            
            vec.push_back({i, t[i]});
            
            cout << vec.size() << "\n";
            for (auto [x, y] : vec) cout << (x + 1) << " " << (char)y << "\n";
            
            return;
        }
    }
    
    cout << -1 << "\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}