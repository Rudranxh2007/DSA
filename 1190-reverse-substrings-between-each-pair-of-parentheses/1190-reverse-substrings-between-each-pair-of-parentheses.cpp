class Solution {
public:
    string reverse(string str){
        for(int i =0,j=str.size()-1;i<=j;i++,j--){
          swap(str[i],str[j]);
        }
        return str;
    }
    string reverseParentheses(string s) {
        stack<string>st;
        string curstr="";
        
        for(int i = 0;i<s.size();i++){
             if(s[i]>='a' && s[i]<='z') curstr+=s[i];
             else if(s[i]=='('){
                
               st.push(curstr);
                curstr="";
             }
             else{
                
                  curstr=reverse(curstr);
                //   string prev= st.top();
                //   st.pop();
                 curstr=st.top()+curstr;
                 st.pop();

                
             }
        }
        return curstr;
    }
};