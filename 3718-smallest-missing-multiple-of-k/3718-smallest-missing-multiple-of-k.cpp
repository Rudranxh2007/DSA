class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++){
        if(nums[i]%k==0)
        mp[nums[i]]++;
       } 
       int ans=0;
       int i;
       for( i=k;i<=100;i+=k){
        if(mp.find(i)==mp.end()){
          ans=i;
       break;
        }
       }
       if(ans==0) ans=i;
       return ans;
    }
};