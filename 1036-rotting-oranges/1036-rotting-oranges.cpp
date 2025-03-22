class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
        return 0;
    int dir_row[] = {1,-1,0,0};
    int dir_col[] = {0,0,1,-1}; 
    int m = grid.size();
    int n = grid[0].size();
    int time = 0;
    queue<pair<int,int>> q;
    int fresh_count=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==2)
            {
                q.push(make_pair(i,j));
            }
            else if(grid[i][j]==1)
            {
                fresh_count++;
            }
        }
    }
    while(!q.empty())
    {
        int quantity = q.size();
        bool spread = false;
        for(int i=0;i<quantity;i++)
        {
            pair<int,int> temp = q.front();
            int x = temp.first;
            int y = temp.second;
            q.pop();
            for(int j=0;j<4;j++)
            {
                int new_r = x + dir_row[j];
                int new_c = y + dir_col[j];
                if(new_r>=0 && new_r<m && new_c>=0 && new_c<n && grid[new_r][new_c]==1)
                {
                    q.push({new_r,new_c});
                    spread = true;
                    fresh_count--;
                    grid[new_r][new_c] = 2;
                }
            }
        }
        if(spread)
        time++;
    }
    if(fresh_count!=0)
    {
        return -1;
    }
    return time;
    }
};