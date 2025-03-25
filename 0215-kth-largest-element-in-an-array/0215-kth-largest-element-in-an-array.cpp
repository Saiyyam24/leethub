class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int i=0;i<nums.size();i++)
        {
            q.push(nums[i]);
        }
        int val = 0;
        while(!q.empty() && k!=0)
        {
            val=q.top();
            q.pop();
            k--;
        }
        return val;
    }
};