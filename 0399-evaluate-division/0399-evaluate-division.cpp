class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>>& adj,string src,string dest,double &ans,double product,unordered_set<string>& visited)
    {
        if(visited.find(src)!=visited.end())
        {
            return;
        }
        visited.insert(src);
        if(src==dest)
        {
            ans=product;
        }
        for(auto& neighbour:adj[src])
        {
            string newsrc = neighbour.first;
            double val = neighbour.second;

            dfs(adj,newsrc,dest,ans,product*val,visited);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<n;i++)
        {
            string x = equations[i][0];
            string y = equations[i][1];
            double val = values[i];

            adj[x].push_back({y,val});
            adj[y].push_back({x,1.0/val});
        }
        vector<double> res;

        for(auto& q:queries)
        {
            string src = q[0];
            string dest = q[1];
            double ans = -1.0;
            double product = 1.0;

            if(adj.find(src)!=adj.end())
            {
                unordered_set<string> visited;
                dfs(adj,src,dest,ans,product,visited);
            }
            res.push_back(ans);
        }
        return res;
    }
};