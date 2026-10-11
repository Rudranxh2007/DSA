class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>mp;
        int k=p.size();
        for(char x:p){
            mp[x]++;
        }
        int count=mp.size();
        int r=0,l=0;
        vector<int>ans;
        for(r=0;r<s.size();r++){
            if(mp.find(s[r])!=mp.end()){
                mp[s[r]]--;
                if(mp[s[r]]==0) count--;
            }
            if(r-l+1==k){
                if(count==0) ans.push_back(l);
                if(mp.find(s[l])!=mp.end()){
                    if(mp[s[l]]==0){
                        count++;
                    }
                        mp[s[l]]++;
                }
                        l++;


            }
        }
        return ans;
        
    }
};