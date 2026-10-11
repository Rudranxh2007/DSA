class Solution {
public:
    bool isAnagram(string s, string t) {
    map<char,int>mp;
    if(t.size()!=s.size()) return false;
    for(char x:t){
        mp[x]++;
    }
    for(int i=0;i<s.size();i++){
        if(mp.find(s[i])!=mp.end()){
            mp[s[i]]--;
            if(mp[s[i]]==0) mp.erase(s[i]);
        }
    }
    return mp.size()==0;
    }
};