#ifndef IMPORT_HASH_SET_SNIPPET
#define IMPORT_HASH_SET_SNIPPET
#include <type_traits>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
typedef long long int ll;
using namespace std;

// Source: Neal Wu (codeforces handle: neal)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename type>
using hash_set = conditional_t <is_same<type,int>::value || is_same<type,ll>::value, unordered_set<type, custom_hash>, unordered_set<type>>;

template<typename t1, typename t2>
using hash_map = conditional_t<is_same<t1,ll>::value || is_same<t1,int>::value, unordered_map<t1, t2, custom_hash>, unordered_map<t1,t2>>;

template <typename type>
using hash_multiset = conditional_t<is_same<type,int>::value || is_same<type,ll>::value, unordered_multiset<type, custom_hash>, unordered_multiset<type>>;

template<typename t1, typename t2>
using hash_multimap = conditional_t<is_same<t1,int>::value || is_same<t2,ll>::value, unordered_multimap<t1, t2, custom_hash>, unordered_multimap<t1,t2>>;

#endif // IMPORT_HASH_SET_SNIPPET