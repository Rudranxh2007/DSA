class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size());
        stack<pair<int,int>>st;
        for(int i =temperatures.size()-1;i>=0;i--){
            while(!st.empty() && st.top().first <=temperatures[i]){
                st.pop();
            }
            ans[i]=st.empty()?0:st.top().second-i;
            st.push({temperatures[i],i});
        }
        return ans;
    }
};