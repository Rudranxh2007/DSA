class Solution {
public:
    int maxVowels(string s, int k) {
        map<char,int>mp={{'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};
     int count=0,l=0,maxC=0;

        for(int r=0;r<s.size();r++){
            if(mp.find(s[r])!=mp.end()){
                count++;
            }
            if(r-l+1>k){
                if(mp.find(s[l])!=mp.end()){
                    count--;
                }
                l++;
            }
            if(r-l+1==k)
            maxC=max(maxC,count);
            
        }
        return maxC;
        
    }
};