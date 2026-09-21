class Solution {
public:
    int calculate(string s) {
     stack<int>st;
     long long result=0;
     int sign=1;
     long long num=0;
     for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            num=0;
            while(i<s.size() && isdigit(s[i])){
                num=num*10+(s[i]-'0');
                i++;
            }
            result+=num*sign;
            num=0;
            i--;
        }
        else if(s[i]=='+'){
            sign=1;
        }
        else if(s[i]=='-'){
          sign=-1;
        }
        else if(s[i]=='('){
            st.push(sign);
            st.push(result);
            result=0;
            sign=1;
        }
        else if(s[i]==')'){
            int prevResult=st.top();
            st.pop();

            int prevSign=st.top();
            st.pop();
            result=prevResult+result*prevSign;
        }
     }   
     return result;
    }
};