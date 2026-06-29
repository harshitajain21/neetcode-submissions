class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        //If A is behind B, and A's time is LESS than B's -> it will catch at some point
        //If car A catches car B before the target, they become a fleet and travel together at the slower speed from that point. So they arrive at the target at the same time as if A never caught up.
        //If A is behind B. and A's time is MORE than B -> they will never meet before the target.. only after the target which doesn't matter

        //10, pos=[4,2,1,7,0]...speed = [2,3,1,1,2]
        //reach in 3 hr
        //reach in 2.66 hr
        //reach in 9 hr
        //reach in 3 hr

        //You need to process cars from closest to target → furthest.
        //sort pos: [7,4,2,1,0] -> [3,3,2.66,10,5]

        //4,2,7...0 -> so 2 car fleets
        //store in max stack
        //[3] (count =1)   if stack empty: push
        //[3] (count =1)   if equal : ignore and move on
        //[3] (count =1)    if less: ignore and move on
        //[3,10] (count =2) if more: push
        //[3,10] (count =2) if less:ignore and move on

        int n= position.size();
        double time=0;
        stack <double> st;

        vector<pair<int,int>> cars;
        for(int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<pair<int,int>>());


        for(int i=0;i<n;i++){
            time = double(target - cars[i].first)/cars[i].second;

            if(st.empty()){
                st.push(time);
            }
            else if(time>st.top()){
                st.push(time);
            }
            else{
                continue;
            }
        }
        return st.size();
      
    }
};
