class Solution {
public:
    vector<string> keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void helper(int i,vector<int>& res,string& current)
    {
        if(i == res.size())
        {
            if(!current.empty())
            {
                ans.push_back(current);
            }
            return;
        }
        string letters = keypad[res[i]];
        for(auto& letter:letters)
        {
            current.push_back(letter);
            helper(i+1,res,current);
            current.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<int> res;
        int n = digits.length();
        string current;
        for(int i=0;i<n;i++)
        {
            res.push_back(digits[i]-'0');
        }
        helper(0,res,current);
        return ans;
    }
};