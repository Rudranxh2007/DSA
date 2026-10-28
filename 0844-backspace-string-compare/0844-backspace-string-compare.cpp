class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size();
        int m=t.size();
        stack<int>st;
        stack<int>st2;
        for(int i =0;i<n;i++){
            if(s[i]=='#'){
                if(!st.empty()) st.pop();
                continue;
            }
            st.push(s[i]);
        }
         for(int i =0;i<m;i++){
            if(t[i]=='#'){
                if(!st2.empty()) st2.pop();
                continue;
            }
            st2.push(t[i]);
        }
        while(!st.empty() && !st2.empty()){
            if(st.top()!=st2.top()) return false;
            st.pop();
            st2.pop();
        }
        return st.empty() && st2.empty();
        
    }
};