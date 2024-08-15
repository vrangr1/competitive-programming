/*
Details for snippet generator program:
title       : NCR Setup
prefix      : import_ncr
description : NCR Code Snippet
*/
#ifndef NCR_SETUP_HPP
#define NCR_SETUP_HPP
#include <vector>
#include <assert.h>
#include <climits>
const long long maxn = (long long)1e5 + 10ll;
const bool MOD_ENABLE = true;
// ALL FACTORIALS, INVERSE_FACTORIALS AND NCRS MUST BE < LLONG_MAX WHEN MOD_ENABLE == false
const long long mod = (MOD_ENABLE?(long long)1e9 + 7ll:LLONG_MAX);
std::vector<long long> factorial(maxn), inverse_factorial(maxn);

long long inv(long long n) {
    if (n <= 1) return n;
    return ((mod-mod/n)*inv(mod%n))%mod;
}

void init() {
    static bool init = false;
    if (init) return;
    init = true;
    factorial[0] = factorial[1] = 1;
    inverse_factorial[0] = inverse_factorial[1] = 1;
    for (long long f = 2; f < maxn; f++) {
        factorial[f] = (factorial[f-1]*f)%mod;
        inverse_factorial[f] = (inverse_factorial[f-1]*inv(f))%mod;
    }
}

long long ncr(long long n, long long r) {
    assert(maxn > n && n >= r && r >= 0ll);
    return (((factorial[n]*factorial[r])%mod)*inverse_factorial[n-r])%mod;
}
#endif