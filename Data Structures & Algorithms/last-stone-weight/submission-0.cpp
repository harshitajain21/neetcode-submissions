class Solution {
    public:
        int lastStoneWeight(vector<int>& stones) {

                /*make max heap
                y: pop
                 heapify
                 x: pop
                 now if x and y same: do again using recursion 
                 else if x<y, add y-x and heapify..now repeat using recursion */

                // 1. Make a max heap
                        priority_queue<int> maxHeap;

                                for (int stone : stones) {
                                            maxHeap.push(stone);
                                                    }

                                                            // 2. Keep smashing stones until <= 1 stone remains
                                                                    while (maxHeap.size() > 1) {

                                                                                // y = largest stone
                                                                                            int y = maxHeap.top();
                                                                                                        maxHeap.pop();

                                                                                                                    // x = second largest stone
                                                                                                                                int x = maxHeap.top();
                                                                                                                                            maxHeap.pop();

                                                                                                                                                        // 3. If same → both destroyed
                                                                                                                                                                    if (x == y) {
                                                                                                                                                                                    continue;
                                                                                                                                                                                                }

                                                                                                                                                                                                            // 4. If different → remaining stone = y - x
                                                                                                                                                                                                                        maxHeap.push(y - x);
                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                        // 5. Return remaining stone, or 0
                                                                                                                                                                                                                                                return maxHeap.empty() ? 0 : maxHeap.top();
                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                    };

