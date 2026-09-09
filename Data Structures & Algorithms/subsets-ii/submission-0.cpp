class Solution {
public:

        void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {

        // Base case
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        // CHOOSE: take nums[index]
        current.push_back(nums[index]);
        // EXPLORE
        backtrack(index+1, nums, current, ans);
        
        // UNDO and choose 2nd option: i.e dont take nums[index]
        current.pop_back();
        // 2. SKIP :Skip all duplicate values 
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {             index++; }
        // CHOOSE: don't take nums[index]
        backtrack(index + 1, nums, current, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> current;
        int i=0;
        backtrack(i,nums,current, res);

        return res;
    }
};
