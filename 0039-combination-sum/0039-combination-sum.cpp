class Solution {
   
    private:
    void Solve(int ind,vector<int>&candidates,vector<int>&num,int target,vector<vector<int>>&ans){
  if(candidates.size()==ind){
    if(target==0){
        ans.push_back(num);
        
    }
    return;
  }
  if(candidates[ind]<=target){
    num.push_back(candidates[ind]);
    Solve(ind,candidates,num,target-candidates[ind],ans);
    num.pop_back();
  }
    Solve(ind+1,candidates,num,target,ans);
       
    
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;

    Solve(0,candidates,v,target,ans);
    return ans;
        
    }
};