class Solution {
private:
    bool palin(string str) {
        int s = 0, e = str.size() - 1;

        while(s <= e) {
            if(str[s] != str[e]) {
                return false;
            }
            else {
                s++;
                e--;
            }
        }

        return true;
    }

public:
    string longestPalindrome(string s) {

        int i = 0;
        string ans = "";

        while(i < s.size()) {

            int j = s.size() - 1;

            while(j >= i) {

                if(s[i] == s[j] && ans.size() < j-i+1) {

                    if(palin(s.substr(i, j-i+1))) {
                        ans = s.substr(i, j-i+1);
                        break;
                    }
                }

                j--;
            }

            i++;
        }

        return ans;
    }
};