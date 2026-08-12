class Solution {
public:
  void dfs(int i,int j,vector<vector<char>>& board, vector<vector<bool>>&visit){
     int n=board.size();
     int m=board[0].size();
     visit[i][j]=1;

    int row[]={-1,0,1,0};
    int col[]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int r=i+row[k];
        int c=j+col[k];

        if(r>=0 && r<n && c>=0 && c<m && board[r][c]=='O' && visit[r][c]==0){
            dfs(r,c,board,visit);
        }
    }
  }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,0));
        
        //first row
        for(int j=0;j<m ;j++){
            if(board[0][j]=='O')
              dfs(0,j,board,visit);
        }
        //last row
         for(int j=0;j<m ;j++){
            if(board[n-1][j]=='O')
              dfs(n-1,j,board,visit);
        }
        // first col 
         for(int i=0;i<n ;i++){
            if(board[i][0]=='O')
              dfs(i,0,board,visit);
        }
        // last col 
         for(int i=0;i<n ;i++){
            if(board[i][m-1]=='O')
              dfs(i,m-1,board,visit);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visit[i][j]==0)
                  board[i][j]='X';
            }
        }

    }
};
