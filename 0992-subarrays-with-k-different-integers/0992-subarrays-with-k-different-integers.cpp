class Solution {
    int helper(vector<int>&nums,int k){
        map<int,int>mp;
        int r=0,l=0,count=0;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){
                
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            if(mp.size()<=k) count+=(r-l+1);
            r++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    return helper(nums,k)-helper(nums,k-1);
    }
};