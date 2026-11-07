class Solution {
public:

//ex: coins = [1, 2, 5], amount = 5
//initially: dp = [0, INF, INF, INF, INF, INF]
/*We calculate each amount from 1 to 5.
Amount i	Possible last coins	Minimum coins dp[i]
1	        1 → dp[0]+1	                            1
2	        1 → dp[1]+1, 2 → dp[0]+1	            1
3	        1 → dp[2]+1, 2 → dp[1]+1	            2
4	        1 → dp[3]+1, 2 → dp[2]+1	            2
5	        1 → dp[4]+1, 2 → dp[3]+1, 5 → dp[0]+1	1*/

    int coinChange(vector<int>& coins, int amount) {
        
        //1. initialization
        //dp[i]=min no. of coins needed to make i
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        //2. update dp of all until amount 
        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (i >= c && dp[i - c] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
}
        //3. RETURN amount
        if (dp[amount] == INT_MAX) {
            return -1;
        }
        else {
            return dp[amount];
        }    }
};
