class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
     vector<pair<int,int>> arr;
     int n = nums1.size();
     for(int i=0;i<n;i++)
     {
        arr.push_back({nums1[i],nums2[i]});
     }   
        auto mycmp = [&](auto &p1,auto &p2)
        {
            return p1.second>p2.second;
        };
        sort(arr.begin(),arr.end(),mycmp);
        priority_queue<int,vector<int>,greater<int>> pq;
        long long ksum=0;
        for(int i=0;i<=k-1;i++)
        {
            ksum+=arr[i].first;
            pq.push(arr[i].first);
        }
        long long result = ksum*arr[k-1].second;
        for(int i=k;i<n;i++)
        {
            ksum += arr[i].first - pq.top();
            pq.pop();
            pq.push(arr[i].first);
            result = max(result,ksum*arr[i].second);
        }
        return result;
    }
};