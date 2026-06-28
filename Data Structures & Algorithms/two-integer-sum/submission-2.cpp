class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //i=0: check if u hv seen 7-3 before?
        //i=1: check if u hv seen 7-4 before?.. if yes, then return [index of seen,i]
        //so u hv to make hashmap where num -> index
        unordered_map <int, int> index;

        for(int i =0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(index.count(diff)){
                return {index[diff],i};
            }
            index[nums[i]]=i;
        }
    }
};
