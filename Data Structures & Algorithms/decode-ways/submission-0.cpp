
//start from i=0
/*while[i-1]!=0
if s[i]==1 or s[i]=2&s[i+1]<=6: l(n)=l(n-1) + l(n-2)
otherwise l(n)=l(n-1)*/

class Solution {
public:
    int numDecodings(string s) {

        //1. initialize count s.t count[i] = no of ways to decode the first i char
        int n = s.size();
        vector<int> count(n + 1, 0);

        //2. base case
        count[0] = 1;

        //check each 
        for (int i = 1; i <= n; i++) {

            // Case 1: Decode one digit
            if (s[i-1] != '0') {
                count[i] += count[i - 1];
            }

            // Case 2: Decode two digits
            if (i >= 2 &&
                s[i - 2] != '0' &&
                (s[i - 2] == '1' ||
                (s[i - 2] == '2' && s[i - 1] <= '6'))) {

                count[i] +=  count[i - 2];
            }
        }

        return count[n];
    }
};

