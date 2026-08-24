class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //ok this is really interesting
        /*basically lets make a linked list where (at index i, next element is nums[i]

        so [1,2,5,4,2,2] 
        lets start with i=0
        0 -> 1 -> 2 -> 5 -> 2 -> 5 -> 2
        seeee cycle formed with 2 bcz 2 repeated

        ex:[1,2,3,4,2,2] 
        0->1->2->3->4->2->3->4
        cycle formed again

        ex: [1,2,4,4,4,5]
        0->1->2->4->4->4
        cycle*/

        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];           // 1 step
            fast = nums[nums[fast]];     // 2 steps
        } while (slow != fast);


        // Phase 2: Find the entrance of the cycle
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;

    }
};
