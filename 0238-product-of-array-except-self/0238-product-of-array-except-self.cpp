class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix(nums.size());
        vector<int>suffix(nums.size());
        vector<int>ans(nums.size());
        
        int leftPro=1;
        for(int i=0;i<nums.size();i++){
              ans[i]=leftPro;
              leftPro*=nums[i];
        }
        int rightPro=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=rightPro;
            rightPro*=nums[i];
        }
        return ans;
    }
};