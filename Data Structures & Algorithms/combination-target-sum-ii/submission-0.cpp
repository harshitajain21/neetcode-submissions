class Solution {
public:

//1,2,2,4,5,6,9
//

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
        backtrack(nums, target-nums[index], index+1, curr); 

        //2. undo and choose to not add
        curr.pop_back();
        // 2. SKIP :Skip all duplicate values 
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {             index++; }
        backtrack(nums, target, index+1,curr);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        vector<int> curr;

        int i=0;

        backtrack(nums, target, i, curr);

        return res;
    }
};
