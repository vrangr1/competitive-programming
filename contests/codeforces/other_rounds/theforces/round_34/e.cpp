/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Tue Sep 17 21:34:56 IST 2024
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
#define TEST int T;cin>>T;while(T--)solve();
#define TEST1 solve();
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(v) ((int)(v).size())
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, forsn, debug, forn)(__VA_ARGS__)
#define forn(i, n) for (__typeof(n) i = 0; i < n; i++)
#define forsn(i, st, end, d) for(__typeof(end) i = st; (d>0?i<=end:i>=end); i+=((__typeof(end))d))
template<typename type>inline void print_vec(const vector<type> &v){rep(i,sz(v))cout<<v[i]<<" \n"[i==sz(v)-1];}
void solve();

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

#ifndef MODULAR_INT_SNIPPET
#define MODULAR_INT_SNIPPET

#include <string>
// Based on ACL's modint header and tourist's Modular class.
template <typename MOD>
class ModularInt {
private:
    using type = typename decay<decltype(MOD::value)>::type;
    const type mod = MOD::value;
    type value;

    template <typename T>
    type normalize(T val) const {
        val %= T(mod);
        if (val >= 0ll)
            return type(val);
        return type((val + mod) % mod);
    }

    // Not done value = (value%mod + mod)%mod because mod-1+mod maybe > inf
    void normalize() {
        this->value %= this->mod;
        if (this->value >= 0) 
            return;
        this->value = (this->value + this->mod) % this->mod;
    }
    
    // Assumes 0 <= lhs < mod, 0 <= rhs < mod
    void add(type lhs, type rhs, type &result) const {
        if (__builtin_add_overflow(lhs, rhs, &result))
            result = lhs + (this->mod - rhs);
        else 
            result = normalize(result);
    }
    
    // Assumes 0 <= lhs < mod, 0 <= rhs < mod
    type add(type lhs, type rhs) const {
        type result;
        add(lhs, rhs, result);
        return result;
    }

    // Assumes 0 <= lhs < mod, 0 <= rhs < mod
    void subtract(type lhs, type rhs, type &result) const {
        if (lhs >= rhs)
            result = lhs - rhs;
        else
            result = this->mod - (rhs - lhs);
    }

    // Assumes 0 <= lhs < mod, 0 <= rhs < mod
    type subtract(type lhs, type rhs) const {
        type result;
        subtract(lhs, rhs, result);
        return result;
    }

    // Assumes 0 <= lhs < mod, 0 <= rhs < mod
    void multiply(type lhs, type rhs, type &result) const {
        if (__builtin_mul_overflow(lhs, rhs, &result))
            result = normalize(__uint128_t(lhs) * __uint128_t(rhs));
        else
            result = normalize(result);
    }

    // Assumes 0 <= lhs < mod, 0 <= rhs < mod
    type multiply(type lhs, type rhs) const {
        type result;
        multiply(lhs, rhs, result);
        return result;
    }

    pair<type,type> inverse(type a, type b) const {
        assert(gcd(a, b) == 1);
        if (a == 1) return {1,0};
        auto [x, y] = inverse(b%a,a);
        return {subtract(y, multiply((b / a), x)), x};
    }

    // Assumes 1 <= x < mod
    type inverse(type x) const {
        if (x == 1) return 1;
        return inverse(x, this->mod).first;
    }

    // Assumes 0 <= lhs < mod, 0 <= rhs < mod
    void divide(type lhs, type rhs, type &result) const {
        multiply(lhs, inverse(rhs), result);
    }

    // Assumes 0 <= lhs < mod, 0 <= rhs < mod
    type divide(type lhs, type rhs) const {
        type result;
        divide(lhs, rhs, result);
        return result;
    }

public:
    ModularInt() : value(0) {}

    ModularInt(const ModularInt &var) {
        this->value = var.value;
    }
    
    template <typename U>
    ModularInt(U val) {
        this->value = normalize(val);
    }

    type operator()() const {
        return this->value;
    }

