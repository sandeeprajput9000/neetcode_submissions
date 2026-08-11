class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,0));
        priority_queue<pair<long long,pair<long long,long long>>,vector<pair<long long,pair<long long,long long>>>,greater<pair<long long,pair<long long,long long>>>>pq;
 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    pq.push({0,{i,j}});
                    visit[i][j]=1;
                }
            }
        }

        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};

        while(!pq.empty()){
            int dist=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();

            for(int k=0;k<4;k++){
                int r=i+row[k];
                int c=j+col[k];

                if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==2147483647 && visit[r][c]==0){
                    grid[r][c]=dist+1;
                    pq.push({dist+1,{r,c}});
                    visit[r][c]=1;
                }
            }
        }

    }
};
