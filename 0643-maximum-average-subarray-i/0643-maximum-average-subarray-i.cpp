class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=-1e18;
        int r=0,l=0,n=nums.size();
        int sum=0;
        double avg=0;
        if(nums.size()==1){
            avg=(double)nums[0];
            return avg;
        }
        while(r<n){
             sum+=nums[r];
            if(r-l+1>k){
                sum-=nums[l];
                l++;
            }
            if(r-l+1==k){
            avg=(double)sum/(r-l+1);
            ans=max(avg,ans);
            }
            r++;
        }
        return ans;
    }
};