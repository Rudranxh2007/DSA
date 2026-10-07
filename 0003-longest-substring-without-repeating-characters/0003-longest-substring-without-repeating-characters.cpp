class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int r=0,l=0,maxlen=0;
     map<char,int>mp;

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