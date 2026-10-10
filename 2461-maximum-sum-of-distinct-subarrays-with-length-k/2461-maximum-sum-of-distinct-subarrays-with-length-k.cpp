class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        long long r=0,l=0,maxsum=0,sum=0;
        while(r<nums.size()){
            
            
                mp[nums[r]]++;
                sum+=nums[r];
                if(r-l+1>k){
                    sum-=nums[l];
                    mp[nums[l]]--;
                    if(mp[nums[l]]==0) mp.erase(nums[l]);
                    l++;
                }
                if(r-l+1==k && mp.size()==k)
                    maxsum=max(maxsum,sum);
                

            
                    r++;
        }
        return maxsum;
    }
};