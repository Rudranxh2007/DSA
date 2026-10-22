class Solution {
public:
    string decodeString(string s) {
        int i=0;
        stack<string>strs;
        stack<int>nums;
        int curnum=0;
        string curstr="";
        while(i<s.size()){
            if(s[i]>='0' && s[i]<='9'){
                int digit=s[i]-'0';
                curnum=curnum*10+digit;
            }
            else if(s[i]>='a' && s[i]<='z'){
                  curstr+=s[i];
            }
            else if(s[i]=='['){
                nums.push(curnum);
                strs.push(curstr);
                curnum=0,curstr="";
            }
            else {
                string x=strs.top();
                int count=nums.top();
                strs.pop(),nums.pop();
                string ans="";
                for(int i=0;i<count;i++){
                 ans+=curstr;
                }
                curstr=x+ans;
            }
            i++;
        }
      return curstr;
    }
};