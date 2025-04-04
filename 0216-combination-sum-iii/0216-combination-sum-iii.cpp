class Solution {
public:
    void dfs(int k, int n, int start, int sum, vector<int>& val, vector<vector<int>>& result) {
        if (val.size() == k) {
            if (sum == n) {
                result.push_back(val);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (sum + i > n) break;  // Stop if sum exceeds target
            val.push_back(i);
            dfs(k, n, i + 1, sum + i, val, result);
            val.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> val;
        dfs(k, n, 1, 0, val, result);
        return result;
    }
};