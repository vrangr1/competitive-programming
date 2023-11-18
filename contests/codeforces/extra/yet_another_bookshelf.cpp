#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n, b, c1, c2, ch;
    cin >> T;
    for (int test = 0; test < T; ++test){
        cin >> n;
        ch = 0;
        c1 = 0;
        c2 = 0;
        for (int i = 0; i < n; ++i){
            cin >> b;
            if (b == 1 && ch == 0){
                ch = 1;
            }
            else if (b == 1){
                c1 = c2;
                continue;
            }
            else if (b == 0 && ch == 1){
                c2++;
            }
        }
        cout << c1;
        if (test != T-1)
            cout << endl;
    }
	return 0;
}

