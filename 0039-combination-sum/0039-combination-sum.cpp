class Solution {
    vector<vector<int>>ans;
    private:
    void Solve(int ind,vector<int>&candidates,vector<int>&num,int sum,int temp){
  
        if(temp==sum){
         ans.push_back(num);
         return;
        }
        if(ind == candidates.size() || temp > sum) {
            return;
        }
    
    num.push_back(candidates[ind]);
    temp+=candidates[ind];
    Solve(ind,candidates,num,sum,temp);
    temp-=candidates[ind];
    num.pop_back();
    Solve(ind+1,candidates,num,sum,temp);
    
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
    Solve(0,candidates,v,target,0);
    return ans;
        
    }
};