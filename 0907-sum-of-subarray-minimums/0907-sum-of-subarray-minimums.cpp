class Solution {
public:
     vector<int>nse(vector<int>&arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        return ans;

     }
     vector<int>psee(vector<int>&arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;

     }
     
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>NSE=nse(arr);
        vector<int>PSE=psee(arr);
        int ans=0;
        long long mod =(int) 1e9+7;
        for(int i=0;i<arr.size();i++){
            int left=i-PSE[i];
            int right=NSE[i]-i;
            ans=(ans+(right*left*1LL*arr[i])%mod)%mod;
        }
        return ans;
    }
};