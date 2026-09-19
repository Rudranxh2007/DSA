class Solution {
    private :
    bool isPossible(int val,vector<int>&arr,long long k){
               long long sum=0;
               for(int x:arr){ sum+=(x/val);
               if(sum>=k) return true;
               }
               return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=0;
        for(int x:candies) sum+=x;

        if(sum<k) return 0;

        int low=1,high=sum;
        int mid=low+(high-low)/2;
        int ans;

        while(low<=high){
            if(isPossible(mid,candies,k)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
            mid=low+(high-low)/2;
        }

        return ans;
    }
};