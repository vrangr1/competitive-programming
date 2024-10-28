/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sun Sep 29 21:47:49 IST 2024
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

#ifndef MODULAR_INT_SNIPPET
#define MODULAR_INT_SNIPPET

#include <string>
#include <vector>
#include <assert.h>

#define IS_SMALL_INT_TYPE(T) ( \
    std::is_same<T, int>::value || \
    std::is_same<T, int32_t>::value || \
    std::is_same<T, unsigned int>::value || \
    std::is_same<T, int16_t>::value || \
    std::is_same<T, short int>::value || \
    std::is_same<T, int8_t>::value )
#define OVERFLOW_MULTIPLY(T, lhs, rhs) \
    (IS_SMALL_INT_TYPE(T) ? \
        normalize(static_cast<int64_t>(lhs) * static_cast<int64_t>(rhs)) : \
        normalize(static_cast<__int128_t>(lhs) * static_cast<__int128_t>(rhs)))

// Based on ACL's modint header and tourist's Modular class.
template <typename MOD>
class ModularInt {
private:
    using type = typename decay<decltype(MOD::value)>::type;
    const type mod = MOD::value;
    type value;

    template <typename T>
    inline type normalize(T val) const {
        val %= T(mod);
        return type((val >= 0) ? val : val + mod);
    }

    // Not done value = (value%mod + mod)%mod because mod-1+mod maybe > inf
    inline void normalize() {
        this->value = (this->value > 0) ? this->value % mod : (this->value % mod + this->mod);
    }
    
    // Assumes 0 <= lhs < mod, 0 <= rhs < mod
    void add(type lhs, type rhs, type &result) const {
        if (__builtin_add_overflow(lhs, rhs, &result)) {
            if (lhs > rhs) swap(lhs, rhs);
            result = lhs + (this->mod - rhs); // ensures 0 <= result <= mod
        }
        if (result >= mod) result -= mod;
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
            result = OVERFLOW_MULTIPLY(type, lhs, rhs);
        else
            result = normalize(result);
    }

    // Assumes 0 <= lhs < mod, 0 <= rhs < mod
    type multiply(type lhs, type rhs) const {
        type result;
        multiply(lhs, rhs, result);
        return result;
    }

