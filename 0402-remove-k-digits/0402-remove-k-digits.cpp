class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k>=n){
            return "0";
        }
        stack<char>st;
        for(int i =0;i<n;i++){
            while(!st.empty() && k>0 && (num[i]-'0') < (st.top()-'0') ){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
      while( !st.empty() && k>0){
        st.pop();
        k--;

      }
      if(st.empty()) return "0";
      string ans="";
      while(!st.empty()){
        ans+=st.top();
        st.pop();
      }
      reverse(ans.begin(),ans.end());
      int j=0;
      while(j<ans.size() && ans[j]=='0'){
         j++;
      }
      ans=ans.substr(j);
      if(ans.size()==0) return "0";
      return ans;

    }
};