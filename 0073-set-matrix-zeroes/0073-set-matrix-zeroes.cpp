class Solution {
private :
    void makethemZero(int m,int n,vector<vector<bool>>&mp,vector<vector<int>>&mat){
        for(int i=0;i<mat[0].size();i++){
            if(mat[m][i]!=0){
                mat[m][i]=0;
                mp[m][i]=true;

            }
        }
        for(int i=0;i<mat.size();i++){
            if(mat[i][n]!=0){
                mat[i][n]=0;
                mp[i][n]=true;

            }
        }
        mp[m][n]=true;
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
       vector<vector<bool>> mp(m, vector<bool>(n, false));
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0 && !mp[i][j] ){
                makethemZero(i,j,mp,matrix);
            }
        }
       }
 
    }
};