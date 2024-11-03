#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k, x; cin >> n >> k >> x;
    if (k == 0) {
        if (x == 0) cout << "YA\n";
        else cout << "TIDAK\n";
        return 0;
    }
    if (x < 0) x = -x;
    assert(n >= 1);
    assert(k >= 0);
    assert(x >= 0);
    if (((x+k-1ll)/k) <= n) cout << "YA\n";
    else cout << "TIDAK\n";
    return 0;
}