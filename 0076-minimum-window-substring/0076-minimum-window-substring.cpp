class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int count=0;  
        for(char x : t) mp[x]++,count++;
        int r=0,l=0,minLen=INT_MAX;
        int start=0;
        while(r<s.size()){
            if(mp[s[r]]>0) count--;
            mp[s[r]]--;
            while(count==0){
                if(minLen>r-l+1){
                    minLen=r-l+1;
                    start=l;
                }
                
                    mp[s[l]]++;
                    if(mp[s[l]]>0)
                    count++;
                
                l++;

            }
            r++;
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};