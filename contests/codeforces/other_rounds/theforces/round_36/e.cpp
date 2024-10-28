/***************************************************
* Author  : Anav Prasad
* Handle  : vrangr
* Created : Fri Oct 25 20:25:03 IST 2024
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

#if 0
// tourist's modint class:
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
 
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
 
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
 
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
 
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
 
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
 
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
 
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  friend const Type& abs(const Modular& x) { return x.value; }
 
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);
 
 private:
  Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
 
// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}
 
// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
 
// using ModType = int;
 
// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mint = Modular<VarMod>;
 
constexpr int md = int(1e9) + 7;
using mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
 
// vector<Mint> fact(1, 1);
// vector<Mint> inv_fact(1, 1);
 
// Mint C(int n, int k) {
//   if (k < 0 || k > n) {
//     return 0;
//   }
//   while ((int) fact.size() < n + 1) {
//     fact.push_back(fact.back() * (int) fact.size());
//     inv_fact.push_back(1 / fact.back());
//   }
//   return fact[n] * inv_fact[k] * inv_fact[n - k];
// }
#else

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
        assert(result >= 0 && result < mod);
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

#endif

int main() {
	fastIO;
	TEST;
#ifdef LOCAL
    cout << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<mint> a(n);
    rep(i,n) cin >> a[i];
    vector<mint> dp(n), rdp(n), prod(n);
    dp.back() = a.back();
    rep(i,n-2,0,-1)
        dp[i] = dp[i+1]*a[i] + a[i];
    rdp[0] = a[0];
    prod[0] = a[0];
    rep(i,1,n-1,1) {
        rdp[i] = rdp[i-1]*a[i] + a[i];
        prod[i] = prod[i-1]*a[i];
    }
    vector<mint> psum(n);
    partial_sum(all(dp),psum.begin());
    auto get_sum = [&](int l, int r) -> mint {
        if (l == 0) return psum[r];
        return psum[r] - psum[l-1];
    };
    auto get_prod = [&](int l, int r) -> mint {
        if (l == 0) return prod[r];
        else return prod[r]/prod[l-1];
    };
    auto get_rs = [&](int l, int r) -> mint {
        mint sol = rdp[r];
        if (l == 0) return sol;
        sol -= rdp[l-1]*get_prod(l,r);
        return sol;
    };
    debug(dp,psum,rdp,prod);
    while(q--) {
        int l, r; cin >> l >> r; --l;--r;
        mint sol = get_sum(l,n-1);
        debug(endl,sol);
        if (r != n-1) {
            sol -= get_sum(r+1,n-1);
            debug(sol,get_rs(l,r));
            sol -= dp[r+1]*get_rs(l,r);
        }
        cout << sol << endl;
    }
}