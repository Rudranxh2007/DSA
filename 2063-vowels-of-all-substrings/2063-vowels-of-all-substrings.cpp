class Solution {
public:
    long long countVowels(string word) {
        long long ans=0;
        int r=0,l=0,n=word.size();
        for(int i=0;i<n;i++){
            if(word[i]=='a' || word[i]=='i' || word[i]=='o' || word[i]=='e' || word[i]=='u'){
                ans+=1LL*(i+1)*(n-i);
            }
        }
        return ans;
    }
};