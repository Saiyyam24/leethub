class Solution {
public:
    vector<vector<int>> adj;
    void dfs(int node,vector<vector<int>> &connections,vector<bool>& visited,int& count)
    {
        visited[node]=true;
        for(auto& neighbour:adj[node])
        {
            if(visited[abs(neighbour)]!=true)
            {
                if(neighbour>0) count++;
                dfs(abs(neighbour),connections,visited,count);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        for(auto comm:connections)
        {
            adj[comm[0]].push_back(comm[1]);
            adj[comm[1]].push_back(-comm[0]);
        }
        vector<bool> visited(n,false);
        int count=0;
        dfs(0,connections,visited,count);
        return count;
    }
};