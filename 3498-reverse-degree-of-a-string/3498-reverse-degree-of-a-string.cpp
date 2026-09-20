class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int>mp(26);
        char ch ='z';
        for(int i=0;i<26;i++){
            mp[ch]=i;
            ch--;
        }
        int sum=0;
        for(int i=0;i<s.size();i++){
            int ind=mp[s[i]]+1;
            sum+=(ind*(i+1));
        }
        return sum;
    }
};