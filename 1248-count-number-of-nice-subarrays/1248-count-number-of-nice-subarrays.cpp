class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int l=0,r=0,cnt=0,sum=0;
        while(r<nums.size()){
            if(nums[r]%2!=0) cnt++;
            while(cnt>k){
                if(nums[l]%2!=0) cnt--;
                l++;
            }
            if(cnt<=k) sum+=r-l+1;
           r++;
        }
        return sum;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
           return atmost(nums,k)-atmost(nums,k-1);
    }
};