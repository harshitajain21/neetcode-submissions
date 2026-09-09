class Solution {
public:

    void backtrack(vector<int>& nums,
                   vector<int>& current,
                   vector<bool>& used,
                   vector<vector<int>>& ans) {

        // We have made a complete permutation
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Try every number
        for (int i = 0; i < nums.size(); i++) {

            // Already used → can't choose it
            if (used[i])
                continue;

            // CHOOSE
            current.push_back(nums[i]);
            used[i] = true;

            // EXPLORE
            backtrack(nums, current, used, ans);

            // UNDO
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, current, used, ans);

        return ans;
    }
};
