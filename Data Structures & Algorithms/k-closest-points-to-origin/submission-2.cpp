class Solution {
public:

//same as kth largest element in stream
//just make a maxheap of size k

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
         // max heap: {distance, point}
        priority_queue<pair<int, vector<int>>> maxheap;

        for(auto point:points){
            int d = point[0]*point[0]+point[1]*point[1];
 
           maxheap.push({d, point});

           while(maxheap.size()>k){
            maxheap.pop();
           }
        }

        vector<vector<int>> result;

        while(!maxheap.empty()){
            result.push_back(maxheap.top().second);
            maxheap.pop();
        }

        return result;

    }
};