    template <typename T>
    friend ostream& operator<< (ostream& out, const ModularInt<T> &var) {
        out << var.value;
        return out;
    }

    // Assumes the input fits into the type of mod
    template <typename T>
    friend istream& operator>> (istream &in, ModularInt<T> &var) {
        in >> var.value;
        var.normalize();
        return in;
    }

    ModularInt& operator=(const ModularInt &rhs) {
        this->value = rhs.value;
        return *this;
    }

    template <typename U>
    ModularInt& operator=(U val) {
        this->value = this->normalize(val);
        return *this;
    }

    ModularInt operator+() {
        return ModularInt(this->value);
    }

    ModularInt operator-() {
        return ModularInt(-this->value);
    }

    ModularInt& operator+=(const ModularInt &rhs) {
        this->value = add(this->value, rhs.value);
        return *this;
    }

    ModularInt& operator-=(const ModularInt &rhs) {
        this->value = subtract(this->value, rhs.value);
        return *this;
    }

    ModularInt& operator*=(const ModularInt &rhs) {
        this->value = multiply(this->value, rhs.value);
        return *this;
    }

    ModularInt& operator/=(const ModularInt &rhs) {
        this->value = divide(this->value, rhs.value);
        return *this;
    }

    ModularInt& operator++() {
        this->value = add(this->value,type(1)%mod);
        return *this;
    }
    
    ModularInt& operator--() {
        this->value = subtract(this->value,type(1)%mod);
        return *this;
    }

    ModularInt operator++(int) {
        ModularInt result = *this;
        this->value = add(this->value,type(1)%mod);
        return result;
    }

    ModularInt operator--(int) {
        ModularInt result = *this;
        this->value = subtract(this->value,type(1)%mod);
        return result;
    }

    template <typename U>
    ModularInt power(U n) const {
        if (n == 0) {
            return ModularInt(1);
        } else if (n < 0) {
            return 1 / power(-n);
        } else {
            ModularInt result = this->value;
            result *= result;
            if (n % 2 == 1)
                return this->value * result;
            return result;
        }
    }

    template <typename U>
    operator U() const {
        return U(this->value);
    }

