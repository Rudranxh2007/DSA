class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mp;
        int count=0;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
            count++;
        }
        int r=0,l=0,minlen=INT_MAX,start=0;
        while(r<s.size()){
            if(mp[s[r]]>0) count--;
            mp[s[r]]--;
            while(count==0){
               if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) count++;
              l++;
            }
            r++;
        }
        return minlen==INT_MAX?"":s.substr(start,minlen);
         
    }
};