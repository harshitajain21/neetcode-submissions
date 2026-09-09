
class Solution {
public:

    vector<vector<string>> ans;

    bool isPalindrome(string& s, int l, int r) {

        while (l < r) {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void backtrack(string& s, int index,
                   vector<string>& current) {

        // Finished the entire string
        if (index == s.size()) {
            ans.push_back(current);
            return;
        }

        // Try every possible substring starting at index
        for (int i = index; i < s.size(); i++) {

            // Only choose palindromes
            if (!isPalindrome(s, index, i))
                continue;

            string part = s.substr(index, i - index + 1);

            // CHOOSE
            current.push_back(part);

            // EXPLORE
            backtrack(s, i + 1, current);

            // UNDO
            current.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {

        vector<string> current;

        backtrack(s, 0, current);

        return ans;
    }
};

