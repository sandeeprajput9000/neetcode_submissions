class Solution {
public:
  int FindParent(int u,vector<int>&parent){
     if(u==parent[u])
       return u;

     return parent[u]=FindParent(parent[u],parent);
  }
  void FindRanke(int u,int v,vector<int>&parent,vector<int>& rank){
      
      int pu=FindParent(u,parent);
      int pv=FindParent(v,parent);

      if(rank[pu] > rank[pv]){
          parent[pv]=pu;
      }else if(rank[pu] < rank[pv]){
          parent[pv]=pu;
      }else{
           parent[pv]=pu;
           rank[pu]++;
      }
  }
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            int pu = FindParent(u, parent);
            int pv = FindParent(v, parent);

            
            if (pu == pv) {
                return {u, v};
            }

            FindRanke(u, v, parent, rank);
        }

        return {};
  }
};
