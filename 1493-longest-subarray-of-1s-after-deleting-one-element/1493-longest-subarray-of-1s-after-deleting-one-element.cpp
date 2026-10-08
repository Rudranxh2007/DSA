class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int r=0,l=0,maxlen=0,count=0;
        while(r<nums.size()){
            if(nums[r]!=1) count++;
          if( count>1){
            if(nums[l]==0)
            count--;
            l=l+1;
          }
         

        
        maxlen=max(maxlen,r-l+1-count);
        r++;
        }
        if(maxlen==nums.size()) maxlen-=1;
        return maxlen;
    }
};