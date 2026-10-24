class Solution {
public:
vector<int>nse(vector<int>&nums){
    stack<int>st;
    int n=nums.size();
    vector<int>ans(n);
    for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty() && nums[i]<=nums[st.top()]){
                      st.pop();
        }
        ans[i]=st.empty()?nums.size():st.top();
        st.push(i);
    }
    return ans;
}
vector<int>psee(vector<int>&nums){
    stack<int>st;
    int n=nums.size();
    vector<int>ans(n);
    for(int i=0;i<nums.size();i++){
        while(!st.empty() && nums[i]<nums[st.top()]){
                      st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}
vector<int>nge(vector<int>&nums){
    stack<int>st;
    int n=nums.size();
    vector<int>ans(n);
    for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty() && nums[i]>=nums[st.top()]){
                      st.pop();
        }
        ans[i]=st.empty()?nums.size():st.top();
        st.push(i);
    }
    return ans;
}
vector<int>pgee(vector<int>&nums){
    stack<int>st;
    int n=nums.size();
    vector<int>ans(n);
    for(int i=0;i<nums.size();i++){
        while(!st.empty() && nums[i]>nums[st.top()]){
                      st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}

   long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int>NGE=nge(arr);
        vector<int>PGEE=pgee(arr);
        long long ans=0;
       
        for(int i=0;i<arr.size();i++){
            int left=i-PGEE[i];
            int right=NGE[i]-i;
            ans=ans+right*left*1LL*arr[i];
        }
        return ans;
    }
     
     long long sumSubarrayMins(vector<int>& arr) {
        vector<int>NSE=nse(arr);
        vector<int>PSE=psee(arr);
        long long ans=0;
        
        for(int i=0;i<arr.size();i++){
            int left=i-PSE[i];
            int right=NSE[i]-i;
            ans=ans+right*left*1LL*arr[i];
        }
        return ans;
    }
    

    long long subArrayRanges(vector<int>& nums) {
        
        return  sumSubarrayMaxs(nums)- sumSubarrayMins(nums);
    }
};