class Solution {
public:
  void dfs(int node,vector<vector<int>>&AdjList,vector<int>&visit){
      visit[node]=1;
      for(auto it : AdjList[node]){
          if(!visit[it])
            dfs(it,AdjList,visit);
      }
  }
    int countComponents(int n, vector<vector<int>>& edges) {
       
       vector<vector<int>>AdjList(n);
       for(auto it : edges){
           AdjList[it[0]].push_back(it[1]);
           AdjList[it[1]].push_back(it[0]);
       }
       vector<int>visit(n,0);
       int cnt=0;
       for(int i=0;i<n;i++){
            if(!visit[i]){
             dfs(i,AdjList,visit);
             cnt++;
         }
       }
       return cnt;
    }
};
