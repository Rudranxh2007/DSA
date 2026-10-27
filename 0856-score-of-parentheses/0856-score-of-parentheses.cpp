class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int count=0;
        int total=0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                st.push(count);
                count=0;
                
            }else {
                    int prev=st.top();
                    st.pop();
                if(count==0){
                    count=prev+1;
                }
                else{
                    int curscore=2*count;
                    count=prev+curscore;
                }
            }
        }

        return count;
    }
};