class KthLargest {

    //we keep only the k largest elements in minheap - and the soln is the min of the k largest elements - and that is kth largest element

    //add element in min heap. if size > k , then remove smallest elements until size =k

    int c;
    priority_queue<int, vector<int>, greater<int>> pq;

public:

    KthLargest(int k, vector<int>& nums) {

        c=k;
        for (int x : nums) {
            add(x);
        }
    }

    int add(int val) {

        pq.push(val);

        if (pq.size() > c) {
            pq.pop();
        }

        return pq.top();
    }
};