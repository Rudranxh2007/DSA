class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if (words.empty() || s.empty())
            return ans;

        int wordLen = words[0].size();
        int totalWords = words.size();
        int totalLen = wordLen * totalWords;

        if (s.size() < totalLen)
            return ans;

        // Required words ki frequency
        unordered_map<string, int> wordCount;

        for (string word : words) {
            wordCount[word]++;
        }

        // Har possible alignment se sliding window chalayenge
        for (int offset = 0; offset < wordLen; offset++) {

            unordered_map<string, int> windowCount;

            int l = offset;
            int r = offset;
            int count = 0;

            while (r + wordLen <= s.size()) {

                string word = s.substr(r, wordLen);
                r += wordLen;

                // Agar word required map mein nahi hai
                if (wordCount.find(word) == wordCount.end()) {
                    windowCount.clear();
                    count = 0;
                    l = r;
                    continue;
                }

                windowCount[word]++;
                count++;

                // Extra occurrence ko remove karo
                while (windowCount[word] > wordCount[word]) {
                    string leftWord = s.substr(l, wordLen);

                    windowCount[leftWord]--;
                    count--;
                    l += wordLen;
                }

                // Saare required words mil gaye
                if (count == totalWords) {
                    ans.push_back(l);

                    // Next possible window ke liye left se ek word hatao
                    string leftWord = s.substr(l, wordLen);
                    windowCount[leftWord]--;
                    count--;
                    l += wordLen;
                }
            }
        }

        return ans;
    }
};