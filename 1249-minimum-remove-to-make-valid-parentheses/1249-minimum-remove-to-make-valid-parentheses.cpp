class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
       vector<bool>flag(s.size(),true);
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                continue;
            }
            else if(s[i]=='('){
                st.push(i);
            }
            else {
                if(st.empty()){
                   flag[i]=false;
                }
                else {
                    st.pop();
                }
            }
        }
        while(!st.empty()){
           flag[st.top()]=false;
           st.pop(); 
        }
        for(int i=0;i<s.size();i++){
            if(flag[i]) ans+=s[i];
        }
        return ans;
        
    }
};