class Solution {

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> freq(26, 0);
        for (char x : s1) {
            freq[x - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++) {
            int j = i, k = 0;
            vector<int> window(26, 0);
            while (k < s1.size() && j < s2.size()) {
                window[s2[j] - 'a']++;
                k++, j++;
            }
            if (window == freq) {
                return true;
            }
        }
        return false;
    }
};