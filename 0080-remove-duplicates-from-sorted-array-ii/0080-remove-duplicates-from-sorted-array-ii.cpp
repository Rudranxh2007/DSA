class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0,count=0;
        while(j<nums.size()){
            int curr=nums[j];
            int subcount=0;
            while(j<nums.size() && nums[j]==curr ) {
                if(subcount<2){
                  nums[i]=nums[j];
                subcount++;
                i++;
                }
            j++;
            }
            count+=subcount;
           
            
        }
        return count;
    }
};