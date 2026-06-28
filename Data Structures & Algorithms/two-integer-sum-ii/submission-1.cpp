class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //1,2,3,4,5,6.....target is 9
        int left = 0;
        int right = numbers.size() - 1;


        while(left<right){

            int sum=numbers[left]+numbers[right];
            if(sum>target){
                right--;
            }
            else if(sum<target){
                left++;
            }
            else{
                return {left+1, right+1};
            }
        }
        
    }
};
