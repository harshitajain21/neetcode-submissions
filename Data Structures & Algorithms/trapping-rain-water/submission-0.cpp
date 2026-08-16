class Solution {
public:
    int trap(vector<int>& height) {
        
        //at any point i -> water volume = min(left max, right max) - height[i] ..(it should be positive, otherwise 0)
        
        //it would be expensive if i search for left max and right max for every i
        // - so mantain leftmax and rightmax

        //let l=0, r=n-1;
// If height[l] <= height[r]:
//     the right boundary is definitely high enough,
//     so process the left side: if height[l]>leftmax, update it
//                               else, add its volume
//
// If height[r] < height[l]:
//     the left boundary is definitely high enough,
//     so process the right side: if height[r]>rightmax, then update it
//                                else add its volume

        int l = 0;
        int r = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while (l <= r) {

            // Process left side
            if (height[l] <= height[r]) {

                if (height[l] >= leftMax) {
                    leftMax = height[l];
                }
                else {
                    water += leftMax - height[l];
                }

                l++;
            }

            // Process right side
            else {

                if (height[r] >= rightMax) {
                    rightMax = height[r];
                }
                else {
                    water += rightMax - height[r];
                }

                r--;
            }
        }

        return water;
    }
};


 