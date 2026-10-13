class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int lastmax=-1,lastmin=-1,lastbad=-1;
        long long ans=0;
      for(int i=0;i<nums.size();i++){
        if(nums[i]<minK || nums[i]>maxK) lastbad=i;
        if(nums[i]==maxK) lastmax=i;
        if(nums[i]==minK ) lastmin=i;

        ans+=max(0,min(lastmin,lastmax)-lastbad);

      }
      return ans;
    }
};