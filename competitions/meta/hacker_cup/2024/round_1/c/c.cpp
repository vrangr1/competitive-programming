/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Sat Oct  5 23:00:26 IST 2024
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
void solve(int test_case);

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
        normalize(static_cast<__uint128_t>(lhs) * static_cast<__uint128_t>(rhs)))

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

    pair<type,type> inverse(type a, type b) const {
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
        if (typeid(U) == typeid(ModularInt))
            return this->power(__int128_t(n));
        if (n == 0) {
            return ModularInt(1);
        } else if (n < 0) {
            return 1 / this->power(-n);
        } else {
            ModularInt result = this->value;
            result *= result;
            if (n % 2 == 1)
                return this->value * result.power(n/2);
            return result.power(n/2);
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

const int mod = 998244353;
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
	int T;cin>>T;rep(t,T)solve(t+1);
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve(int test_case) {
    cout << "Case #" << test_case << ": ";
    ll w, g, l; cin >> w >> g >> l;
    mint m = 2ll*l + 1ll;
    mint sol = m * mint(w-g);
    cout << sol << endl;
}