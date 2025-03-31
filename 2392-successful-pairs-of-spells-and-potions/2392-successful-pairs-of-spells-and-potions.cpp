class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        
        for(int i=0;i<n;i++)
        {
            int index=m;
            int left = 0;
            int right = m-1;
            while(left<=right)
            {
                int mid = (left+right)/2;
                if(((long long)spells[i]*potions[mid]) >= success)
                {
                index = mid;
                right=mid-1;
                }
                else
                {
                left=mid+1;
                }
            }
            result.push_back(m-index);
        }
        return result;
    }
};