class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*prices = [10,1,5,6,7,1]
        1 and 7   
        note - we can't go back 
        
        prices = [10,2,5,9,6,7,1]
        2 and 9

        prices = [10,1,5,9,6,7,2,10]
        1 and 10

        prices = [10,9,5,4,6,2]
        4 and 6

        prices = [1,5,9,6,7,1]
        1 and 9
        
        prices = [10,9,5,4,6,2,11]
        2 and 11

        so basically min from left side and max from right side
        1st take window of whole array..

        ok no i saw the soln.. first of all, it's 2 pointer not sliding window
        now see, mantain a minimum variable (keep updating it), now for each     number, find if its max distance (keep updating max distance) */

        int min=prices[0];
        int max_profit=0;
        int profit=0;

        for(int x: prices){
            if(x<min){
                min=x;
            }
            else{
                profit=x-min;
                if(profit>max_profit){
                    max_profit=profit;
                }
            }
        }

        return max_profit;
    }
};
