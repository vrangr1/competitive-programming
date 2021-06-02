/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <bits/stdc++.h>

using namespace std;

#define bline "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forsn(i, st_val, n) for (int i = st_val; i <= n; ++i)

typedef long long int ll;


inline bool lang(char ch){
	return (ch >= 'a' && ch <= 'm');
}


inline bool lang2(char ch){
	return (ch >= 'N' && ch <= 'Z');
}


bool check_word(string word){
	int n = word.length();
	bool lg = lang(word[0]);
	for (int i = 0; i < n; ++i){
		if (!(lg? lang(word[i]) : lang2(word[i])))
			return false;
	}
	return true;
}


int main(){
	fastIO;
	int T;
	cin >> T;
	while(T--){
		int k;
		cin >> k;
		string words[k];
		bool chef = true;
		forn(i, k){
			cin >> words[i];
			chef = chef && (check_word(words[i]));
		}
		if (chef){
			cout << "YES\n";
		}
		else
			cout << "NO\n";

	}
	return 0;
}