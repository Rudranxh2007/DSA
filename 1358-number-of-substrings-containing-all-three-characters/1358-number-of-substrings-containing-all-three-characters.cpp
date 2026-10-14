class Solution {
public:
    int numberOfSubstrings(string s) {
         int ans=0;
         map<char,int>mp;
         int r=0,l=0;
         while(r<s.size()){
            mp[s[r]]++;
            while(mp.size()==3){
                ans+=(s.size()-r);
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            r++;
         }
         return ans;
    }
};