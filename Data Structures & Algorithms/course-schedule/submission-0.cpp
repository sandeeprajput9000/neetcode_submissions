class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>AdjList(n);
        for(auto it :prerequisites ){
            AdjList[it[0]].push_back(it[1]);
           // AdjList[it[1]].push_back(it[0]);
        }
        vector<int>indgree(n,0);
        for(int i=0;i<n;i++){
            for(auto it : AdjList[i]){
                indgree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indgree.size();i++){
            if(indgree[i]==0)
              q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;

            for(auto it : AdjList[node]){
                indgree[it]--;
                if(indgree[it]==0)
                 q.push(it);
            }
        }
        return cnt==n ? true : false;
    }
};
