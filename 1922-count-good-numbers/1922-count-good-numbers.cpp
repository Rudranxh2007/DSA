class Solution {
   const  long long MOD = 1000000007;
private:
    long long myPow(long long x, long long n) {
     
     if(n==0)
        return 1;
 
     long long ans = myPow(x,n/2);
     if(n%2==0)
     return (ans*ans)%MOD;
     else return (x*ans%MOD*ans)%MOD;

    }
public:
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;

       long long first=myPow(5,even)%MOD;
       long long second=myPow(4,odd)%MOD;
        return (int) ((first*second)%MOD);
    }
};