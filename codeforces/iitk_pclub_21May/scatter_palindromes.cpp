#include<bits/stdc++.h>

using namespace std;


inline int get_ind(char ch){
	return (int)(ch - 'a');
}


void update(vector<vector<int>> &count, int ind, int j){
	for (int i = 0; i < 26; ++i)
		count[i][j] = count[i][j - 1];
	count[ind][j] += 1;
}


inline int get_ct(vector<vector<int>> &count, int ind, int st, int end){
	if (st > 0)
		return count[ind][end] - count[ind][st - 1];
	return count[ind][end];
}


bool check_palindrome(vector<vector<int>> &count, int st, int end){
	int len = end - st + 1;
	vector<int> charct(26, 0);
	if (len % 2 == 0){
		for (int i = 0; i < 26; ++i)
			if (get_ct(count, i, st, end) % 2 != 0)
				return false;
		return true;
	}
	else{
		bool odd = false;
		for (int i = 0; i < 26; ++i){
			if (get_ct(count, i, st, end) % 2 != 0 && !odd)
				odd = true;
			else if (get_ct(count, i, st, end) % 2 != 0)
				return false;
		}
		return true;
	}
	return true;
}


void print(vector<vector<int>> &count, int n){
	for (int i = 0; i < 26; ++i){
		cout << (char)(i + 'a') << ": ";
		for (int j = 0; j < n; ++j)
			cout << count[i][j] << " ";
		cout << endl;
	}
}


int main(){
	int n;
	string s;
	cin >> s;
	n = s.length();
	int ind;
	vector<vector<int>> count(26, vector<int>(n, 0));
	count[get_ind(s[0])][0] = 1;
	for (int i = 1; i < n; ++i){
		ind = get_ind(s[i]);
		update(count, ind, i);
	}
	int ct = n, win = 2;
	// print(count, n);
	while(win <= n){
		for(int i = 0; i < n - win + 1; ++i){
			if (check_palindrome(count, i, i + win - 1)){
				ct++;
			}
		}
		win++;
	}
	cout << ct;

	return 0;
}

