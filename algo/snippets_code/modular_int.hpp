/*
Details for snippet generator program:
title       : Modular Int Snippet
prefix      : import_modint
description : Modular Int Snippet
*/
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
    ModularInt power(const U n) const {
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
// using MOD_TYPE = ll;
// struct VarMod {
//     static MOD_TYPE value;
// };
// MOD_TYPE VarMod::value;
// MOD_TYPE &mod = VarMod::value;
// using mint = ModularInt<VarMod>;

const int mod = int(1e9) + 7;
using mint = ModularInt<std::integral_constant<std::decay<decltype(mod)>::type,mod>>;

#endif