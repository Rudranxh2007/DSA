class Solution {
    
public:
   static int digitSum(int num){
        int ans=0;
        while(num!=0){
           ans+=num%10;
            num/=10;
        }
        return ans;
    }
   static bool cmp(int a ,int b){
        int x=digitSum(a);
        int y=digitSum(b);
        if(x==y) return a<b;
        return x<y;
    }
    int minSwaps(vector<int>& nums) {

        
         int n = nums.size();

        vector<int> temp = nums;
        sort(temp.begin(), temp.end(),cmp);

        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[temp[i]] = i;
        }
        int sum=0;

       vector<int>visited(n,false);
       for(int i=0;i<nums.size();i++){
           if(visited[i] || mp[nums[i]]==i) continue;
           int swaps=0;
           int j=i;
           while(!visited[j]){
               visited[j]=true;
               j=mp[nums[j]];
               swaps++;
           }
           sum+=swaps-1;
           
       }
        return sum;

    }
};