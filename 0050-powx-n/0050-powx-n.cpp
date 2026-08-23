class Solution {
public:
    double myPow(double x, int n) {
     
     if(n==0)
        return 1;
  long long N=n;
     if(N<0){
        N=-N;
        x=1/x;
     }
     double ans = myPow(x,N/2);
     if(N%2==0)
     return ans*ans;
     else return x*ans*ans;

    }
    
};