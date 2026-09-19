class Solution {
private:
      bool isPossible(int k ,vector<int>& piles,int h){
        int sum=0;
        for(int i=0;i<piles.size();i++){
               sum+=((piles[i]+k-1)/k);
               if(sum>h) return false;
        }
        return true;
      }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int mid=low+(high-low)/2;
        int ans;
        while(low<=high){
            if(isPossible(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
            mid=low+(high-low)/2;
        }
        return ans;
    }
};