class Solution {
public:
    int findMin(vector<int> &nums) {
        //let 0th element be smallest
        /*check : _ yes yes yes no no
                  _ yes no no no no
                  _ yes yes yes
                  y y y y y y y n n n*/
                //so i can clearly see monotonicity
        

        //1. check if mid element is biggr than smallest -> if yes, then left = mid+1.. if not, then right=mid-1.. but prblm is if no rotation

        //another method is that we can always take the right element as largest
        //so : n n n n y y

        int left=0;
        int right=nums.size()-1;

        while(left<right)
        {
            int mid=(left+right)/2;

            if(nums[mid]>nums[right]){
                left=mid+1;
            }
            else{
                right=mid;
            }}
        return nums[left];
    }
};
