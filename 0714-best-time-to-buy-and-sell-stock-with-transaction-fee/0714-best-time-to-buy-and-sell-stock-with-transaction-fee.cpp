class Solution {
public:
    int dp[50001][2];
    int solve(vector<int>& prices,int fee,int n,int i,bool canbuy)
    {
        if(i==n)
        {
            return 0; 
        }
        int involve=0,ignore=0;
        if(dp[i][canbuy]!=-1)
        {
            return dp[i][canbuy];
        }
        if(canbuy==true)
        {
            involve = -prices[i]+solve(prices,fee,n,i+1,false);
            ignore = solve(prices,fee,n,i+1,true);
        }
        else if(canbuy==false)
        {
            involve = prices[i]+solve(prices,fee,n,i+1,true) - fee;
            ignore = solve(prices,fee,n,i+1,false);
        }
        
        return dp[i][canbuy]=max(involve,ignore);

    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        bool canbuy = true;
        return solve(prices,fee,n,0,canbuy);
    }
};