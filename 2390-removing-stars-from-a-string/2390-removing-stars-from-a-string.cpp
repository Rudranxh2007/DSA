class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        int n=s.size();

        for(int i=0;i<n;i++){
           
            if(!st.empty() && s[i]=='*'){
                st.pop();
               continue;
            }
           
            st.push(s[i]);

        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};