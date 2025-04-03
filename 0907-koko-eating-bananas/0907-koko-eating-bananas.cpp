class Solution {
public:
    int find_max(vector<int>& piles)
    {
        int num = INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            if(num<piles[i])
            {
                num = piles[i];
            }
        }
        return num;
    }
    int total_sum(vector<int>& piles,int k)
    {
        double total = 0;
        for(int i=0;i<piles.size();i++)
        {
            total += ceil(double(piles[i])/k);
        }
        return (int)total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high = find_max(piles);
        while(low<high)
        {
            int mid = (low+high)/2;
            int total_hr = total_sum(piles,mid);
            if(total_hr<=h)
            {
                high = mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};