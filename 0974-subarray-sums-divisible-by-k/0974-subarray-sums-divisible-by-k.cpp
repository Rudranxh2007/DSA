class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int ans=0,sum=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find((sum%k+k)%k)!=mp.end()){
                ans+=mp[(sum%k+k)%k];
                
            }
            mp[(sum%k+k)%k]++;
        }
        return ans;
    }
};