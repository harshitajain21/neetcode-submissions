class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sorted: -4,-1,-1,0,1,2
        //-4, we want sum = 4...check [-1,-1 to 2] by 2sum - no
        //-1.. we want sum=1.. check [-1 to 2] by 2sum - 0 and 1  - and -1 and 2
        //0..we want sum = 0 .. check[1,2]

        sort(nums.begin(),nums.end());
        vector <vector<int>> result;
        int n = nums.size();


       for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i-1]) {
                continue;} //skip duplicate starting elements


            int target = 0 - nums[i];

            int left = i+1;
            int right = n - 1;

            while(left<right){

                int sum=nums[left]+nums[right];
                if(sum>target){
                    right--;
                }
                else if(sum<target){
                    left++;
                }
                else{
                    result.push_back({nums[i],nums[left], nums[right]});
                    
                    while (left < right && nums[left] == nums[left+1]) {
                        left++;}
                    while (left < right && nums[right] == nums[right-1]) {
                        right--;}
                    left++;
                    right--;
                }
            }
         }
        return result;

    }};

