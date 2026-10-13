class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>s;
        for(int x: nums) s.insert(x);
        map<int,int>mp;
        int r=0,l=0,count=0;
        int ans=0;
        while(r<nums.size()){
             mp[nums[r]]++;
             while(mp.size()==s.size()){
                ans+=(nums.size()-r);
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
             }
             r++;

        }

        return ans;
    }
};