class Solution {
public:

//vhi same min heap of size k
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue <int, vector<int>, greater<int>> minheap;
        
        for(int x: nums){
            minheap.push(x);

            while(minheap.size()>k){
                minheap.pop();
            }
        }

        return minheap.top();
    }
};
