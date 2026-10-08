class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int r=0,l=0,pro=1,count=0;
        while(r<nums.size()){
            pro*=nums[r];
         
            
            while(pro>=k){
                pro/=nums[l];
                l++;
            }
                count+=(r-l+1);
            r++;
        }
        return count;
    
    }
};