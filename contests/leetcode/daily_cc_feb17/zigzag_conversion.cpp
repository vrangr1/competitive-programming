#include <stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ans = "";
        bool down = false;
        for (int j = 0; j < s.size(); j+= 2*(numRows -1)) ans.push_back(s[j]);
        for (int i = 1; i < numRows - 1; ++i){
            int increment;
            down = false;
            for (int j = i; j < s.size(); j+= increment){
                down = !down;
                if (down) increment = numRows - i - 1;
                else increment = i;
                increment *= 2;
                ans.push_back(s[j]);
            }
        }
        for (int j = numRows - 1; j < s.size(); j+= 2*(numRows -1)) ans.push_back(s[j]);
        return ans;
    }
};


int main(){
    // Do nothing; class based solution: leetcode
    return 0;
}