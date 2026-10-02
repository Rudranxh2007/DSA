class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,maxlen=0;
        map<int,int>s;
        while(r<fruits.size()){
            s[fruits[r]]++;
            if(s.size()>2){
                s[fruits[l]]--;

                if(s[fruits[l]] == 0)
                s.erase(fruits[l]);
                l++;

            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};