    template <typename T>
    friend ModularInt<T> operator+(const ModularInt<T> &lhs, const ModularInt<T> &rhs) {
        ModularInt<T> result;
        result.add(lhs.value, rhs.value, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator+(const ModularInt<T> &lhs, U rhs) {
        ModularInt<T> result;
        type rhs_normalized = result.normalize(rhs);
        result.add(lhs.value, rhs_normalized, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator+(U lhs, const ModularInt<T> &rhs) {
        return rhs + lhs;
    }

    template <typename T>
    friend ModularInt<T> operator-(const ModularInt<T> &lhs, const ModularInt<T> &rhs) {
        ModularInt<T> result;
        result.subtract(lhs.value, rhs.value, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator-(const ModularInt<T> &lhs, U rhs) {
        ModularInt<T> result;
        type rhs_normalized = result.normalize(rhs);
        result.subtract(lhs.value, rhs_normalized, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator-(U lhs, const ModularInt<T> &rhs) {
        ModularInt<T> result;
        type lhs_normalized = result.normalize(lhs);
        result.subtract(lhs_normalized, rhs.value, result.value);
        return result;
    }

    template <typename T>
    friend ModularInt<T> operator*(const ModularInt<T> &lhs, const ModularInt<T> &rhs) {
        ModularInt<T> result;
        result.multiply(lhs.value, rhs.value, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator*(const ModularInt<T> &lhs, U rhs) {
        ModularInt<T> result;
        type rhs_normalized = result.normalize(rhs);
        result.multiply(lhs.value, rhs_normalized, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator*(U lhs, const ModularInt<T> &rhs) {
        return rhs * lhs;
    }

    template <typename T>
    friend ModularInt<T> operator/(const ModularInt<T> &lhs, const ModularInt<T> &rhs) {
        ModularInt<T> result;
        result.divide(lhs.value, rhs.value, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator/(const ModularInt<T> &lhs, U rhs) {
        ModularInt<T> result;
        type rhs_normalized = result.normalize(rhs);
        result.divide(lhs.value, rhs_normalized, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator/(U lhs, const ModularInt<T> &rhs) {
        ModularInt<T> result;
        type lhs_normalized = result.normalize(lhs);
        result.divide(lhs_normalized, rhs.value, result.value);
        return result;
    }
};

template <typename T>
std::string to_string(const ModularInt<T> &var) {
    return std::to_string(var());
}

template <typename T, typename U>
U& operator+=(U &lhs, ModularInt<T> rhs) {
    return lhs += U(rhs);
}

template <typename T, typename U>
U& operator-=(U &lhs, ModularInt<T> rhs) {
    return lhs -= U(rhs);
}

template <typename T, typename U>
U& operator*=(U &lhs, ModularInt<T> rhs) {
    return lhs *= U(rhs);
}

template <typename T, typename U>
U& operator/=(U &lhs, ModularInt<T> rhs) {
    return lhs /= U(rhs);
}

// For variable mod cases:
// using MOD_TYPE = ll;
// struct VarMod {
//     static MOD_TYPE value;
// };
// MOD_TYPE VarMod::value;
// MOD_TYPE &mod = VarMod::value;
// using mint = ModularInt<VarMod>;

const int mod = 998244353;
using mint = ModularInt<std::integral_constant<std::decay<decltype(mod)>::type,mod>>;

#endif

#ifndef NCR_SETUP_HPP
#define NCR_SETUP_HPP
#include <vector>
#include <assert.h>
#include <climits>
const long long maxn = (long long)3e5 + 10ll;
const bool MOD_ENABLE = true;
// ALL FACTORIALS, INVERSE_FACTORIALS AND NCRS MUST BE < LLONG_MAX WHEN MOD_ENABLE == false
const long long mod2 = (MOD_ENABLE?(long long)998244353:LLONG_MAX);
std::vector<long long> factorial(maxn), inverse_factorial(maxn);

long long inv(long long n) {
    if (n <= 1) return 1;
    return ((mod2-mod2/n)*inv(mod2%n))%mod2;
}

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    factorial[0] = factorial[1] = 1;
    inverse_factorial[0] = inverse_factorial[1] = 1;
    for (long long f = 2; f < maxn; f++) {
        factorial[f] = (factorial[f-1]*f)%mod2;
        inverse_factorial[f] = (inverse_factorial[f-1]*inv(f))%mod2;
    }
}

ll ncr(long long n, long long r) {
    debug(n,'c',r);
    assert(maxn > n && n >= r && r >= 0ll);
    ll nccr = ll((((factorial[n]*inverse_factorial[r])%mod2)*inverse_factorial[n-r])%mod2);
    debug(nccr,endl);
    return nccr;
}
#endif

void solve() {
    init();
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll mx = *max_element(all(a)), mn = *min_element(all(a));
    if (n == 2) {
        assert(mx == mn && mx == 1);
        cout << "3\n";
        return;
    }
    if (mx == mn && mx == n-1) {
        cout << "1\n";
        return;
    }
    if (mx == mn) {
        if (mx > n/2ll) return void(cout << "0\n");
        // assert(mx <= n/2ll);
        ll sol = (ncr(n,mx) * ncr(n-1,mx-1))%mod2;
        cout << sol << endl;
        return;
    }
    if (mn != mx-1) {
        cout << "0\n";
        return;
    }
    ll dist = mx, unq = 0, rp = 0ll;
    rep(i,n)
        if (a[i] == mn) unq++;
        else rp++;
    if (unq >= dist || unq == 0) return void(cout << "0\n");
    // assert(unq < dist);
    // assert(unq > 0);
    ll rem = n-unq, v = dist-unq;
    if (rem <= v || rem != rp) return void(cout << "0\n");
    ll sol = (((ncr(n,dist)*ncr(dist,unq))%mod2)*ncr(rem-1,v-1))%mod2;
    cout << sol << endl;
}