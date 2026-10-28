class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        //let c[i] = min cost to reach step above i

        //c[i] = min( (c[i-1]+cost[i-1]), (c[i-2]+cost[i-2]))

        //start: c[0] = 0, c[1] = 0... bcz both can be reached at start

        int n =cost.size();
        vector<int> c(n+1);

        c[0]=0;
        c[1]=0;

        for(int i=2;i<=n;i++){
            c[i]=min(c[i-1] + cost[i-1], c[i-2] + cost[i-2]);
        }
        
        return c[n];
    }
};
