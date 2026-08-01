class Solution {
public:
    int search(vector<int>& nums, int target) {

       //nums = [3,5,6,0,1,2]....target=4

       //[3,5,6] and [0,1,2]
       //4<6 so binary search in 1st set

       //1. find the turning point
       int l=0;
       int r = nums.size()-1;

       while(l<r){
        int mid=(l+r)/2;
        if(nums[mid]>nums[r]){
            l=mid+1;
        }
        else{
            r=mid;
        }
       }
       int pivot=r;

       //so pivot is the index pointing to 0 here
       //2. find target belongs to which set
       int left, right;
       if (target >= nums[pivot] && target <= nums.back()){
        left=pivot;
        right = nums.size()-1;
       }
       else{
        left=0;
        right=pivot-1;
       }

       //2. do binary search in that set
       while(left<=right){
        int midx=(left+right)/2;
        if(nums[midx]<target){
            left=midx+1;
        }
        else if(nums[midx]>target){
            right=midx-1;
        }
        else{
            return midx;
        }
       }

       return -1;


    }
};
