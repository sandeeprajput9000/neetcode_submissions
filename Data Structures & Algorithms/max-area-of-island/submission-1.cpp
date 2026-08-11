class Solution {
public:

 void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&Visit,int & cnt){
       int n=grid.size();
        int m=grid[0].size();
        Visit[i][j]=1;

        int row[4]={-1,0,1,0};
        int col[4]={0,1,0,-1};


        for(int k=0;k<4;k++){
            int r=i+row[k];
            int c=j+col[k];
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 &&Visit[r][c]==0){
                 cnt++;
                 dfs(r,c,grid,Visit,cnt);
            }
         }
    }
  
   int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>Visit(n,vector<int>(m,0));
       
         int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && Visit[i][j]==0){
                    int cnt=1;
                    dfs(i,j,grid,Visit,cnt);
                     maxi=max(maxi,cnt);
                }
            }
        }
       
            return maxi==INT_MIN ? 0 : maxi;
    }
    
        
    
};
