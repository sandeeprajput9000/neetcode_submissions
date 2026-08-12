class Solution {
public:
   bool validTree(int n, vector<vector<int>>& edges) {
      if (edges.size() != n - 1)
            return false;

        vector<vector<int>> AdjList(n);

        for (auto it : edges) {
            AdjList[it[0]].push_back(it[1]);
            AdjList[it[1]].push_back(it[0]);
        }

        vector<int> visited(n, 0);

        queue<int> q;
        q.push(0);
        visited[0] = 1;

        int cnt = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cnt++;

            for (auto it : AdjList[node]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }

        return cnt == n;
   }

    
};
