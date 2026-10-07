class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
     int r=0,l=0,sum=0,count=0;
     double avg=0;
     while(r<arr.size()){
        sum+=arr[r];
        if(r-l+1>k){
            sum-=arr[l];
            l++;
        }
        if(r-l+1==k){
          avg=(double)sum/(r-l+1);
          if(avg>=threshold){
            count++;
          }
        }
        r++;
     }   
     return count;
    }
};