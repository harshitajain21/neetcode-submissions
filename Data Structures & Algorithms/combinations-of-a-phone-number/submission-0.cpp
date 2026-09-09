class Solution {
public:

    vector<string> mp = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(string& digits, int index,
                   string& current, vector<string>& ans) {

        // Complete combination
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mp[digits[index] - '0'];

        // Try every letter for this digit
        for (char c : letters) {

            // CHOOSE
            current.push_back(c);

            // EXPLORE
            backtrack(digits, index + 1, current, ans);

            // UNDO
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if (digits.empty())
            return ans;

        string current;

        backtrack(digits, 0, current, ans);

        return ans;
    }
};

