class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
    int l=0,r=0,maxlen=0;
    unordered_map<char,int>mp;
    while(r<s.size()){
        if(mp.find(s[r])!=mp.end()){
            if(mp[s[r]]>=l){
                l=mp[s[r]]+1;
            }
        }
        mp[s[r]]=r;
       
        maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;

   }
};