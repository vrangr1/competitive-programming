/***************************************************
* AUTHOR : Anav Prasad
* Nick : Vrangr
****************************************************/
#include <iostream>
#include <string>
using namespace std;

#define bline "\n"

typedef long long ll;



class RPSMagicTrick {
public:
	string guess(string exampleGuess, string exampleResponse, string volunteersAction){
		bool pat;
		string inc = "AB", dec = "BA";
		string ans;
		pat = ((int)(exampleGuess[1] - exampleGuess[0]) > 0);
		if (exampleResponse == "Wrong.")
			pat = !pat;
		int len = volunteersAction.length();
		for (int i = 0; i < len; ++i){
			if (volunteersAction[i] == '?'){
				ans.append((pat?inc:dec));
			}
			else
				pat = !pat;
		}
		return ans;
	}
};

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	RPSMagicTrick one;
	string a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	// cout << "c: " << c << bline;
	// cout << "c.len: " << c.length() << bline;
	string out;
	out = one.guess(a, b, c);
	cout << out;
	return 0;
}