    // Assumes 1 <= x < mod
    // Taken directly from tourist's code
    // Source: https://codeforces.com/contest/1992/submission/269939496
    type inverse(type x) const {
        type u = 0, v = 1, m = mod;
        while (x != 0) {
            type t = m / x;
            m -= t * x;
            swap(x, m);
            u -= t * v;
            swap(u, v);
        }
        assert(m == 1);
        return u;
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
    ModularInt(const U val) {
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
    ModularInt& operator=(const U val) {
        this->value = this->normalize(val);
        return *this;
    }

    ModularInt operator+() const {
        return ModularInt(this->value);
    }

    ModularInt operator-() const {
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
    ModularInt power(const U n) const {
        ModularInt result = 1, base = this->value;
        typename std::conditional<std::is_integral<U>::value, U, type>::type exponent = [&]() {
            if constexpr (std::is_integral<U>::value) {
                return n;
            } else {
                return n();
            }
        }();
        while (exponent > 0) {
            if (exponent % 2)
                result *= base;
            base *= base;
            exponent /= 2;
        }
        return result;
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
    friend ModularInt<T> operator+(const ModularInt<T> &lhs, const U rhs) {
        ModularInt<T> result;
        type rhs_normalized = result.normalize(rhs);
        result.add(lhs.value, rhs_normalized, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator+(const U lhs, const ModularInt<T> &rhs) {
        return rhs + lhs;
    }

    template <typename T>
    friend ModularInt<T> operator-(const ModularInt<T> &lhs, const ModularInt<T> &rhs) {
        ModularInt<T> result;
        result.subtract(lhs.value, rhs.value, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator-(const ModularInt<T> &lhs, const U rhs) {
        ModularInt<T> result;
        type rhs_normalized = result.normalize(rhs);
        result.subtract(lhs.value, rhs_normalized, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator-(const U lhs, const ModularInt<T> &rhs) {
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
    friend ModularInt<T> operator*(const ModularInt<T> &lhs, const U rhs) {
        ModularInt<T> result;
        type rhs_normalized = result.normalize(rhs);
        result.multiply(lhs.value, rhs_normalized, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator*(const U lhs, const ModularInt<T> &rhs) {
        return rhs * lhs;
    }

    template <typename T>
    friend ModularInt<T> operator/(const ModularInt<T> &lhs, const ModularInt<T> &rhs) {
        ModularInt<T> result;
        result.divide(lhs.value, rhs.value, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator/(const ModularInt<T> &lhs, const U rhs) {
        ModularInt<T> result;
        type rhs_normalized = result.normalize(rhs);
        result.divide(lhs.value, rhs_normalized, result.value);
        return result;
    }

    template <typename T, typename U>
    friend ModularInt<T> operator/(const U lhs, const ModularInt<T> &rhs) {
        ModularInt<T> result;
        type lhs_normalized = result.normalize(lhs);
        result.divide(lhs_normalized, rhs.value, result.value);
        return result;
    }

    template <typename T>
    friend ModularInt<T> operator%(const ModularInt<T> &lhs, const ModularInt<T> &rhs) {
        assert(rhs.value != 0);
        return ModularInt<T>(lhs.value % rhs.value);
    }

    template <typename T, typename U>
    friend U operator%(const ModularInt<T> &lhs, const U rhs) {
        return U(lhs.value) % rhs;
    }

    template <typename T, typename U>
    friend U operator%(const U lhs, const ModularInt<T> &rhs) {
        return lhs % U(rhs);
    }

    template <typename T>
    friend bool operator<(const ModularInt<T> lhs, const ModularInt<T>rhs) {
        return lhs.value < rhs.value;
    }

    template <typename T>
    friend bool operator>(const ModularInt<T> lhs, const ModularInt<T> rhs) {
        return lhs.value > rhs.value;
    }

    template <typename T>
    friend bool operator<=(const ModularInt<T> lhs, const ModularInt<T> rhs) {
        return lhs.value <= rhs.value;
    }

    template <typename T>
    friend bool operator>=(const ModularInt<T> lhs, const ModularInt<T> rhs) {
        return lhs.value >= rhs.value;
    }

    template <typename T, typename U>
    friend bool operator<(const ModularInt<T> lhs, const U rhs) {
        return lhs < ModularInt<T>(rhs);
    }

    template <typename T, typename U>
    friend bool operator<(const U lhs, const ModularInt<T> rhs) {
        return ModularInt<T>(lhs) < rhs;
    }

    template <typename T, typename U>
    friend bool operator>(const ModularInt<T> lhs, const U rhs) {
        return lhs > ModularInt<T>(rhs);
    }

    template <typename T, typename U>
    friend bool operator>(const U lhs, const ModularInt<T> rhs) {
        return ModularInt<T>(lhs) > rhs;
    }

    template <typename T, typename U>
    friend bool operator<=(const ModularInt<T> lhs, const U rhs) {
        return lhs <= ModularInt<T>(rhs);
    }

    template <typename T, typename U>
    friend bool operator<=(const U lhs, const ModularInt<T> rhs) {
        return ModularInt<T>(lhs) <= rhs;
    }

    template <typename T, typename U>
    friend bool operator>=(const ModularInt<T> lhs, const U rhs) {
        return lhs >= ModularInt<T>(rhs);
    }

    template <typename T, typename U>
    friend bool operator>=(const U lhs, const ModularInt<T> rhs) {
        return ModularInt<T>(lhs) >= rhs;
    }

    template <typename T>
    friend bool operator==(const ModularInt<T> lhs, const ModularInt<T> rhs) {
        return lhs.value == rhs.value;
    }

    template <typename T, typename U>
    friend bool operator==(const ModularInt<T> lhs, const U rhs) {
        return lhs == ModularInt<T>(rhs);
    }

    template <typename T, typename U>
    friend bool operator==(const U lhs, const ModularInt<T> rhs) {
        return ModularInt<T>(lhs) == rhs;
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
// using MOD_TYPE = int;
// struct VarMod {
//     static MOD_TYPE value;
// };
// MOD_TYPE VarMod::value;
// MOD_TYPE &mod = VarMod::value;
// using mint = ModularInt<VarMod>;

constexpr int mod = int(1e9) + 7;
using mint = ModularInt<std::integral_constant<std::decay<decltype(mod)>::type,mod>>;

// #define USE_NCR
#ifdef USE_NCR
const int NCR_MAX = int(1e5)+10;
bool NCR_SETUP = false;
std::vector<mint> factorial;

void ncr_setup() {
    if (NCR_SETUP) return;
    NCR_SETUP = true;
    factorial.assign(NCR_MAX,mint(0));
    factorial[0] = factorial[1] = 1;
    for (int f = 2; f < NCR_MAX; ++f)
        factorial[f] = factorial[f-1]*f;
}

mint ncr(int n, int r) {
    ncr_setup();
    return factorial[n]/(factorial[n-r]*factorial[r]);
}
#endif
#endif

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

const mint t4 = 10000;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<mint> p(n);
    rep(i,n) {
        cin >> p[i];
        p[i]/=t4;
    }
    vector<vector<vector<mint>>> dp(10,vector<vector<mint>>(10,vector<mint>(2)));
    rep(b1,10) {
        rep(b2,10) {
            int v1 = (1<<b1), v2 = (1<<b2);
            array<mint, 4> cur = {1,0,0,0};
            rep(i,n) {
                array<mint,4> nxt;
                int v = (((a[i]&v1) > 0)<<1) + ((a[i]&v2) > 0);
                rep(j,4)
                    nxt[j] = cur[j^v]*p[i] + cur[j]*(1-p[i]);
                swap(cur,nxt);
            }
            dp[b1][b2][0] = cur[0]+cur[1]+cur[2];
            dp[b1][b2][1] = cur[3];
        }
    }
    mint sol = 0;
    rep(i,10)
        rep(j,10)
            sol += mint((1<<(i+j)))*dp[i][j][1];
    cout << sol << endl;
}