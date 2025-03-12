class Solution {
public:
    int waycost(vector<int>& cost,int n,vector<int>& dp)
    {
        if(n<0)
        return 0;
        if(n==0 || n==1)
        {
            return cost[n];
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n] = min(waycost(cost,n-1,dp),waycost(cost,n-2,dp))+cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
     int n = cost.size();
     vector<int> dp(n,-1);
     return min(waycost(cost,n-1,dp),waycost(cost,n-2,dp));   
    } 
};