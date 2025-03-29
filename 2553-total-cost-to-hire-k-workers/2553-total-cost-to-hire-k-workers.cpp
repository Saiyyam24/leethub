class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int,vector<int>,greater<int>> left_pq,right_pq;
        long long total_sum=0;
        int left=0;
        int right=n-1;
                
            for(int i=0;i<candidates && left<=right;i++,left++)
            {
                left_pq.push(costs[left]);
            }

            for(int i=0;i<candidates && left<=right;i++,right--)
            {
                right_pq.push(costs[right]);
            }
        
        while(k--)
        {
            if(!left_pq.empty() && (right_pq.empty() || (left_pq.top()<=right_pq.top())))
            {
                total_sum+=left_pq.top();
                left_pq.pop();
                if(left<=right)
                {
                    left_pq.push(costs[left++]);
                }
            }
            else
            {
                total_sum+=right_pq.top();
                right_pq.pop();
                if(left<=right)
                {
                    right_pq.push(costs[right--]);
                }
            }
        }
        return total_sum;
    }
};