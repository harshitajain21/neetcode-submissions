class Solution {
public:

vector<vector<int>> res;

    void backtrack(vector<int>& nums, int target, int index, vector<int>&curr){

        if(target==0){
            res.push_back(curr);
            return;
        }

        if (index == nums.size() || target < 0) {
            return;}

        //1.choose to add
        curr.push_back(nums[index]);
        backtrack(nums, target-nums[index], index, curr); //index not changed bcz duplicates can be there

        //2. undo and choose to not add
        curr.pop_back();
        backtrack(nums, target, index+1,curr);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<int> curr;

        int i=0;

        backtrack(nums, target, i, curr);

        return res;
    }
};
